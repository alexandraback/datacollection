#include <stdio.h>
#include <vector>
#include <map>
#include <set>
using namespace std;

int cases, kejs;
int i, j, N, res;
int d[1000], n[1000], w[1000], e[1000], s[1000], dd[1000], dp[1000], ds[1000];
struct ATTACK {
    int w, e, s;
} a;
map<int, vector<ATTACK> > m;
map<int, vector<ATTACK> >::iterator mit;
map<int, int> wall;
map<int, int>::iterator wit;

int main() {
    scanf("%d", &cases);
    for (kejs = 1; kejs <= cases; kejs++) {
        printf("Case #%d: ", kejs);
        m.clear();
		wall.clear();
		res = 0;
        scanf("%d", &N);
        for (i = 0; i < N; i++) {
            scanf("%d%d%d%d%d%d%d%d", &d[i], &n[i], &w[i], &e[i], &s[i], &dd[i], &dp[i], &ds[i]);
            for (j = 0; j < n[i]; j++) {
                a.w = w[i];
                a.e = e[i];
                a.s = s[i];
                m[d[i]].push_back(a);
                w[i] += dp[i];
                e[i] += dp[i];
                s[i] += ds[i];
                d[i] += dd[i];
            }
        }
		for (mit = m.begin(); mit != m.end(); ++mit) {
			for (i = 0; i < (int) mit->second.size(); i++) {
				bool suc = false;
				for (j = mit->second[i].w; j < mit->second[i].e; j++) {
					if (wall[j] < mit->second[i].s) {
						suc = true;
						break;
					}
				}
				if (suc) res++;
			}
			for (i = 0; i < (int) mit->second.size(); i++) {
				for (j = mit->second[i].w; j < mit->second[i].e; j++) {
					if (wall[j] < mit->second[i].s) wall[j] = mit->second[i].s;
				}
			}
		}
		printf("%d\n", res);
    }
    return 0;
}

