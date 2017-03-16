#include <bits/stdc++.h>

using namespace std;

char s[1000], f[1000];
bool a[1000], b[1000];
int n, ques;
                                
pair<string, string> ans;
int diff;
char arr[10];

void go(int at) {
	if (at == ques) {
		int top = 0;
		for(int i = 0; i < n; ++i)
			if (a[i]) s[i] = arr[top++];
		for(int i = 0; i < n; ++i)
			if (b[i]) f[i] = arr[top++];
		int x, y;
		sscanf(s, "%d", &x);
		sscanf(f, "%d", &y);
		int curDiff = abs(x - y);
		string ss = "";
		string ff = "";
		for(int i = 0; s[i]; ++i) ss += char(s[i]);
		for(int i = 0; f[i]; ++i) ff += char(f[i]);
		pair<string, string> cur = make_pair(ss, ff);
		if (diff > curDiff) {
			diff = curDiff;
			ans = cur;
		}
		else if (diff == curDiff && ans > cur) ans = cur;
		return;
	}
	for(int i = 0; i < 10; ++i) {
		arr[at] = i + '0';
		go(at + 1);
	}
}

void solve() {
	scanf("%s%s", s, f);
	n = strlen(s);
	memset(a, false, sizeof a);
	memset(b, false, sizeof b);
	ans = make_pair("9999", "0");
	diff = 9999;
	ques = 0;
	for(int i = 0; s[i]; ++i)
		if (s[i] == '?') {
			++ques;
			a[i] = true;
		}
	for(int i = 0; f[i]; ++i)
		if (f[i] == '?') {
			++ques;
			b[i] = true;
		}
	go(0);
	cout << ans.first << ' ' << ans.second << '\n';
}

int main() {
	int ntest;
	scanf("%d", &ntest);
	for(int tc = 1; tc <= ntest; ++tc) {
		cerr << tc << '\n';
		printf("Case #%d: ", tc);
		solve();
	}
	return 0;
}
