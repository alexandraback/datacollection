#include<iostream>
#include<fstream>
#include <cstdio>
#include <cmath>
#include <climits>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <map>

using namespace std;

int main() {
	bool outputToFile = false;
	string inputFile = "fashionPolice.in";
	string outputFile = "fashionPolice.out";

	/* Merging input/output streams with filestreams */
	streambuf *coutbuff;
	ofstream out;
	streambuf *cinbuff;
	ifstream in;

	if(outputToFile)
	{
		out.open(outputFile);
		coutbuff = out.rdbuf();

		in.open(inputFile);
		cinbuff = in.rdbuf();
	}
	else
	{
		coutbuff = cout.rdbuf();
		cinbuff = cin.rdbuf();
	}
	
	ostream fout(coutbuff);
	istream fin(cinbuff);

	/* Merging ends */

    long long int testCases;
	fin >> testCases;

	long long int tc = 0;
    while (++tc <= testCases)
    {
		fout << "Case #" << tc << ": ";
		
		int s, p, j, k;
		fin >> j >> p >> s >> k;
		
		int result = j * p * min(s, k);
		fout << result << endl;

		for (int a = 0; a < j; a++)
		{
			int jVal = (a*k) % s;

			for (int b = 0; b < p; b++)
			{
				for (int c = 0; c < min(s, k); c++)
				{
					fout << a + 1 << " " << b + 1 << " " << jVal + 1 << endl;
					jVal = (jVal + 1) % s;
				}
			}
		}
    }

	if(outputToFile)
	{
		out.close();
		in.close();
	}
    
    return 0;
}
