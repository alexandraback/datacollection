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

	int Smax;
	string s;
	In >> Smax >> s;
	int ret = 0;
	int curStanding = 0;
	for(int i=0; i<s.size(); i++)
	{
		if(curStanding < i)
		{	ret += (i-curStanding);
			curStanding = i;
		}
		curStanding += (s[i]-'0');
	}
		

	Out << "Case #" << h+1 << ": " << ret << endl;

}

In.close();

Out.close();

return 0;

}
 
