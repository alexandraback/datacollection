#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iterator>
#include <assert.h>
#include <math.h>
using namespace std;

const string file = "file";

const string infile = file + ".in";
const string outfile = file + ".out";

const int INF = 0x3f3f3f3f; 
const int MODN = 666013;
const double EPS = 0.0000001;

//#define ONLINE_JUDGE




long long cmmdc(long long a, long long b)
{
	while(b)
	{
		long long d = b;
		b = a % b;
		a = d;
		
	}
	return a;
}


int main()
{
#ifdef ONLINE_JUDGE
	ostream &fout = cout;
	istream &fin = cin;
#else
	fstream fin(infile.c_str(), ios::in | ios::binary);
	fstream fout(outfile.c_str(), ios::out);
#endif	
	
	int T;
	fin >> T;
	for(int t = 1; t <= T; t++)
	{
		char c;
		long long  p;
		long long q;
		fin >> p >> c >> q;
		
		long long Sol = 0;

		long long d = cmmdc(p, q);
		p /= d;
		q /= d;


		if(q - (q & (q ^ (q - 1))) != 0)
		{
			fout << "Case #" << t << ": ";
			fout << "impossible\n";
			continue;
		}

		
		if(p == 1 && q == 2)
		{
			fout << "Case #" << t << ": ";
			fout << "1\n";
			continue;
		}


		long long b = 2;
		long long power = 1;
		

		for(; b <= q; power++, b *= 2)
		{
			long long v = q / b;
			if(v <= p)
				break;
		}

		Sol = power;

		fout << "Case #" << t << ": ";
		fout << Sol;
		fout << "\n";
	}


#ifdef ONLINE_JUDGE
#else
    fout.close();
	fin.close();
#endif
}
