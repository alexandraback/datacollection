#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <queue>
#include <sstream>
#include <numeric>
#include <functional>
#include <set>
#include <cmath>
#include <stack>
#include <fstream>
#include <cassert>
#ifdef HOME_PC
#include <ctime>
#endif
using namespace std;

#pragma comment(linker,"/stack:16000000")
#pragma warning (disable : 4996)

#define ALL(v) v.begin(),v.end()
#define SZ(v) ((int)(v.size()))
#define mset(A,x) memset((A),(x),sizeof(A))
#define FOR(i,start,N) for(int i=(start);i<(N);++i)
#define FORSZ(i,start,v) FOR(i,start,SZ(v))
#define REPSZ(i,v) FORSZ(i,0,v)
#define FORE(i,start,N) FOR(i,start,N+1)
#define make_unique(v) v.resize(unique(ALL(v))-v.begin())
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define adebug(A,N) FOR(i,0,N) cout<<#A<<"["<<i<<"] = "<<A[i]<<endl;
#define adebug2d(a,n,m) FOR(i,0,n) { FOR(j,0,m) { cout<<a[i][j]<<" ";} cout<<endl;}
#define vdebug(v) REPSZ(i,v) cout<<#v<<"["<<i<<"] = "<<v[i]<<endl;
#define selfx(x,f,a) x = f(x,a)
#define sqr(x) ((x)*(x))


typedef pair<int,int> pii;
typedef long long i64;
typedef vector<int> VI; typedef vector< vector<int> > VVI;
typedef vector<string> VS;

const int inf = 1<<25;
const double eps = 1e-9;

inline int bit(int x,int i) { return (x>>i)&1;}

void solve(const VI& a, const int testCase)
{
	printf("Case #%d:\n",testCase);
	static int sums[1<<20];
	mset(sums,0);
	int n = SZ(a);
	FOR(mask, 0, 1<<n)
		FOR(i,0,n)
		if(bit(mask,i))
			sums[mask] += a[i];
	VVI ans;
	FOR(mask,1,1<<n)
		if(sums[mask] % 2 == 0)
		{
			for(int s1 = (mask-1)&mask; s1 > 0; s1 = (s1-1)&mask)
				if(sums[s1] == sums[s1^mask])
				{
					ans.resize(2);
					FOR(i,0,n)
					{
						if(bit(s1,i))
							ans[0].push_back(a[i]);
						if(bit(mask^s1,i))
							ans[1].push_back(a[i]);
					}
			
					FOR(i,0,2)
					{
						REPSZ(j,ans[i])
						{
							if(j) printf(" ");
							printf("%d",ans[i][j]);
						}
						puts("");
					}
					return;
				}
		}
	puts("Impossible");
}

int main()
{
#ifdef HOME_PC
	freopen ("C-small-attempt0(1).in","r",stdin);
	//freopen ("in.txt","r",stdin);
	freopen ("output.txt","w",stdout);
#else
	//freopen ("input.txt","r",stdin);
	//freopen ("output.txt","w",stdout);
#endif
	int numTests = 0;
	cin>>numTests;
	FORE(testCase,1,numTests)
	{
		int n;
		cin>>n;
		VI a(n);
		FOR(i,0,n)
			cin>>a[i];
		solve(a,testCase);
	}
	
#ifdef HOME_PC
	cerr<<endl<<"Execution time = "<<clock()<<" ms"<<endl;
#endif
	return 0;
}
