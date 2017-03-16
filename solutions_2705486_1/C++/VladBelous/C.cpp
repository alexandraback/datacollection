#include <vector>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <utility>

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

template<typename T>
inline int sz(const T& x) { return (int)x.size(); }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef long long int LL;



struct node {
	int idx;
	node* next[26];
};

node* new_node() {
	node* ret = new node;
	ret->idx = -1;
	for (int i = 0; i < 26; ++i)
		ret->next[i] = 0;
	return ret;
}

void add_word(node* root, string& w, int n, int idx) {
	if (n == sz(w)) {
		root->idx = idx;
	} else {
		int c = (int)(w[n] - 'a');
		if (!root->next[c])
			root->next[c] = new_node();
		add_word(root->next[c], w, n+1, idx);
	}
}


vector<pair<int,ii> > words;
void fill_words(node *root, int cur_idx, int fe_idx, int e_cnt, string& S) {
	if (!root)
		return;

	if (root->idx >= 0)
		words.push_back(pair<int,ii>(root->idx, ii(fe_idx, e_cnt)));

	if (cur_idx >= sz(S))
		return;

	int c = (int)(S[cur_idx] - 'a');
	for (int a = 0; a < 26; ++a) {
		if (a == c) {
			fill_words(root->next[a], cur_idx+1, fe_idx, e_cnt, S);
		} else if (cur_idx >= fe_idx) {
			fill_words(root->next[a], cur_idx+1, cur_idx+5, e_cnt+1, S);
		}
	}
}

vector<string> wd;
vvi dp;
int solve(string& S, node* trie, int cur_idx, int fe_dist) {
	if( dp[cur_idx][fe_dist] == -2 )
		return -2;
	if( dp[cur_idx][fe_dist] != 1000000 )
		return dp[cur_idx][fe_dist];

	if( cur_idx >= sz(S) )
		return dp[cur_idx][fe_dist] = 0;

	int ans = 1000000;

	words.clear();
	fill_words(trie, cur_idx, cur_idx + fe_dist, 0, S);
	vector<pair<int,ii> > wl = words;
	//for (int i = 0; i < sz(words); ++i)	cout << wd[words[i].first] << endl;
	for (int i = 0; i < sz(wl); ++i) {
		int w_idx  = wl[i].first;
		int fe_idx = wl[i].second.first;
		int e_cnt  = wl[i].second.second;

		int next_idx = cur_idx + sz(wd[w_idx]);
		int rem = solve(S, trie, next_idx, max(0, fe_idx - next_idx));
		if (rem >= 0 ) {
			ans = min(ans, e_cnt + rem);
		}
	}

	return dp[cur_idx][fe_dist] = ans;
}



int main() {
	wd.clear();
	ifstream ifsd("garbled_email_dictionary.txt");
	string w;
	while (ifsd >> w)
		wd.push_back(w);
	ifsd.close();
	/*
	cout << "Total words: " << sz(ws) << endl;
	vi lens(50,0);
	for (int i = 0; i < sz(ws); ++i) {
		int l = sz(ws[i]);
		if (l < 50)
			lens[l]++;
		else
			cout << "too long" << endl;
	}
	for (int i = 0; i < 15; ++i) {
		cout << i << ": " << lens[i] << endl;
	}
	*/

	/*
	for (int i = 0; i < 1000; ++i) {
		cout << wd[rand()%510000];
	} cout << endl;
	*/


	node* trie = new_node();
	for (int i = 0; i < sz(wd); ++i) {
		add_word(trie, wd[i], 0, i);
	}

	int tcn; cin >> tcn;

	for (int tc = 1; tc <= tcn; ++tc) {
		int ans = 0;

		string S; cin >> S;

		dp.clear();
		dp.resize( sz(S)+100, vi(10, 1000000));
		ans = solve(S, trie, 0, 0);

		cout << "Case #" << tc << ": " << ans << "\n";
	}

	return 0;
}
