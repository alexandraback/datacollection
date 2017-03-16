#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define size(x) (int) x.size()

const int maxn = 1000005;
const int logn = 30;
const int inf = (int) 1e9 + 5;
const long long mod = (int) 1e9 + 7;
const long long base = 2204234849;
const long long l_inf = (long long) 4e18;
const long double pi = acos(-1.0);
const long double eps = 1e-12;

int T;
int cnt[256];
string num[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

inline string process(string str) {
	int ans[10];
	memset(ans, 0, sizeof ans);
	memset(cnt, 0, sizeof cnt);

	for (int i = 0; i < size(str); i++) {
		cnt[str[i]]++;
	}
	while (cnt['Z']) {
		ans[0]++;
		for (int i = 0; i < size(num[0]); i++)
			cnt[num[0][i]]--;
	}
	while (cnt['G']) {
		ans[8]++;
		for (int i = 0; i < size(num[8]); i++)
			cnt[num[8][i]]--;
	}
	while (cnt['X']) {
		ans[6]++;
		for (int i = 0; i < size(num[6]); i++)
			cnt[num[6][i]]--;
	}
	while (cnt['S']) {
		ans[7]++;
		for (int i = 0; i < size(num[7]); i++)
			cnt[num[7][i]]--;
	}
	while (cnt['V']) {
		ans[5]++;
		for (int i = 0; i < size(num[5]); i++)
			cnt[num[5][i]]--;
	}
	while (cnt['I']) {
		ans[9]++;
		for (int i = 0; i < size(num[9]); i++)
			cnt[num[9][i]]--;
	}
	while (cnt['U']) {
		ans[4]++;
		for (int i = 0; i < size(num[4]); i++)
			cnt[num[4][i]]--;
	}
	while (cnt['W']) {
		ans[2]++;
		for (int i = 0; i < size(num[2]); i++)
			cnt[num[2][i]]--;
	}
	while (cnt['H']) {
		ans[3]++;
		for (int i = 0; i < size(num[3]); i++)
			cnt[num[3][i]]--;
	}
	while (cnt['O']) {
		ans[1]++;
		for (int i = 0; i < size(num[1]); i++)
			cnt[num[1][i]]--;
	}

	string res = "";
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < ans[i]; j++)
			res += '0' + i;
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(10);
	cout << fixed;
	srand(566);

#ifdef LOCAL
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif

	cin >> T;
	for (int t = 1; t <= T; t++) {
		string str;
		cin >> str;

		cout << "Case #" << t << ": ";
		cout << process(str) << '\n';
	}

	return 0;
}
