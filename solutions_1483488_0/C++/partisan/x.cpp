#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <queue>
#include <list>
#include <deque>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

#define FOR(i,a,b) for(int i(a),_b(b); i < _b; ++i)
#define REP(i,n) FOR(i,0,n)
#define FORD(i,a,b) for(int i(a),_b(b); i >= _b; --i)
#define X first
#define Y second
#define pb push_back
#define sz(a) (int)(a).size()

#define N 2000005

int n,m,a,b,t,T,d;
int numd[N];
int pow10[7];
bool used[N];
vi f[N];

inline int numDigits(int a)
{
	int res = 0;
	while(a)
	{
		++res;
		a /= 10;
	}
	return res;
}

int main()
{
	freopen("input.txt","r", stdin);
	freopen("output.txt","w", stdout);
	pow10[0] = 1;
	FOR(i,1,7)
		pow10[i] = 10 * pow10[i-1];
	FOR(i,1,N)
		numd[i] = numDigits(i);
	FOR(n,1,N)
	{
		m = n;
		int d = numd[n];
		REP(i,d)
		{
			int c = m % 10;
			m = m / 10 + c * pow10[d-1];  
			if( m <= N && numd[m] == d && !used[m])
			{
				f[n].pb(m);
				used[m] = 1;
			}
		}
		REP(i,sz(f[n]))
			used[f[n][i]] = 0;
	}
	scanf("%d",&T);
	REP(t,T)
	{
		scanf("%d%d",&a,&b);
		int ans = 0;
		FOR(n,a,b)
			REP(i,sz(f[n]))
				if(f[n][i] > n && f[n][i] <= b)
					++ans;
		printf("Case #%d: %d\n",t+1,ans);
	}
	return 0;
}

