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

#define N 110

int n,s,p,tests;
int a[N];

int main()
{
	freopen("input.txt","r", stdin);
	freopen("output.txt","w", stdout);
	scanf("%d",&tests);
	REP(t,tests)
	{
		scanf("%d%d%d",&n,&s,&p);
		REP(i,n)
			scanf("%d",&a[i]);
		int ans = 0;
		REP(i,n)
		{
			if(a[i] >= 3*p)
			{
				++ans;
			}
			else if(a[i] >= 3*p-2 && p-1 >= 0)
			{
				++ans;
			}
			else if(a[i] >= 3*p-4 && p-2 >= 0 && s > 0)
			{
				++ans;
				--s;
			}
		}
		printf("Case #%d: %d\n",t+1,ans);
	}
	return 0;
}

