#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <string.h>

typedef long long ll;
using namespace std;

const int INF = (1<<29);
const char *digits[] = {
	"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
};
char ans[2100] = {};
int s[28] = {};
int dd[10] = {};

int rec(int i, int ind) {
	if (i == 10) {
		if (all_of(s, s+26, [](int x){ return x == 0; })) {
			ans[ind] = '\0';
			return ind;
		}
		return 0;
	}
	if (i%2 == 0) {
		for (int k = 0; k < dd[i]; k++) {
			ans[ind++] = i+'0';
		}
		int newind = rec(i+1, ind);
		if (newind != 0)
			return newind;
		ind -= dd[i];
		return 0;
	}
	int c = INF;
	map<int, int> cnt;
	for (int j = 0; digits[i][j]; j++) {
		cnt[digits[i][j]-'A']++;
	}
	for (auto j = cnt.begin(); j != cnt.end(); ++j) {
		c = min(c, s[j->first] / j->second);
	}
	//printf("%d %d\n", i, c);
	for (int j = c; j >= 0; j--) {
		for (int k = 0; digits[i][k]; k++) {
			s[digits[i][k]-'A'] -= j;
		}
		for (int k = 0; k < j; k++) {
			ans[ind++] = i+'0';
		}
		int newind = rec(i+1, ind);
		if (newind != 0)
			return newind;
		ind -= j;
		for (int k = 0; digits[i][k]; k++) {
			s[digits[i][k]-'A'] += j;
		}
	}
	return 0;
}

string solve(const char *arg) {
	memset(s, 0, sizeof(s));
	for (int i = 0; arg[i]; i++) {
		s[arg[i]-'A']++;
	}
	int d[] = {'Z', 'W', 'U', 'X', 'G'};
	memset(dd, 0, sizeof(dd));
	for (int i = 0; i < 5; i++) {
		int c = s[d[i]-'A'];
		dd[i*2] = c;
		for (int k = 0; digits[i*2][k]; k++) {
			s[digits[i*2][k]-'A'] -= c;
		}
	}
	int ind = rec(0, 0);
	if (ind == 0) {
		return string("!!!!!!!!!!!!!!!!!!!!!!!!");
	}
	return string(ans);
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		char s[2010];
		scanf("%s", s);
		string ans = solve(s);
		printf("Case #%d: %s\n", i+1, ans.c_str());
	}
}
