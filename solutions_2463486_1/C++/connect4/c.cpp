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

int palindrome(string s)
{
	for(int i=0; i*2 < s.size(); i++)
		if(s[i]!=s[s.size()-1-i])
			return false;
	return true;
}

// preprocess run before-hand to generate all numbers
// pasted into array after
// yes, this won't work for 2nd large, but I'll think on that
void preprocess()
{
	fstream Out("list.txt", ios::out);
	for(long long i=0; i*i <= 1e14; i++)
	{
		stringstream s1;
		s1 << i << " " << i*i << endl;
		string s, t;
			s1 >> s >> t;
	
		if(palindrome(s) && palindrome(t) )
			Out << s << ",";
	}
	Out.close();
}

const int numCount = 40;
long long numList[numCount] = {0,1,2,3,11,22,101,111,121,202,212,1001,1111,2002,10001,10101,10201,11011,11111,11211,20002,20102,100001,101101,110011,111111,200002,1000001,1001001,1002001,1010101,1011101,1012101,1100011,1101011,1102011,1110111,1111111,2000002,2001002};



int main(int argc, char** argv)
{


string fName = argv[1];
fstream In((fName+".in").c_str(), ios::in);
fstream Out((fName + ".out").c_str(), ios::out);

int tests;

In >> tests;

int N, M;

for(int h=0; h<tests; h++)
{
	long long A, B;
	In >> A >> B;
	int ret = 0;
	for(int i=0; i<numCount; i++)
		if(numList[i]*numList[i] >= A && numList[i]*numList[i] <= B)
		{	ret++;
			
		}

	Out << "Case #" << h+1 << ": " << ret << endl;

}

In.close();

Out.close();

return 0;

}
 
