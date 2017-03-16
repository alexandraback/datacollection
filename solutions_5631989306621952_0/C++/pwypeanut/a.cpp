#include <bits/stdc++.h>
using namespace std;

int TC;

bool cmp(pair<char, int> a, pair<char, int> b) {
	if (a.first != b.first) return a.first > b.first;
	else return a.second > b.second;
}

bool cmp2(pair<char, int> a, pair<char, int> b) {
	return a.second < b.second;
}

int main() {
	scanf("%d", &TC);
	for (int tc = 1; tc <= TC; tc++) {
		string S;
		cin >> S;
		vector< pair<char, int> > V;
		for (int i = 0; i < S.length(); i++) V.push_back(make_pair(S[i], i));
		sort(V.begin(), V.end(), cmp);
		string ans = "";
		bool used[1005];
		memset(used, 0, sizeof(used));
		int last = 1000000000;
		for (int i = 0; i < V.size(); i++) {
			if (V[i].second < last) {
				last = V[i].second;
				ans += V[i].first;
				used[i] = 1;
			}
		}
		vector< pair<char, int> > newv;
		for (int i = 0; i < V.size(); i++) if (!used[i]) newv.push_back(V[i]);
		sort(newv.begin(), newv.end(), cmp2);
		for (int i = 0; i < newv.size(); i++) ans += newv[i].first;
		printf("Case #%d: %s\n", tc, ans.c_str());
	}
}
