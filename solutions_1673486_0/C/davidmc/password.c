#include <stdio.h>

#define NUM_CHARS 100000
//double p_char[NUM_CHARS];
//double p_upto[NUM_CHARS];
//double ec_correct [NUM_CHARS];

void do_case(FILE* fin, FILE* fout, int case_no)
{
	int i, nc_in, nc_tot;
	double best_ec;
	double c_fin, c_retype;
	double p_char, p_upto, c_to_correct, ec_correct;
	//Read input
	fscanf(fin, "%i %i", &nc_in, &nc_tot);
	c_fin = (double)(nc_tot-nc_in+1);
	c_retype = (double)(nc_tot+1);
	
	//Assume best expected cost from abandon and retype, then see if 
	// correct improves this 
	best_ec = c_retype + 1;

	// We assume that it is never better to erase the whole string and retype
	// from start, since this costs nc_in + nc_tot +1, while abadon and retype
	// costs nc_tot+2, and nc_in >= 1.
	p_upto = 1.0;
	for(i=0; i<nc_in; i++)
	{
		fscanf(fin, "%lf", &p_char);
		
		p_upto = p_char * p_upto;
		c_to_correct = (double)(2*(nc_in-i-1))+c_fin;
		ec_correct = c_to_correct + (1-p_upto)*c_retype;
		if(ec_correct < best_ec)
			best_ec = ec_correct;
	}
	
	fprintf(fout, "Case #%i: %.6f\n", case_no, best_ec);
	return;
}

int main (void)
{
	FILE * fin;
	FILE * fout;
	int no_cases, i;
	
	fin = fopen("input.txt", "r");
	fout = fopen("output.txt", "w");
	
	fscanf(fin, "%i", &no_cases);
	for(i=1; i<=no_cases; i++)
	{
		do_case(fin, fout, i);
	}	
	
	fclose(fin);
	fclose(fout);
	return 0;
}

