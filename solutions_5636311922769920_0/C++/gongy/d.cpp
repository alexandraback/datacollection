#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i=0;i<(n);i++)
#define MOD 1000000007
#define MP make_pair
#define PB push_back
typedef long long ll;

int T, K, C, S;

int main () {
	scanf("%d", &T);
	for (int _ = 1; _ <= T; _++) {
		scanf("%d %d %d", &K, &C, &S);
		printf("Case #%d:", _);
		fo(i, K) printf(" %d", i+1); puts("");
	}
	return 0;
}
