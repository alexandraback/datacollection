#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int n;
int bff[2000];
int perm[1000];
int was[1000];
int bestans;

void
go(int v)
{
	bool ok = true;
	for (int i = 0; i < v; ++i) {
		if (!(bff[perm[i]] == perm[(i + v - 1) % v] || bff[perm[i]] == perm[(i + 1) % v])) {
			ok = false;
		}
	}
	if (ok) {
		bestans = max(bestans, v);
	}
	if (v == n) {
		return;
	}
	for (int i = 0; i < n; ++i) {
		if (!was[i]) {
			was[i] = 1;
			perm[v] = i;
			go(v + 1);
			was[i] = 0;
		}
	}
}

void
solve()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &bff[i]);
		bff[i]--;
	}
	bestans = 0;
	go(0);
	printf("%d\n", bestans);
}

int
main()
{
    int t;
    scanf("%d\n", &t);
    for (int i = 0; i < t; ++i) {
        printf("Case #%d: ", i + 1);
        solve();
    }
}
