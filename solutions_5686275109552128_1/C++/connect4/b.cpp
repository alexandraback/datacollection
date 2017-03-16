#include <string.h>       
#include <vector>       
#include <set>       
#include <map>       
#include <algorithm>       
#include <math.h>       
#include <sstream>       
#include <ctype.h>       
#include <queue>       
#include <stack>       
#include <iostream> 
#include <gmp.h>	// if GMP is not allowed, I apologize
#include <fstream>
using namespace std;

int main(int argc, char** argv)
{

string fName = argv[1];

fstream In((fName+".in").c_str(), ios::in);
fstream Out((fName + ".out").c_str(), ios::out);

int tests;

In >> tests;



for(int h=0; h<tests; h++)
{

	// I could do binary search, but there's at most 1000 pancakes / plate so go quick and dirty

	int D;
	In >> D;
	vector<int> P(D, 0);
	for(int i=0; i<D; i++)
		In >> P[i];

	int ret = 10000;

	for(int maxPancakes = 1; maxPancakes<=1000; maxPancakes++)
	{
		int time = maxPancakes;

		for(int i=0; i<D; i++)
			if(P[i] > maxPancakes)
				time += (P[i]-1)/maxPancakes;
		ret = min(ret, time);
	}
	
	Out << "Case #" << h+1 << ": " << ret << endl;

}

In.close();

Out.close();

return 0;

}
 
