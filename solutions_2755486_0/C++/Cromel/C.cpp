#include <stdio.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <sstream>
#include <stack>
#include <string.h>
#include <list>
#include <assert.h>

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define PI 3.14159265358979
#define forn(i, n) for(int i = 0; i < n; ++i)
#define ALL(x) x.begin(), x.end()
#define L(s) (int)((s).size())
#define ms(x) memset(x,0,sizeof(x))
#define ms1(x) memset(x,-1,sizeof(x))
#define del(y,x) erase(y.begin()+x)

typedef long long ll;
using namespace std;
typedef pair<int,int> pii;
const int INF = 2147483647;
const ll LLINF = 9223372036854775807LL;
const int ST = 100010;
const int ST1 = 1000010;
const ll MOD = 1000000007;

ll ABS(ll a)
{
    if(a<0)
        return a*(-1);
    else
        return a;
}

struct tribe
{
	int w,e,s,dp,ds;
};
vector<tribe> in;
vector<vector<pii> > days(676061);
int wal[1600];
int mod[1600];
int main()
{
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	int cur = 1,T;
	cin >> T;
	while(cur <= T)
	{
		int N;
		in.clear();
		ms(wal);
		cin >> N;
		for(int i = 0;i < N;i++)
		{
			int d,n,w,e,s,dd,dp,ds;
			cin >> d >> n >> w >> e >> s >> dd >> dp >> ds;
			tribe tem;
			tem.dp = dp;
			tem.ds = ds;
			tem.e = e;
			tem.s = s;
			tem.w = w;
			in.pb(tem);
			for(int j = 0;j < n;j++)
			{
				int to = d+(j*dd);
				days[to].pb(mp(i,j));
			}
		}
		int ans = 0;
		for(int i = 0;i < 676061;i++)
		{
			for(int j = 0;j < L(days[i]);j++)
			{
				int ti = days[i][j].X;
				int d = days[i][j].Y;
				int e = in[ti].e;
				int w = in[ti].w;
				int dp = in[ti].dp;
				int s = in[ti].s;
				int ds = in[ti].ds;
				e = 800 + (e + d*dp)*2;
				w = 800 + (w + d*dp)*2;
				s = s + ds * d;
				bool suc = false;
				for(int kor = w;kor <= e;kor++)
				{
					if(s > wal[kor])
					{
						suc = true;
					}
					mod[kor] = max(mod[kor],s);
				}
				if(suc)
					ans++;
			}
			if(L(days[i])>0)
			{
				for(int j = 0;j < 1600;j++)
				{
					wal[j] = max(mod[j],wal[j]);
				}
				ms(mod);
			}
			days[i].clear();
		}

		printf("Case #%d: %d\n",cur,ans);
		cur++;
	}

    return 0;
}