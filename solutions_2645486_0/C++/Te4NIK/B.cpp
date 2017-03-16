#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define clr(x) memset((x), 0, sizeof(x))
#define pb push_back
#define mp make_pair
#define sz size()
#define x first
#define y second
#define forn(i, n) for(int i=0; i<(n); i++)
#define ford(i, n) for(int i=(n)-1; i>=0; i--)

typedef long double ld;

// Constants
const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-11;

// Types
typedef signed   long long i64;
typedef unsigned long long u64;
typedef pair < int, int > PII;

int T;
int e,r,n;
int v[20];
int sp[20];
int ans;

void dfs(int ind, int en)
{
	if(ind==n)
	{
		int tans=0;
		forn(i,n)
			tans+=sp[i]*v[i];
		ans=max(ans,tans);
		return;
	}
	forn(i,en+1)
	{
		sp[ind]=i;
		dfs(ind+1,min(en-i+r,e));
	}
}
         
int main()
{
	freopen("z.in", "rt", stdin);
	freopen("z.out", "wt", stdout);

	cin >>T;
	forn(tt,T)
	{
		cin >>e>>r>>n;
		forn(i,n)
			cin >>v[i];
		ans=-1;
		dfs(0,e);
		cout <<"Case #"<<tt+1<<": "<<ans<<endl;
	}

	return 0;
}
