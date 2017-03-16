#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>

#define sqr(a) (a) * (a)
#define N 10000

using namespace std;


int n, t, i, tt;
int mx;
int f[N], rf[N], d[N], cnt[N];
bool used[N], used2[N], cycled[N];

void dfs(int u) {
	used[u] = true;
	if (!used[rf[u]] && rf[u])
		dfs(rf[u]);
	d[u] = max(d[u], d[rf[u]] + 1);
}


void solve() {

	// searching for cycles
	int counter = 0, len, i;
	for (int j = 1; j <= n; j++) {
			cnt[j] = 0;
			used[j] = false;
		}

	for (i = 1; i <= n; i++)
	if (!cycled[i])
	{
		int u = i;
		counter = 0;
		do {
			used[u] = true;
			cnt[u] = ++counter;
			u = f[u];
		} while(!used[u]);

		counter++;

		len = counter - cnt[u];

		cycled[u] = true;

		if (len > mx)
			mx = len;

		for (int j = 1; j <= n; j++) {
			cnt[j] = 0;
			used[j] = false;
		}
	}

    for (i = 1; i <= n; i++) {
    	cycled[i] = false;
    }

    int u;
    int len2 = 0;
	for (i = 1; i <= n; i++) {
		if (f[f[i]] == i && !used2[i]) {
		    int c1, c2;
		    c1 = c2 = 0;
            for (int j = 1; j <= n; j++)
                if (j != i && j != f[i]){
                    counter = 0;
                    u = j;
                    do {
                        if (u == i)
                            break;
                        ++counter;
                        used[u] = true;
                        u = f[u];
                    } while(u && u != f[i] && u != i && !used[u]);

                    if (u == i)
                        c1 = max(c1, counter);

                    if (u == f[i])
                        c2 = max(c2, counter);

                    for (int k = 1; k <= n; k++)
                        used[k] = false;
                }

            len2 += (2 + c1 + c2);
            used2[f[i]] = used2[i] = true;
		}
    }

    for (i = 1; i <= n; i++)
        used2[i] = false;
    mx = max(len2, mx);
}

int main()  {

    #ifndef ONLINE_JUDGE
    freopen("a.in", "r" , stdin);
   	freopen("a.out", "w", stdout);
    #endif


    cin >> t;
    for (tt = 1; tt <= t; tt++) {
    	scanf("%d", &n);
    	for (i = 1; i <= n; i++)
    		scanf("%d", &f[i]);

    	solve();
    	printf("Case #%d: %d\n", tt, mx);
    	mx = 0;
    }


    return 0;
}
