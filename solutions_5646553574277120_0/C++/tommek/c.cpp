#include "bits/stdc++.h"
using namespace std;

typedef long long LL;
typedef long double LD;
typedef vector<int> VI;
typedef pair<int,int> PII;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define FOREACH(it,v) for(decltype((v).begin())it=(v).begin();it!=(v).end();++it)
#define ST first
#define ND second
#define MP make_pair
#define PB push_back
#define ALL(v) (v).begin(),(v).end()
#define SIZE(x) ((int)(x).size())
#define DBG(x) cerr<<">> "<<#x<<" = "<<x<<endl;
const int MX = 1e6 + 5;
const int INF = 1e9 + 5;

int Res, c, d, v, keft = 0;
bool used[MX], dp[MX];

int main()
{
//	ios_base::sync_with_stdio(false);	
	int cases; cin >> cases; for (int ca = 1; ca <= cases; ++ ca)
	{
		scanf("%d%d%d", &c, &d, &v);
	
		for (int i = 0; i <= v; ++ i)
		{
			used[i] = false;
			dp[i] = false;
		}
		keft = v;

		dp[0] = true;

		for (int i = 0; i < d; ++ i)
		{
			int  a; scanf("%d", &a);
			used[a] = true;

			for (int k = v; k >= a; -- k)
				if (dp[k-a] == true)
				{
					if (dp[k] == false)
						keft --;

					dp[k] = true;
				}
		}

//		printf("%d\n", keft);

		for (int i = 1; i <= v && keft > 0; ++ i)
			if (!used[i] && !dp[i])
			{
				used[i] = true;
				for (int k = v; k >= i; -- k)
					if (dp[k-i] == true)
					{
						if (dp[k] == false)
							keft --;
						dp[k] = true;
					}
			}

		Res = 0;
		for (int i = 1; i <= v; ++ i)
			if (used[i])
				++ Res;

		printf("Case #%d: %d\n", ca, Res-d);
	}

	return 0;
}
