#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

const int maxn = 25;
const int maxmask = (1 << 21);
const int maxkey = 45;

bool can[maxmask];
vector<int> from[maxmask];
int k, n;
int key[maxkey];
int keyin[maxn][maxkey];
int t[maxn], kv[maxn];
vector<int> nextfr;

bool cann(int mask, int id)
{
    int curkv = 0;
    for (int i = 0; i < k; i++) if (key[i] == t[id]) curkv++;
    for (int i = 0; i < n; i++) if (mask & (1 << i))
    {
        if (t[i] == t[id]) curkv--;
        for (int j = 0; j < kv[i]; j++) if (keyin[i][j] == t[id]) curkv++;
    }
    return curkv > 0;
}

int main()
{
    int NT = 0;
    scanf("%d", &NT);
    for (int T = 1; T <= NT; T++)
    {
        scanf("%d%d", &k, &n);
        for (int i = 0; i < k; i++) scanf("%d", &key[i]);
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d", &t[i], &kv[i]);
            for (int j = 0; j < kv[i]; j++) scanf("%d", &keyin[i][j]);
        }
        
        int km = (1 << n);
        for (int mask = 0; mask < km; mask++) can[mask] = false;
        can[0] = true;
        for (int mask = 0; mask < km; mask++) if (can[mask])
        {
            for (int i = 0; i < n; i++) if (!(mask & (1 << i)))
            {
                if (cann(mask, i))
                {
                    nextfr = from[mask];
                    nextfr.push_back(i);
                    int nextm = mask | (1 << i);
                    if (!can[nextm] || (can[nextm] && from[nextm] > nextfr))
                    {
                        can[nextm] = true;
                        from[nextm] = nextfr;
                    }
                }
            }
        }
        
        printf("Case #%d: ", T);
        if (can[km - 1])
        {
            for (int i = 0; i < n; i++) printf("%d ", from[km - 1][i] + 1);
            printf("\n");
        } else printf("IMPOSSIBLE\n");
        fprintf(stderr, "%d/%d cases done!\n", T, NT);
    }
    return 0;
}
