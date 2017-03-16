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

int val[11];
int e,r,n;
int pos(int i)
{
	int value;
	bool good = true;
	int curr = 0,j;
	for(j=i-1;j>=0;j--)
	{
		curr +=r;
		if(val[j]!=-1)
			break;
	}
	if(j==-1)
		curr = e;
	curr = min(e,curr);
	int nowe= curr;
	for(value=nowe;value>=1;value--)
	{
		bool good = true;
		int curr = nowe-value;
		for(int j=i+1;j<n;j++)
		{
			curr +=r;
			curr = min(e,curr);
			if(curr==e)
				break;
			if(val[j]==-1)
				continue;

			if(curr<val[j])
			{
				good = false;
				break;
			}
			curr-=val[j];
		}
		if(good)
			break;
	}
	val[i] = value;
	return value;
}

int main()
{
	int gg=1;
	int tt;cin >> tt;while (tt--)
	{
		cin >> e >> r >> n;
		fill(val, -1);
		VPII num;
		REP(i,n)
		{
			int a; s(a);
			num.pb(mp(a,i));
		}
		sort(all(num));
		reverse(all(num));
		int ans = 0;
		REP(j,n)
		{
			ans +=num[j].FF*pos(num[j].SS);
			//cout << num[j].SS << "  " << val[num[j].SS] << endl;
		}
		cout << "Case #" << gg++ << ": " << ans << endl;
	}
	return 0;
}
