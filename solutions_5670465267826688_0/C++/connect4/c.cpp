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

int table[5][5] = { {0,0,0,0,0}, {0, 1, 2, 3, 4}, {0, 2, -1, 4, -3}, {0, 3, -4, -1, 2}, {0, 4, 3, -2, -1} };

int multiply(int a, int b)
{
	int sa = abs(a)/a, sb = abs(b)/b;

	return table[abs(a)][abs(b)] * sa * sb;
}


int main(int argc, char** argv)
{


string fName = argv[1];
fstream In((fName+".in").c_str(), ios::in);
fstream Out((fName + ".out").c_str(), ios::out);

int tests;

In >> tests;


for(int h=0; h<tests; h++)
{
	int L, X;
	string s;

	In >> L >> X >> s;

	vector<int> prod(L*X, 0);

	int cur = 1;
	for(int i=0; i<L*X; i++)
	{
		int temp = s[i%s.size()]-'g';

		int t2 = multiply(cur, temp);
		prod[i] = t2;
		cur = t2;
	}

	int flag = true;
	int index = 0;
	for(; index < prod.size(); index++)
		if(prod[index]==2) break;
	
	if(index==prod.size() )
		flag = false;

	for(; index < prod.size(); index++)
		if(prod[index]==4)
			break;

	if(index==prod.size() )
		flag = false;

	if(prod[prod.size()-1]!=-1)
		flag = false;

	Out << "Case #" << h+1 << ": " << (flag ? "YES" : "NO") << endl;
}

In.close();

Out.close();

return 0;

}
 
