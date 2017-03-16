#include <iostream>
using namespace std;

char keys[10];
char target[10];
char types[10];
int K, L, S;
double ans;
double probs[30];
int avaiable[256];

int cases;
int max_reward;
double totals;

static int check()
{
	int i;
	int cnt = 0;
	for (i = 0; i < S; ++i) {
		int j, k;
		for (j = i, k = 0; k < L && j < S; ++j, ++k)
			if (target[k]!=types[j])
				break;
		if (k == L)
			++cnt;
	}
	return cnt;
}

static void press(int length, double prob) {
	int i;
	int ret;
	if (length == S) {
		ret = check();
		//printf("types: %s, prob: %lf, reward: %d\n", types, prob, ret);
		totals += ret * prob;
		cases++;
		if (ret > max_reward)
			max_reward = ret;
		return;
	}
	for (i = 'A'; i <= 'Z'; ++i) {
		if (avaiable[i]) {
			types[length] = i;
			press(length + 1, prob * probs[i - 'A']);
		}
	}
}

static void solve() {
	press(0, 1.0);
	return;
}

int main()
{
	int T, t;
	int i;
	scanf("%d\n", &T);
	for (t = 1; t <= T; ++t) {
		memset(probs, 0, sizeof(probs));
		memset(avaiable, 0, sizeof(avaiable));
		memset(types, 0, sizeof(types));

		scanf("%d %d %d\n", &K, &L, &S);
		scanf("%s\n", keys);
		scanf("%s\n", target);
		max_reward = 0;
		totals = 0;
		cases = 1;

		for (i = 0; i < K; ++i) {
			probs[keys[i] - 'A'] += 1.0/K;
			//printf("char: %c, prob: %lf\n", keys[i], probs[keys[i] - 'A']);
			avaiable[keys[i]] = 1;
		}
		solve();
		//printf("max_reward %d, totals %lf, cases %d\n", max_reward, totals, cases);
		ans = max_reward - totals * 1.0;
		printf("Case #%d: %lf\n", t, ans);
	}
	return 0;
}