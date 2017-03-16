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
	} else if (K == 5) {
		//prime
		if (N < 3 || M < 3) {
			print(false);
			return;
		}
		if (M % 5 == 0) {
			swap(N, M);
		}
		if (N == 5) {
			print(M >= 4);
		} else {
			print(true);
		}
	} else {
		//K = 6
		if (N <= 3 || M <= 3) {
			//0, 1, 2, 3
			print(false);
			return;
		}
		if (N < 6 && M < 6) {
			//can't tile the straight one
			print(false);
			return;
		}
		print(true);
		//3 * 2n -> not possible
		//6 * (4 and above) -> 5 * 6 -> 5 * 6n
		//that implies 6 * 7 -> 7 * 6n
		//8 * (6, 9, 12, ...)
		//9 * (4, 6, 8, 10, 12, ...)
		//10 * (6, 9, 12, ...)
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