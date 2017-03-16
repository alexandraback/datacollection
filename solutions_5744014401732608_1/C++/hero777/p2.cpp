#include<iostream>
#include<cstdio>
#include<string>
#include<fstream>
#include <algorithm>


using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

int main ()
{
	ifstream input;
	ofstream output;
	input.open("in.txt");
	output.open("out.txt");
	int test,tests;
	input >> tests;
	//printf("%d", tests);
	for (int test = 0; test < tests; test++)
	{	
		output << "Case #"<< test+1 << ": " ;
		int B;
		input >>  B;
		long long int M;
		input >> M;
		int i = 0;
		int j = 0;
		int matrix[B][B];
		forn(k, B)
			forn(l, B)
				matrix[k][l] = 0;
		long long int maxi = 1;
		forn (i, B-2)
			maxi = maxi*2;
		if (maxi >= M)
		 	output << "POSSIBLE\n";
		else
			output << "IMPOSSIBLE\n";
		if (maxi >=M)
		{
			forn(k, B)
				for(int l = k+1; l < B; l++)
					matrix[k][l] = 1;
			long long int diff = maxi - M;
			int curr = 1;
			while (diff > 0)
			{
				if(diff %2 == 1)
					matrix[curr][B-1] = 0;
				diff = diff/2;
				curr++;
			}
			forn(k, B)
			{
				forn(l, B)
					output << matrix[k][l];
				output << "\n";
			}
		}
			
			
			
		
		
		
	}
}	



