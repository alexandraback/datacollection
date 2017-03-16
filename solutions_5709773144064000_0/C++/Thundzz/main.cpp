#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>

#define SQUARESIZE 4
#define BADMAGICIAN 0
#define VOLUNTEERCHEATED -1


void parse_number_of_tests(FILE * file, int * number)
{
	fscanf(file, "%d", number);
}



double time_cost(double F, double X, double C, int nbFactories)
{
	if(nbFactories == 0)
	{
		return X/2;
	}
	else
	{
		return time_cost(F, C, C, nbFactories - 1)+ X/(2+ nbFactories*F);
	}
}



void solve_one_test(FILE * inputFile)
{
	double C, F, X, i = 1;
	fscanf(inputFile, "%lf %lf %lf\n", &C, &F, &X);
	double neededTime =time_cost( F, X, C, 0), next=0.0;

	while (neededTime > (next = time_cost(F, X, C, i++)))
	{
		neededTime = next;
	}
	std::cout << neededTime  << std::endl;
}

void solve_input_file()
{
	int numberOfTests;
	FILE * inputFile= fopen ("input.in", "r");
	parse_number_of_tests(inputFile, &numberOfTests);

	for(int i =0; i< numberOfTests; i++)
	{
		std::cout << "Case #" << i+1 << ": ";
		solve_one_test(inputFile);
	}
}

int main(int argc, char * argv[])
{
	std::cout << std::fixed << std::setprecision(7);
	solve_input_file();
	return EXIT_SUCCESS;
}