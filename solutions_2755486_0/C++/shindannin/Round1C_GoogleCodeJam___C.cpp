// I may use the MPIR library. Its website is this,
// http://www.mpir.org/

#include <stdio.h>
#include <tchar.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
using namespace std;

typedef long long ll;
static const double EPS = 1e-6;
inline int ROUND(double x) { return (int)(x+0.5); }
inline bool ISINT(double x) { return fabs(ROUND(x)-x)<EPS; }
inline bool ISEQUAL(double x,double y) { return fabs(x-y)<EPS; }
#define INRANGE(x,a,b) ((a)<=(x)&&(x)<=(b))
#define ARRAY_NUM(a) (sizeof(a)/sizeof(a[0])) 
#define SZ(a) ((int)a.size())

int main()
{
	freopen("_google_code_jam_input.txt","r",stdin);
	freopen("_google_code_jam_output.txt","w",stdout);

	int T;
	scanf("%d ",&T);

	for (int t=0;t<T;t++)
	{
		int N;
		scanf("%d ",&N);
		vector <ll> d(N),n(N),w(N),e(N),s(N),dd(N),dp(N),ds(N);

		for (int i = 0; i < N; i++)
		{
			scanf("%lld %lld %lld %lld %lld %lld %lld %lld ",&d[i],&n[i],&w[i],&e[i],&s[i],&dd[i],&dp[i],&ds[i]);
		}

		vector < pair <ll, pair < int, int > > > attackInfo; // (day, ( tribeID, attack times) )
		for (int tribeID = 0; tribeID < N; tribeID++)
		{
			for (int times = 0; times < n[tribeID]; times++)
			{
				ll day = d[tribeID]+dd[tribeID]*times;
				attackInfo.push_back(make_pair(day, make_pair(tribeID,times)));
			}
		}

		sort(attackInfo.begin(),attackInfo.end());

		const int WALL_DEF = 10000;
		vector <ll> wall(WALL_DEF*2);

		ll ret = 0;
		for (int all_attacks = 0; all_attacks < SZ(attackInfo); all_attacks++)
		{
			vector <ll> next_wall(wall);
			for (int attackID = all_attacks; attackID<SZ(attackInfo) && attackInfo[attackID].first==attackInfo[all_attacks].first ; attackID++)
			{
				const int tribeID = attackInfo[attackID].second.first;
				const int times   = attackInfo[attackID].second.second;

				const ll nowE	= e[tribeID]+dp[tribeID]*times;
				const ll nowW	= w[tribeID]+dp[tribeID]*times; 
				const ll nowStr	= s[tribeID]+ds[tribeID]*times;

				bool ok = false;
				// BEGIN CUT HERE
//				cout << " tribeID=" << tribeID << " times=" << times << " nowE=" << nowE << " nowW=" << nowW << " nowStr=" << nowStr << endl;
				// END CUT HERE

				for (ll place = nowW*2; place <= nowE*2; place++)
				{
					// BEGIN CUT HERE
//					cout << " place=" << place << " wall[place+WALL_DEF]=" << wall[place+WALL_DEF] << " nowStr=" << nowStr << endl;
					// END CUT HERE

					if(wall[place+WALL_DEF]<nowStr)
					{
						ok = true;
						next_wall[place+WALL_DEF] = max(next_wall[place+WALL_DEF],nowStr);
					}
				}

				if(ok)
				{
					ret++;
					// BEGIN CUT HERE
//					cout << " ret=" << ret << endl;
					// END CUT HERE


				}
			}
			wall = next_wall;
		}

		fprintf(stderr, "Case #%d: %lld\n",t+1,ret);
		printf("Case #%d: %lld\n",t+1,ret);
	}

	return 0;
}