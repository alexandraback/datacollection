#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt(){
	int x;
	scanf("%d", &x);
	return x;
}

void solve(int test){
	printf("Case #%d: ", test);

	int n = nxt();
	vector<pair<string, string>> a(n);
	map<string, int> fi, se;
	for (int i = 0; i < n; i++){
		string s, t;
		cin >> s >> t;
		fi[s] += 1;
		se[t] += 1;
		a[i] = {s, t};
	}

	int N = 1 << n;
	int ans = 0;
	for (int mask = 0; mask < N; mask++){
		map<string, int> fo, la;
		bool ok = true;
		for (int i = 0; i < n; i++){
			if (mask & (1 << i)){
				fo[a[i].first] += 1;
				la[a[i].second] += 1;
				if (fo[a[i].first] == fi[a[i].first] ||
					la[a[i].second] == se[a[i].second])
					ok = false;
			}
		}
		if (ok){
			ans = max(ans, __builtin_popcount(mask));
		}
	}

	cout << ans << "\n";
}

int main(){

	int T = nxt();
	for (int i = 0; i < T; i++){
		solve(i + 1);
		cerr << "Test #" << i + 1 << " is complete\n";
	}

	return 0;
}