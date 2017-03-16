#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <cstring>
using namespace std;

const int MOD = 1000000007, N_ALP = 26, N_FACT = 1000;

vector<string> car;
vector<int> G[N_ALP];
int FORB[N_ALP], SINGLE[N_ALP], FACT[N_FACT] = {1, 1}, IN[N_ALP], VIS[N_ALP];

void remove_rep(string &s) {
	s = s.substr(0, unique(s.begin(),s.end())-s.begin());
}

bool dfs(int x) {
	if(VIS[x] == 1) return false;
	VIS[x] = 1;
	if(!G[x].empty()) return dfs(G[x][0]);
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	for(int i = 2; i < N_FACT; ++i) FACT[i] = (long long)FACT[i-1]*i%MOD;
	int T, N, res, cc;
	string s;

	cin >> T;
	for(int cs = 1; cs <= T; ++cs) {
		memset(SINGLE, 0, sizeof(SINGLE));
		memset(FORB, 0, sizeof(FORB));
		memset(IN, 0, sizeof(IN));
		memset(VIS, 0, sizeof(VIS));
		car.clear();
		for(int i = 0; i < N_ALP; ++i) G[i].clear();

		res = 0;

		cin >> N;
		for(int i = 0; i < N; ++i) {
			cin >> s;
			remove_rep(s);
			int l = s.size();
			if(l == 1) {
				SINGLE[s[0]-'a']++;
				continue;
			}
			for(int i = 1; i < l-1; ++i) FORB[s[i]-'a'] = 1;
			car.push_back(s);
		}
		for(int i = 0; i < car.size(); ++i) {
			int first = car[i][0]-'a';
			int last = car[i][car[i].size()-1]-'a';
			if(FORB[first] || FORB[last]) {
				goto C;
			}
			G[first].push_back(last);
			IN[last]++;
		}
		for(int i = 0; i < N_ALP; ++i) if(G[i].size() > 1 || IN[i] > 1) { goto C; } 

		cc = 0;
		for(int i = 0; i < car.size(); ++i) {
			int first = car[i][0]-'a';
			if(IN[first] == 0) {
				if(!G[first].empty() && !dfs(first)) goto C;
				cc++;
			}
		}
		for(int i = 0; i < N_ALP; ++i) if(IN[i] && !VIS[i]) goto C;
		res = FACT[cc];
		for(int i = 0; i < N_ALP; ++i) if(SINGLE[i]) {
			res = (long long)res * FACT[SINGLE[i]] % MOD;
			if(IN[i] == 0 && G[i].empty()) {
				res = (long long)res * (++cc) % MOD;
			}
		}
		
C:		cout << "Case #" << cs << ": " << res << endl;
	}
	return 0;
}