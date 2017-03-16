//why are you stalking me?
#include <bits/stdc++.h>

using namespace std;

#define fillchar(a, s) memset((a), (s), sizeof(a))
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define all(v) (v).begin(), (v).end()
#define rep(it, v) for (auto it = (v).begin(); it != (v).end(); it++)
#define dbg(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> pii;

void print (bool b) {
	puts(b ? "GABRIEL" : "RICHARD");
}

int N, M, K;

void go (int tt) {
	scanf("%d %d %d", &K, &N, &M);
	printf("Case #%d: ", tt);
	if (((N * M) % K) || (K > N && K > M) || (K >= 7)) {
		//not divisible, too big, too big, or the hole
		print(false);
	} else if (K <= 2) {
		print(true);
	} else if (K == 3) {
		print(N != 1 && M != 1);
	} else if (K == 4) {
		print(N > 2 && M > 2);
	}
}

int main() {
	//why are you stalking me?
	if (fopen("input.txt", "r")) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	int tt;
	scanf("%d", &tt);
	for (int i = 1; i <= tt; i++) {
		go(i);
	}
}