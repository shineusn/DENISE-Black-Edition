/*------------------------------------------------------------------------
 * Module for extraction of Preconditioned Conjugate Gradient Method (PCG)
 * for the material parameters vp, rho and lambda, rho respectively
 * 
 * Daniel Koehn
 * Kiel, 12.06.2017
 * ----------------------------------------------------------------------*/

#include "fd.h"

void extract_PCG_AC(float * PCG_old, float ** waveconv, float ** waveconv_rho){

	extern int NX, NY, IDX, IDY;
	int i, j, h;
	
	/* ============================================================================================================================================================== */
	/* ===================================================== GRADIENT VP/ZP/lambda ================================================================================== */
	/* ============================================================================================================================================================== */

        h=1;
	/* store gradient */
	for (i=1;i<=NX;i=i+IDX){
	   for (j=1;j<=NY;j=j+IDY){

		 waveconv[j][i] = PCG_old[h];

                 h++;
	   }
	}

	/* ============================================================================================================================================================== */
	/* ===================================================== GRADIENT rho =========================================================================================== */
	/* ============================================================================================================================================================== */

	/* store gradient */
	for (i=1;i<=NX;i=i+IDX){
	   for (j=1;j<=NY;j=j+IDY){

		 waveconv_rho[j][i] = PCG_old[h];

                 h++;
	   }
	}


}
