#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i=0;i<(n);i++)
#define MOD 1000000007
#define MP make_pair
#define PB push_back
typedef long long ll;

int T, N, M;

int solve (int v) {
	int n = 10, i = 0; bool s[10] = {0};
	while (n) {
		i++;
		int j = v*i;
		while (j) {
			if (!s[j%10]) n--;
			s[j%10] = 1;
			j /= 10;
		}
	}
	return v*i;
}

int main () {
	scanf("%d", &T);
	for (int _ = 1; _ <= T; _++) {
		scanf("%d", &N);
		if (N) printf("Case #%d: %d\n", _, solve(N));
		else printf("Case #%d: INSOMNIA\n", _);
	}
	return 0;
}
