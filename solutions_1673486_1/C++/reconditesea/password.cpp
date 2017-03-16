#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>
#include <bitset>
using namespace std;


int main()
{


	FILE *fp1 = fopen ("A-large.in", "r");	
	FILE *fp2 = fopen ("password_output2.txt", "w");

	int T, A, B;
	double P;
	double p[100000];
	fscanf (fp1, "%d\n", &T);


	for (int i = 0; i < T; ++i)
	{

		fscanf (fp1, "%d %d\n", &A, &B);
		for (int j = 0; j < A; ++j){
			fscanf (fp1, "%lf", &p[j]);
		}

		double result = B + 2;	//give up

		for (int j = 0; j <= A; ++j){
			P = 1;
			for (int k = 0; k <= A - j - 1; ++k)
				P *= p[k];

			double temp = P * (j + B - A + j + 1) + (1 - P) * (j + B - A + j + 1 + B + 1);
			result = min (result, temp);
		}

		//print out
		fprintf (fp2, "Case #%d: %lf\n", i + 1, result);
	}

	return 0;

}