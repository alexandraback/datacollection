// This works!!
//Data-structures includes
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<string>
#include<list>

//Other Includes
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<limits.h>

using namespace std;

#define s(n)		scanf("%d",&n)
#define sf(n) 		scanf("%lf",&n)
#define ss(n) 		scanf("%s",n)
#define pb		push_back
#define mp	 	make_pair
#define fill(a,v) 	memset(a, v, sizeof(a))
#define SZ(v)		(int)(v.size())
#define all(x)		x.begin(), x.end()
#define INDEX(arr,ind)	(lower_bound(all(arr),ind)-arr.begin())
#define FF		first
#define SS		second
#define EPS		1e-9
#define INF		(int)1e9
#define LINF		(long long)1e9
#define FOR(i,a,b)	for(int i=a;i<b;i++)
#define REP(i,n)	FOR(i,0,n)
#define CHECKSQRT(n)    (typeof(n))sqrt(n)*(typeof(n))sqrt(n)==n
#define T(t)            int t;scanf ("%d",&t);while (t--)

typedef vector<int> VI;
typedef priority_queue<int> MXHEAP;
typedef priority_queue<int,VI,greater<int> > MNHEAP;
typedef vector<vector<int> > VVI;
typedef long long int LL;
typedef vector<long long> VLL;
typedef pair<int,int> PII;
typedef vector<pair<int,int> > VPII;
typedef pair<double,double> PDD;

const long double PI = 3.141592653589793238L;
// t>=n*(2*pi*r+pi+2*pi*(n-1))
LL gogo(LL r,LL t)
{
	LL l=0,h=2*LINF;
	while (l<h)
	{
		LL n = (l+h+1)/2;
		//cout << h << " " << l << " " << n*(2*r + 1 + (2*(n-1)))<<endl;
		if ((1.0*t)/n >= (2*r + 1 + (2*(n-1))))
			l=n;
		else
			h=n-1;

	}
	return l;
}
int main()
{
	int gg=1;
	int tt;cin >> tt;while (tt--)
	{
		LL r,t;
		cin >> r >> t;
		cout << "Case #" << gg++ << ": " << gogo(r,t) << endl;
	}
	return 0;
}
