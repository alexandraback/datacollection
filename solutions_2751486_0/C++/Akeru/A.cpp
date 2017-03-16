#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
using namespace std;

#define REP(i, s, e) for (int i = (s); i < (e); i++)
#define REPI(i, s, e) for (int i = (s); i <= (e); i++)
#define rep(i, n) REP(i, 0, n)
#define repi(i, n) REPI(i, 0, n)
#define ALL(v) (v).begin(), (v).end()

#define dump(x) (cout << #x << " = " << x << endl)
#define dump2(x, y) (cout << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")" << endl)
#define dump3(x, y, z) (cout << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", "<< z << ")" << endl)

typedef long long ll;
typedef pair<int, int> pii;

int T, n;
string str;
int len;

#define MAX 105
int memo[MAX][MAX];

bool is_vowel(char ch)
{
	return ch == 'a'
		|| ch == 'e'
		|| ch == 'i'
		|| ch == 'o'
		|| ch == 'u';
}

bool is_consonant(char ch) { return !is_vowel(ch); }

bool check(int l, int r)
{
	int cnt = 0;
	REPI(i, l, r) {
		if (is_consonant(str[i])) {
			if (++cnt == n)
				return true;
		} else {
			cnt = 0;
		}
	}
	return false;
}

ll dfs(int l, int r)
{
	if (l > r) return 0;
	if (memo[l][r]) return 0;
	memo[l][r] = 1;

	ll cnt = check(l, r)?1:0;
	cnt += dfs(l+1, r) + dfs(l, r-1);
	return cnt;
}

int main(void)
{
	cin >> T;
	rep(t, T) {
		cin >> str >> n;

		memset(memo, 0, sizeof(memo));
		len = str.size();
		ll ans = dfs(0, len-1);
		printf("Case #%d: %lld\n", t+1, ans);
	}
	return 0;
}
