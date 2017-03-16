#include <stdio.h> 

#include <iostream> 

#include <stdio.h> 

#include <string> 

#include <fstream> 

using namespace std; 

int main() 
{
	ifstream fin ("C:/Code/dance6.in",ios::in);
	ofstream fout("C:/Code/test.txt"); 
	int T,N,S,p,t;

	int mod;
	int middle;
	int total = 0;
	int stotal = 0;
	fin >> T;
	for ( int i = 1 ; i <= T ; i++)
	{
		total = 0;
		stotal = 0;
		fin >> N;
		fin >> S;
		fin >> p;
		for (int j = 0 ; j < N; j++)
		{
			int np = 0;
			fin >> t;
			
			if ( t == 0)
			{
				if (p != 0) continue;
			}			
			
			mod = t % 3;
			middle = t / 3;
			if ( mod == 0)
			{
				np = middle;
				if (np >= p)
					total ++;
				else if (np == p - 1)
					stotal ++;
			}
			else if (mod == 1)
			{
				np = middle + 1;
				if (np >= p)
					total ++;
			}
			else
			{
				np = middle + 1;
				if (np >= p)
					total ++;
				else if (np  == p - 1)
					stotal ++;
			}


		}
		if(S != 0) 
		{
			if (stotal <= S)
				total += stotal;
			else
			{
				total += S;
			}
		}

		fout <<"Case #"<<i<<": "<<total<<endl;

		

	}
	return 0;
}