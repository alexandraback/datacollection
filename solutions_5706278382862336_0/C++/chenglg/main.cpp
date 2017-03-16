#ifdef __GNUC__
#include <ext/hash_map>
#include <ext/hash_set>
#else
#include <hash_map>
#include <hash_set>
#endif

namespace std
{
 using namespace __gnu_cxx;
}

#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <set>
#include <map>
#include <stack>
#include <list>
#include <queue>
#include <algorithm>
#include <math.h>
#include <cstdlib>
#include <climits>
#include <iomanip> 
using namespace std;

typedef long long LL;
typedef long double LD;

string its(int n)
{
	string ret;
	if(n == 0)
	{
		ret = "0";
		return ret;
	}
	while(n > 0)
	{
		ret += (n % 10 + '0');
		n /= 10;
	}
	reverse(ret.begin() , ret.end());
	return ret;
}

int checkLast(LL src)
{
	int ret = -1;
	int t = src & (- src);
	while( t > 0)
	{
		t = t >> 1;
		ret ++;
	}
	return ret;
}

int checkFirst(LL src)
{
	int ret = -1;
	while (src > 0)
	{
		src = src >> 1;
		ret ++;
	}
	return ret;
}

LL prime(LL a , LL b)
{
	if ( a > b)
		return (prime(b , a));
	if(a == 0)
		return b;
	return prime(a , b-a);
}

int main()
{
//==============in put=================
	ifstream curFile("A-small-attempt0.in");
	vector<string> result;
	int T; // testcases count
	string input;
	string ret;
	if(curFile.is_open())
	{
		curFile >> T;
		for(int c = 0 ; c < T ; c++)
		{
//==============solution==================
			curFile >> input;
			int pos = input.find("\/");
			LL P = atoi (input.substr(0, pos).data() );
			LL Q = atoi (input.substr(pos + 1).data());
			LL x = prime(P , Q);
			P /= x;
			Q /= x;
			int q = checkLast(Q);
			int p = checkFirst(P);
			LL t = 1;
			if(Q!= t << q)	
				ret = "impossible";
			else
			{
				ret = its(q - p);
			}
			result.push_back(ret);
//==============solution end==============
		}	
	}
	curFile.close();
//==============out put==================
	ofstream outfile;
	outfile.open("result.txt");
	if(outfile.is_open())
	{
//		outFile << setprecision(6);
		for(int i = 0; i < result.size() ; i++)
			outfile << "Case #" << i + 1<< ": " <<result[i] << endl;
	}
	outfile.close();
	return 0;
}
