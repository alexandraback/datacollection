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
const int MAXN = 1.3e6;

//1 = 0, i = 1, j = 2, k = 3

int mult[8][8] = 
{
	{0, 1, 2, 3, 4, 5, 6, 7},	//1, i, j, k
	{1, 4, 3, 6, 5, 0, 7, 2},	//i, -1, k, -j
	{2, 7, 4, 1, 6, 3, 0, 5},	//j, -k, -1, i
	{3, 2, 5, 4, 7, 6, 1, 0},	//k, j, -i, -1
	{4, 5, 6, 7, 0, 1, 2, 3},
	{5, 0, 7, 2, 1, 4, 3, 6},
	{6, 3, 0, 5, 2, 7, 4, 1},
	{7, 6, 1, 0, 3, 2, 5, 4}
};

int pwr (int x, ll y) {
	y %= 4;
	int res = 0;
	while (y--) {
		res = mult[res][x];
	}
	return res;
}

void print (bool b) {
	puts(b ? "YES" : "NO");
}

int N, A[MAXN];
ll M;

bool brute() {
	for (int i = 1; i < M; i++) {
		copy_n(A, N, A + i * N);
	}
	int want = 1, cur = 0;
	for (int i = 0; i < M * N; i++) {
		//then just do it
		cur = mult[cur][A[i]];
		if (cur == want) {
			//then just do it
			if (want == 2) {
				if (i < M * N - 1) {
					return true;
				}
			} else {
				want = 2;
				cur = 0;
			}
		}
	}
	return false;
}

bool mg12() {
	for (int i = 1; i < 4; i++) {
		copy_n(A, N, A + i * N);
	}
	//make sure you can go fwd and backward
	bool ans = false;
	int cur = 0;
	for (int i = 0; i < 4 * N; i++) {
		//see if you can get an i
		cur = mult[cur][A[i]];
		if (cur == 1) {
			ans = true;
			break;
		}
	}
	if (!ans) {
		return false;
	}
	cur = 0;
	for (int i = 4 * N - 1; i >= 0; i--) {
		cur = mult[A[i]][cur];
		if (cur == 3) {
			return true;
		}
	}
	return false;
}

void go (int tt) {
	//clear stuff?
	scanf("%d %lld\n", &N, &M);	//M times
	printf("Case #%d: ", tt);
	int smult = 0;
	for (int i = 0; i < N; i++) {
		A[i] = getchar() - 'i' + 1;
		smult = mult[smult][A[i]];
	}
	if (pwr(smult, M) != 4) {
		//then it's not
		print(false);
	} else {
		print(M <= 12 ? brute() : mg12());
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