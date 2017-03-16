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


    ifstream fin("C:\\Compete\\CodeJam1A\\CodeJam1A\\A-large.in");

    //ifstream fin("C:\\Compete\\CodeJam1A\\CodeJam1A\\Text.txt");

    ofstream fout("C:\\Compete\\CodeJam1A\\CodeJam1A\\output.txt");

	fin >> T;
   
	for (int i=0; i < T; i++)
	{
		long long  r, t;

		fin >> r >> t;


		long long c = 0;
		long long total = 0 ;

	    long long low = 0; long long high = 1000000000;
		long long rh = 2000000000000000000 / r;
		high = std::min(high, rh);
		
		
		long long mi = 0;
		while (low <= high)
		{
		   mi = (high + low ) / 2;
		   total = 2 * r * mi + mi + 2 * mi * (mi-1);
		   if (total == t)
		   {
			   fout << "Case #" << i+1 <<  ": " << mi << endl;
			   goto n1;
		   } else if (total > t)
			   high = mi-1;
		   else 
			   low = mi +1;
		}

		if (total <= t)
		  	fout << "Case #" << i+1 <<  ": " << mi  << endl;
		else 
		   fout << "Case #" << i+1 <<  ": " << mi - 1 << endl;
n1:		continue;
	}
	return 0;
} 