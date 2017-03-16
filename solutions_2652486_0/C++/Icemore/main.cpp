#pragma comment(linker,"/STACK:256000000")
#define _CRT_SECURE_NO_DEPRECATE

#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <functional>
#include <cmath>
#include <sstream>
#include <utility>
#include <ctime>
#include <memory.h>
#define forn(i,n) for (int i = 0; i < (int)(n); i++)
#define forv(i, a) for(int i=0; i<(int)a.size(); i++)
#define mset(a, val) memset(a, val, sizeof(a))
#define all(a) a.begin(),a.end()
#define mp make_pair
#define pb push_back
#define VI vector< int >
#define VS vector< string >
#define PII pair< int,int >
#define PDD pair< double,double >
#define PIS pair< int, string >
#define PLL pair<long long, long long>
#define sqr(a) ((a)*(a))
#define cube(a) ((a)*(a)*(a))
#define pi 3.1415926535897932384626433832795
#define PI pi
#define iinf 1000000000
#define linf 1000000000000000000LL
#define sinf 10000
#define eps 1e-9
#define lng long long
#define ulng unsigned long long
#define uint unsigned int
#define X first
#define Y second
using namespace std;
#define prev asdprev
#define exit(a) { if (a) cerr<<"oops "<<a<<endl; exit(a); }

int r, n, m, k;
int met[10];

void prods(int num)
{
	for(int i=2; i<=m; ++i)
	{
		int cur=0;
		int t=num;
		while(t%i==0)
		{
			t/=i;
			cur++;
		}

		met[i]=max(met[i], cur);
	}
}

void solveOne()
{
	mset(met, 0);

	int prod;
	forn(i, k)
	{
		cin>>prod;
		prods(prod);
	}

	int sum=0;
	for(int i=2; i<=m; ++i) sum+=met[i];
	
	met[2]-=sum-n;

	for(int i=2; i<=m; ++i)
		forn(q, met[i])
		cout<<i;
	cout<<endl;
}

void solve()
{
	cin>>r>>n>>m>>k;

	forn(q, r)
	{
		solveOne();
	}
}

#define taska "casting"
int main() {
#ifdef __ASD__
	freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#else
	//freopen(taska".in", "r", stdin);freopen(taska".out", "w", stdout);
	//freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0);

	int T;
	cin>>T;

	forn(tc, T)
	{
		cout<<"Case #"<<tc+1<<": "<<endl;
		solve();
	}
	
	return 0;
}

