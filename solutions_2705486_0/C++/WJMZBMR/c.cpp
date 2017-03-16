/*
 * [JSOI2007]文本生成器.cpp
 *
 *  Created on: 2011-3-15
 *      Author: user
 */

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <fstream>
#include <vector>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
using namespace std;

const int MAX_N_ALPHABET = 26;
const int MAX_NODES = 1200000;

struct Trie;
vector<Trie*> all;

struct Trie {
	Trie*ch[MAX_N_ALPHABET];
	int id;
	bool end;
	Trie() {
		id = all.size();
		end = false;
		all.push_back(this);
		memset(ch, 0, sizeof ch);
	}
	Trie*getCh(char what) {
		int which = what - 'a';
		if (ch[which] != 0)
			return ch[which];
		ch[which] = new Trie;
		return ch[which];
	}
};

Trie*root;
const int INF = ~0U >> 2;
int nId;

int dp[5][MAX_NODES];

void update(char c) {
	int w = c - 'a';
	static int nxt[5][MAX_NODES];
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < nId; ++j) {
			nxt[i][j] = INF;
		}
	}

	for (int i = 0; i < 5; ++i) {
		for (int j = nId - 1; j >= 0; --j) {
			Trie*t = all[j];
			int c = dp[i][j];
			if (c == INF)
				continue;
			Trie*nt = t->ch[w];
			if (nt != 0) {
				nxt[max(i - 1, 0)][nt->id] = min(nxt[max(i - 1, 0)][nt->id], c);
			}

			if (i == 0) {
				for (int nw = 0; nw < MAX_N_ALPHABET; ++nw) {
					if (t->ch[nw]) {
						nt = t->ch[nw];
						nxt[4][nt->id] = min(nxt[4][nt->id], c + 1);
					}
				}
			}
		}
	}

	for (int i = 0; i < 5; ++i) {
		for (int j = nId - 1; j >= 1; --j) {
			Trie*t = all[j];
			int c = nxt[i][j];
			if (c == INF)
				continue;
			if (t->end)
				nxt[i][root->id] = min(nxt[i][root->id], c);
		}
	}

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < nId; ++j) {
//			nxt[i][j] = INF;
			dp[i][j] = nxt[i][j];
		}
	}
}

int work() {
	string s;
	cin >> s;
	nId = all.size();
//	cerr << nId << " " << MAX_NODES << endl;

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < nId; ++j) {
			dp[i][j] = INF;
		}
	}
	dp[0][root->id] = 0;

	for (int i = 0; i < s.size(); ++i) {
		update(s[i]);
	}

	int ans = INF;
	for (int i = 0; i < 5; ++i) {
		ans = min(ans, dp[i][root->id]);
	}
	return ans;
}

int main() {
	fstream fin("garbled_email_dictionary.txt");
	string s;

	root = new Trie;
	while (fin >> s) {
		Trie*t = root;
		for (int j = 0; j < s.length(); ++j) {
			t = t->getCh(s[j]);
		}
		t->end = true;
	}
//	cerr << Trie::numId << endl;
//	build();
	int T;
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		printf("Case #%d: %d\n", i, work());
	}
}
