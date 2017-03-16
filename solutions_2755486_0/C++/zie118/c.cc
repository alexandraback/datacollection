#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <stack>
#include <iostream>
#include <sstream>
#include <bitset>

using namespace std;

#define inf (1<<29)
#define eps (1e-9)

#define flt(x,y) ((x)<(y)-eps)
#define fgt(x,y) flt(y,x)
#define fle(x,y) !fgt(x,y)
#define fge(x,y) !flt(x,y)
#define feq(x,y) (fabs((x)-(y))<eps)

#define PB push_back
#define MP make_pair

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

typedef struct {
	int w, e, s;
} P;

int H[10000], Hm[10000];
map<int, vector<P> > ats;
map<int, vector<P> >::iterator it;

int d[100], n[100], s[100], e[100], w[100], dd[100], dp[100], ds[100];
int N;

int main()
{
	int T,cc=0; scanf("%d", &T);
	while (T--)
	{
		ats.clear();
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
		{
			scanf("%d %d %d %d %d %d %d %d", &d[i], &n[i], &w[i], &e[i], &s[i], &dd[i], &dp[i], &ds[i]);
			for (int j = 0; j < n[i]; j++)
			{
				int day = d[i] + j * dd[i];
				P p;
				p.w = (w[i] + j * dp[i] + 1000) * 2;
				p.e = (e[i] + j * dp[i] + 1000)*2;
				p.s = s[i] + j * ds[i];
				ats[day].PB(p);
			}
		}
		memset(H, 0, sizeof(H));
		int ans = 0;
		for (it=ats.begin(); it != ats.end(); it++)
		{
			memset(Hm, 0, sizeof(Hm));
			for (int j = 0; j < it->second.size(); j++)
			{
				int succ = 0;
				for (int k = it->second[j].w; k <= it->second[j].e; k++)
				{
					Hm[k] = max(it->second[j].s, H[k]);
					if (H[k] < it->second[j].s) {
						succ = 1;
					}
				}
				if (succ) ans++;
			}
			for (int i = 0; i < 10000; i++) H[i] = max(H[i], Hm[i]);
		}
		printf("Case #%d: %d\n", ++cc, ans);
	}
	return 0;
}
