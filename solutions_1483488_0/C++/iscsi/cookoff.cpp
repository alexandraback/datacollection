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
#define HOME

vector<int> digits(int a)
{
	vector<int> res;
	while(a)
	{
		res.push_back(a%10);
		a/=10;
	}
	reverse(res.begin(),res.end());
	return res;
}

int calc(const vector<int>& a)
{
	int res=0;
	REP(i,a.size())
	{
		res*=10;
		res+=a[i];
	}
	return res;
}

int main()
{
#ifdef HOME
	clock_t start=clock();
	freopen ("C-small-attempt0.in","r",stdin);
	freopen ("C-small-attempt0.out","w",stdout);
	freopen ("out_err.txt","w",stderr);
#endif
	const int mm=2*1e6+2;
	vector<vector<int> > v(mm);
	REP(i,mm)
	{
		vector<int> d=digits(i);
		vector<int> tmp(d.size());
		REP(j,d.size())
		{
			tmp.clear();
			FOR(k,j,d.size())
				tmp.push_back(d[k]);
			REP(k,j)
				tmp.push_back(d[k]);
			int tmpv=calc(tmp);
			if(tmpv>i)
			{
				bool ok=true;
				REP(j,v[i].size())
					if(v[i][j]==tmpv)
						ok=false;
				if(ok)
					v[i].push_back(tmpv);
			}
		}
	}
	int T,A,B;
	cin >> T;
	FOR(testcase,1,T+1)
	{
		int res=0;
		cin >> A >> B ;
		FOR(i,A,B)
		{
			REP(j,v[i].size())
			{
				if(v[i][j]<=B)
				{
					++res;
				}
			}
		}
		cout << "Case #" << testcase << ": " << res << endl;
	}
	v.clear();
#ifdef HOME
	fprintf(stderr,"time=%.3lfsec\n",0.001*(clock()-start));
#endif
	return 0;
} 