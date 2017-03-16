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

	string unique = "ZXWGHUSVON";
	string dg[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

	string s;
	cin >> s;
	vector<int> cnt(26);
	for (auto c : s)
		cnt[c - 'A']++;

	vector<int> res;
	vector<char> used(10);
	for (auto c : unique){
		int i = 0;
		while (used[i] || dg[i].find(c) == string::npos)
			i++;
		used[i] = 1;
		while (cnt[c - 'A']){
			for (auto d : dg[i])
				cnt[d - 'A']--;
			res.push_back(i);
		}
	}
	sort(all(res));
	for (auto x : res)
		cout << x;
	cout << "\n";
}

int main(){

	int T = nxt();
	for (int i = 0; i < T; i++){
		solve(i + 1);
		cerr << "Test #" << i + 1 << " is complete\n";
	}

	return 0;
}