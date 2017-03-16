#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <utility>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

#define INF 1000000000

const double PI = acos(-1.0);

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector< pii > vpii;
typedef long long ll;

const int MAXN = 10010;

int cases;
int E, R, num;
int V[MAXN];

long long DP[MAXN][10];

long long calc(int idx, int e) {
	if (idx == num-1) return V[idx] * e; //spend the rest
	if (DP[idx][e] != -1) return DP[idx][e];
	long long best = 0;
	for(int i=0; i<=e; i++) {
		best = max(best, ll(V[idx]) * ll(i) + calc(idx+1, min(e-i+R, E)));
	}
	return DP[idx][e] = best;
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	scanf("%d", &cases);
	for(int casen = 1; casen <= cases; casen++) {
		scanf("%d%d%d", &E, &R, &num);
		memset(V, -1, sizeof V);
		memset(DP, -1, sizeof DP);
		for(int i=0; i<num; i++) {
			scanf("%d", &V[i]);
		}
		long long ans = calc(0, E);
		printf("Case #%d: %lld\n", casen, ans);
	}





	return 0;
}