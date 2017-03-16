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
const int MAXN = 1010;

int N;

void go (int tt) {
	scanf("%d", &N);
	//separate 4 and above
	multiset<int, greater<int> > st;	//STORE DUPLICATES!!!!
	for (int i = 1, x; i <= N; i++) {
		scanf("%d", &x);
		st.insert(x);
	}
	int ans = MAXN, op = 0;
	do {
		//find the # of ops right now
		int x = *st.begin();
		ans = min(ans, x + op);
		st.erase(st.begin());
		st.insert(x / 2);
		st.insert(x / 2 + (x & 1));
		op++;
	} while (*st.begin() != 1 && op <= MAXN);
	printf("Case #%d: %d\n", tt, ans);
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