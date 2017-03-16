#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt(){
	int x;
	scanf("%d", &x);
	return x;
}

void upd(pair<long long, pair<string, string>>& ans, long long res, string s, string t){
	pair<long long, pair<string, string>> cur = {res, {s, t}};
	if (ans.first == -1 || ans > cur){
		ans = cur;
	}
}

void solve(int test){
	printf("Case #%d: ", test);

	string s, t;
	cin >> s >> t;

	int n = s.length();
	vector<long long> a(n + 1), b(n + 1);
	a[0] = b[0] = 0;
	long long cur = 1;
	for (int i = 0; i < n; i++){
		long long tmp = 0;
		if (s[n - 1 - i] == '?')
			tmp += 0;
		else
			tmp += s[n - 1 - i] - '0';
		if (t[n - 1 - i] == '?')
			tmp -= 9;
		else
			tmp -= t[n - 1 - i] - '0';
		a[i + 1] = a[i] + cur * tmp;

		tmp = 0;
		if (s[n - 1 - i] == '?')
			tmp += 9;
		else
			tmp += s[n - 1 - i] - '0';
		if (t[n - 1 - i] == '?')
			tmp -= 0;
		else
			tmp -= t[n - 1 - i] - '0';
		b[i + 1] = b[i] + cur * tmp;

		cur *= 10;
	}

	pair<long long, pair<string, string>> ans;
	ans.first = -1;
	for (int i = 0; i < n; i++){
		if (s[i] == '?' && t[i] == '?'){
			long long tmp = 1;
			string q = s, w = t;
			q[i] = '1';
			w[i] = '0';
			for (int j = i + 1; j < n; j++){
				if (q[j] == '?')
					q[j] = '0';
				if (w[j] == '?')
					w[j] = '9';
				tmp *= 10;
			}
			tmp += a[n - 1 - i];
			upd(ans, tmp, q, w);

			tmp = 1;
			q = s, w = t;
			q[i] = '0';
			w[i] = '1';
			for (int j = i + 1; j < n; j++){
				if (q[j] == '?')
					q[j] = '9';
				if (w[j] == '?')
					w[j] = '0';
				tmp *= 10;
			}
			// cerr << tmp << " " << b[n - 1 - i] << " " << ans.first << " " << q << " " << w << "\n";
			tmp -= b[n - 1 - i];
			upd(ans, tmp, q, w);

			s[i] = t[i] = '0';
		} else
		if (s[i] == '?'){
			if (t[i] < '9'){
				long long tmp = 1;
				string q = s, w = t;
				q[i] = t[i] + 1;
				for (int j = i + 1; j < n; j++){
					if (q[j] == '?')
						q[j] = '0';
					if (w[j] == '?')
						w[j] = '9';
					tmp *= 10;
				}
				tmp += a[n - 1 - i];
				upd(ans, tmp, q, w);
			}

			if (t[i] > '0'){
				long long tmp = 1;
				string q = s, w = t;
				q[i] = t[i] - 1;
				for (int j = i + 1; j < n; j++){
					if (q[j] == '?')
						q[j] = '9';
					if (w[j] == '?')
						w[j] = '0';
					tmp *= 10;
				}
				tmp -= b[n - 1 - i];
				upd(ans, tmp, q, w);
			}

			s[i] = t[i];
		} else
		if (t[i] == '?'){
			if (s[i] > '0'){
				long long tmp = 1;
				string q = s, w = t;
				w[i] = s[i] - 1;
				for (int j = i + 1; j < n; j++){
					if (q[j] == '?')
						q[j] = '0';
					if (w[j] == '?')
						w[j] = '9';
					tmp *= 10;
				}
				tmp += a[n - 1 - i];
				upd(ans, tmp, q, w);
			}

			if (s[i] < '9'){
				long long tmp = 1;
				string q = s, w = t;
				w[i] = s[i] + 1;
				for (int j = i + 1; j < n; j++){
					if (q[j] == '?')
						q[j] = '9';
					if (w[j] == '?')
						w[j] = '0';
					tmp *= 10;
				}
				tmp -= b[n - 1 - i];
				upd(ans, tmp, q, w);
			}

			t[i] = s[i];
		} else {
			if (s[i] != t[i]){
				long long cur = s[i] - t[i];
				for (int j = i + 1; j < n; j++){
					cur *= 10;
				}
				if (cur > 0){
					cur += a[n - 1 - i];
					for (int j = i + 1; j < n; j++){
						if (s[j] == '?')
							s[j] = '0';
						if (t[j] == '?')
							t[j] = '9';
					}
				} else {
					cur = -cur - b[n - 1 - i];
					for (int j = i + 1; j < n; j++){
						if (s[j] == '?')
							s[j] = '9';
						if (t[j] == '?')
							t[j] = '0';
					}
				}
				upd(ans, cur, s, t);
				break;
			}
		}
	}

	if (s == t){
		ans = {0, {s, t}};
	}

	cout << ans.second.first << " " << ans.second.second << "\n";
}

int main(){

	int T = nxt();
	for (int i = 0; i < T; i++){
		solve(i + 1);
		cerr << "Test #" << i + 1 << " is complete\n";
	}

	return 0;
}