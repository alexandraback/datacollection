#include <iostream>

#include <vector>
#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

#define ll long long
#define M 1000000007LL
string S[100];
int n;
bool vis[100];
vector<int> lft[26], rgt[26], mid[26], all[26];
bool good;
ll fct(ll a) {
	ll ans = 1;
	for (ll i = 2;i<=a;++i) {
		ans = (ans*i)%M;
	}
	return ans;
}
int as(char c) {
	return c-'a';
}
ll run(int c, int prev = -1) {
	if (vis[c]) return 0;
	vis[c] = true;
	if (mid[c].size() > 1) return 0;
	else if (mid[c].size() == 1) {
		if (all[c].size()>0 || lft[c].size()>0 || rgt[c].size()>0) {
			return 0;
		}
		return 1;
	}
	if (lft[c].size() > 1) return 0;
	if (rgt[c].size() > 1) return 0;
	if (rgt[c].size() == 1 && lft[c].size() == 1 && rgt[c][0] == lft[c][0]) return 0;
	ll ans = fct(all[c].size()); 
	if (rgt[c].size() == 1) {
		string s = S[rgt[c][0]];
		int blah = as(s[0]);
		if (blah != prev)
		ans = (ans * run(blah, c))%M;
	}
	if (lft[c].size() == 1) {
		string s = S[lft[c][0]];
		int blah = as(s[s.size()-1]);
		if (blah != prev)
		ans = (ans * run(blah, c))%M;
	}
	return ans%M;
}

int main() {
	int T;
	cin>>T;
	for (int t=1;t<=T;++t) {
		for (int i=0;i<26;++i) {
			lft[i].clear();
			rgt[i].clear();
			mid[i].clear();
			all[i].clear();
		}
		bool any[26];
		memset(any,0,sizeof(any));
		cin>>n;
		for (int i=0;i<n;++i)  cin>>S[i];
		vector<string> alt;
		//printf("%d\n", n);
		for (int i=0;i<n;++i) {
			string s = S[i];
			//printf("%s ", s.c_str());
			char b[24];
			sprintf(b, "%d", i);
			alt.push_back(s + b);
			vector<int> parts;
			parts.push_back(as(s[0]));
			any[as(s[0])] = true;
			for (int j=1;j<s.size();++j) {
				any[as(s[j])] = true;
				if (s[j] != s[j-1]) parts.push_back(as(s[j]));
			}
			if (parts.size() == 1) {
				all[parts[0]].push_back(i);
			} else {
				lft[parts[0]].push_back(i);
				rgt[parts[parts.size()-1]].push_back(i);
				for (int j=1;j<parts.size()-1;++j) {
					mid[parts[j]].push_back(i);
				}
			}
		}
		//printf("\n");


/*
		sort(alt.begin(), alt.end());
		ll altc = 0;
		do {
			bool seen[26];
			memset(seen, false, sizeof(seen));
			int prev = -1;
			bool good = true;
			string tog = "";
			for (int i=0;i<alt.size() && good;++i) {
				for (int j=0;j<alt[i].size() && good;++j) {
					int c = as(alt[i][j]);
					if (c < 0 || c >= 26) continue;
					if (c != prev) {
						prev = c;
						if (seen[c]) {
							good = false;
						}
						seen[c] = true;
					}
				}
			}
			if (good) ++altc;
		} while (next_permutation(alt.begin(), alt.end()));
		*/

		good = true;
		ll ans = 1;
		ll f = 0;
		memset(vis,0,sizeof(vis));
		for (int i=0;i<26;++i) {
			if ((!lft[i].empty() || !rgt[i].empty() || !all[i].empty()) && !vis[i]) {
				ans = (ans * run(i))%M;
				f++;
			}
		}
		while (f > 1) {
			ans = (ans*f) % M;
			--f;
		}
		/*
		if (altc != ans) {
			printf("Mismatch! %lld vs %lld\n", altc, ans);
		}*/
		printf("Case #%d: %lld\n", t, (ans%M));
	}
}
