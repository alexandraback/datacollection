#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>
#include <bitset>
#include <set>
using namespace std;


int main()
{


	FILE *fp1 = fopen ("A-small-attempt3.in", "r");	
	FILE *fp2 = fopen ("Safety_output.txt", "w");

	int T, N, X;

	fscanf (fp1, "%d\n", &T);
	for (int i = 0; i < T; ++i)
	{
		fscanf (fp1, "%d", &N);				
		vector<int> js(N);
		vector<double> results(N);
		X = 0;
		for (int j =0; j < N; ++j)
		{
			fscanf (fp1, "%d", &js[j]);
			X += js[j];
		}

		double avg = 2.0 * X / (double)N;
		double cnt = 0, x = 0;
		for (int j =0; j < N; ++j)
		{
			if (js[j] < avg)
			{
				cnt++;
				x += js[j];
			}
		}
		double new_avg = (x + X) / cnt;

		//double Z = 0;	//for normalize
		for (int j =0; j < N; ++j)
		{
			if (js[j] > avg)
				results[j] = 0;
			else
				results[j] = (new_avg - js[j]) / (double)X;

			//Z += results[j];
		}

		

		//print out
		fprintf (fp2, "Case #%d: ", i + 1);
		for (int j =0; j < N; ++j)
		{
			fprintf (fp2, "%6lf ", (results[j]) * 100);
		}
		fprintf (fp2, "\n");

	}

	return 0;

}