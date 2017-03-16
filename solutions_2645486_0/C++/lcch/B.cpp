#include <iostream>
#include <cstdio>
#include <string.h>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

const int maxn = 10000 + 10;
int v[maxn];
int L[maxn];
int E, R, N;

int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B.out", "w", stdout);
	
	int TextN = 0, TT = 0;
	scanf("%d", &TextN);
	while (TextN--) {
		scanf("%d%d%d", &E, &R, &N);
		for (int i = 1; i <= N; i++) scanf("%d", v+i);
		
		L[0] = 0;
		for (int i = 1; i <= N; i++) {
			if (L[0] == 0) L[++L[0]] = i;
			else {
				while (L[0]>0 && v[L[L[0]]] <= v[i])
					--L[0];
				L[++L[0]] = i;
			}
		}
		
		long long ans = 0, tmp, now = E, dE, us;
		int j = 1;
		for (int i = 1; i <= N; i++) {
			if (j <= L[0] && L[j] == i) {
				ans = ans + now * v[i];
				++j;
				now = R;
			} else {
				dE = E - now;
				if (R > dE) {
					us = now;
					if (R - dE < us) us = R - dE;
					ans = ans + us * v[i];
					now -= us;
				}
				now += R;
				if (now > E) now = E;
			}
		}

		cout << "Case #" << ++TT << ": " << ans << endl;
	}
	return 0;
}