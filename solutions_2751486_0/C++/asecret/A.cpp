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
#define LINF		(long long)1e18
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



bool check(int a,int b, string temp,int n)
{
	int c=0;
	for (int i=a;i<=b;i++)
	{
		if(temp[i]!='a' && temp[i]!='e' && temp[i]!='i' && temp[i]!='o' && temp[i]!='u')
			c++;
		else 
			c=0;
		if (c>=n)
			return true;
	}
	return false;
}
int main()
{
	int g=1;
	int tt;cin >> tt;while (tt--){
		string ss;
		int n,c=0;
		cin >> ss >> n;

		int len = ss.length();
		FOR(i,0,len)
		{
			FOR(j,i,len)
			{
				if (check(i,j,ss,n)) c++;
			}
		}
		cout << "Case #" << g++ << ": " << c << endl;
		
	}
	return 0;
}
