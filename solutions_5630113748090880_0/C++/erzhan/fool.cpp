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
#define pb push_back
#define N 65

using namespace std;

int v[N];
int cnt[N * N];
int t, tt, i, j, sz, n, x;

int main()  {

    #ifndef ONLINE_JUDGE
    freopen("a.in", "r" , stdin);
    freopen("a.out", "w", stdout);
    #endif

    cin >> t;

    for (tt = 1; tt <= t; tt++) {
		scanf("%d", &n);
		for (i = 1; i < 2 * n; i++)
			for (j = 1; j <= n; j++) {
				scanf("%d", &x);
				cnt[x]++;
			}

        sz = 0;
		for (i = 1; i <= 2500; i++) {
			if (cnt[i] & 1)
				v[++sz] = i;
			cnt[i] = 0;
		}

		sort (v + 1, v + sz + 1);

		printf("Case #%d: ", tt);
		for (i = 1; i <= n; i++)
			printf("%d ", v[i]);
		printf("\n");
    }
          
    return 0;
}