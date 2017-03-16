#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cassert>

using namespace std;
typedef unsigned long long LL;
#define FOR(k,a,b) for(LL k(a); k < (b); ++k)
#define FORD(k,a,b) for(int k(b-1); k >= (a); --k)
#define REP(k,a) for(int k=0; k < (a); ++k)
#define ABS(a) ((a)>0?(a):-(a))


int main()
{
#ifdef HOME
	clock_t start=clock();
	freopen ("A-small-attempt0.in","r",stdin);
	freopen ("A-small-attempt0.out","w",stdout);
#endif
	char m[30]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
	string in,out;
	int T;
	out.reserve(110);
	scanf("%d",&T);
	getline(cin,in);
	FOR(testcase,1,T+1)
	{
		out.clear();
		getline(cin,in);
		REP(i,in.length())
		{
			if(in[i]!=' ')
				out+=m[in[i]-'a'];
			else
				out+=' ';
		}
		cout << "Case #" << testcase << ": " << out << endl;
	}
#ifdef HOME
	fprintf(stderr,"time=%.3lfsec\n",0.001*(clock()-start));
#endif
	return 0;
} 