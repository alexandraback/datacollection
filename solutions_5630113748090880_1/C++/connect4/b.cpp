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

cout << tests << endl;



for(int h=0; h<tests; h++)
{
	vector<int> heights(2501, 0);

	int N, temp;
	In >> N;

	for(int i=0; i<2*N-1; i++)
		for(int j=0; j<N; j++)
		{
			In >> temp;
			heights[temp]++;
		}

	Out << "Case #" << h+1 << ": ";
	for(int i=0; i<2501; i++)
		if(heights[i]%2)
			Out << i << " ";
	Out << endl;


}

In.close();

Out.close();

return 0;

}
 
