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
	freopen ("B-small-attempt0.in","r",stdin);
	freopen ("B-small-attempt0.out","w",stdout);
	freopen ("out_err.txt","w",stderr);
#endif
	int T,N,S,P;
	vector<int> v;
	cin >> T;
	FOR(testcase,1,T+1)
	{
		cin >> N >> S >> P ;
		int res1=0,res2=0;
		int t1=max(P-1,0)+max(P-1,0)+P;
		int t2=max(P-2,0)+max(P-2,0)+P;
		v.clear();
		v.resize(N);
		REP(i,N)
		{
			cin >> v[i];
			if(v[i]>=t1)
				++res1;
			else if(v[i]>=t2)
				++res2;
		}
		cout << "Case #" << testcase << ": " << res1+min(res2, S)<< endl;
	}
	v.clear();
#ifdef HOME
	fprintf(stderr,"time=%.3lfsec\n",0.001*(clock()-start));
#endif
	return 0;
} 