#include <stdio.h>

//#include "tic_tac_toe_tomek.h"
//#include "lawnmower.h"
#include "fair_and_square.h"

int main() {
	//if (!solve_tic_tac_toe_tomek("tic.in", "tic.out")) printf("Cannot solve tic_tac_toe_tomek\n");
	//if (!solve_lawnmower("lawn.in", "lawn.out")) printf("Cannot solve lawnmower\n");
	if (!solve_fair_and_square("fair.in", "fair.out")) printf("Cannot solve fair_and_square\n");
}
