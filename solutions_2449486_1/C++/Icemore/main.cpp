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
#define X first
#define Y second
using namespace std;
#define prev asdprev
#define exit(a) { if (a) cerr<<"oops "<<a<<endl; exit(a); }

int n, m;
int a[200][200];
int row[200], col[200];

bool solve()
{
	cin>>n>>m;

	forn(i, n)forn(j, m) cin>>a[i][j];

	forn(i, n) row[i]=-1;
	forn(j, m) col[j]=-1;

	forn(i, n) forn(j, m)
	{
		row[i]=max(row[i], a[i][j]);
		col[j]=max(col[j], a[i][j]);
	}

	forn(i, n)forn(j, m)
	{
		if(row[i]>a[i][j] && col[j]>a[i][j])
			return false;
	}

	return true;
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
		cout<<"Case #"<<tc+1<<": "<<(solve() ? "YES" : "NO")<<endl;
	}
	
	return 0;
}

