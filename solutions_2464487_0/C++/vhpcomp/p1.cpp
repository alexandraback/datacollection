#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <iostream>
#include <cstdlib>

using namespace std;


int main()
{

	int T;


    ifstream fin("C:\\Compete\\CodeJam1A\\CodeJam1A\\A-small-attempt0.in");

//    ifstream fin("C:\\Compete\\CodeJam1A\\CodeJam1A\\Text.txt");

    ofstream fout("C:\\Compete\\CodeJam1A\\CodeJam1A\\output.txt");

	fin >> T;
   
	for (int i=0; i < T; i++)
	{
		long long  r, t;

		fin >> r >> t;


		long long c = 0;
		long long total = 0 ;

		long long inc = 0;
		while (total <= t)
		{
			total += 2 * r + 1 + 2 * inc;
			c ++;
			inc += 2;
		}

		fout << "Case #" << i+1 <<  ": " << c-1 << endl;
		
	}
	return 0;
} 