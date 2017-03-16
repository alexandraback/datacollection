#include <fstream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int T, A, n, v[1000], i, j, aux_T = 1;

int f1()
{
	int i, aux_A = A, nr = 0;
	
	for(i=1; i<=n; i++)
		{
			if(v[i] < aux_A)
				aux_A += v[i];
			else if(v[i] >= aux_A)
				if(v[i]-aux_A != 0)
				{
					if(aux_A+(aux_A-1) > v[i])
					{
						aux_A += aux_A-1;
						nr++;
						i--;
					}
					else
						nr++;
				}
				else if(aux_A != 1)
				{
					aux_A += aux_A-1;
					nr++;
					i--;
				}	
				else
					nr++;
		}
	
	return nr;
}

int f2()
{
	int i, aux_A = A, nr = 0;
	
	for(i=1; i<=n; i++)
		{
			if(v[i] < aux_A)
				aux_A += v[i];
			else if(v[i] >= aux_A && aux_A > 1)
				{
					aux_A += aux_A-1;
					nr++;
					i--;
				}
				else if(aux_A == 1)
					nr++;
		}
	
	return nr;
}

int main()
{
	ifstream fin("file.in");
	ofstream fout("file.out");
	
	//Read
	fin>>T;

	while(aux_T != T+1)
	{
		//Read
		fin>>A>>n;
		for(i=1; i<=n; i++)
			fin>>v[i];
			
		//Compute
		sort(v+1, v+n+1);
	
		//Print	
		fout<<"Case #"<<aux_T<<": "<<min(f1(), f2())<<'\n';	
		
		aux_T++;
	}
}