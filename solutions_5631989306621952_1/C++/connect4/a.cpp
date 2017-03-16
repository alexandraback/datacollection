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

string doit(string s)
{
	if(s=="") return "";
	char bestChar = s[s.size()-1];
	int index = s.size()-1;
	for(int i=s.size()-2; i>-1; i--)
		if(bestChar < s[i])
		{
			bestChar = s[i];
			index = i;
		}

	return bestChar + doit(s.substr(0, index)) + s.substr(index+1);

}


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
	string S;
	In >> S;

	Out << "Case #" << h+1 << ": " << doit(S) << endl;

}

In.close();

Out.close();

return 0;

}
 
