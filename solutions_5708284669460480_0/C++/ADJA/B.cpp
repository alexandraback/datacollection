#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
#include <cassert>
#include <utility>
#include <iomanip>

using namespace std;

const int MAXN = 205;

struct node {
	int suff_link, par;
	char c;
	map < char, int > go;
	bool is_word;   

	node() {
		suff_link = -1, par = -1;
		is_word = false;
	}
};

vector <node> trie;
double dp[MAXN][MAXN][MAXN];
bool used[MAXN][MAXN][MAXN];

void trieInsert(char s[MAXN]) {
	int cur_node = 0;
	int len = strlen(s);
	for (int i = 0; i < len; i++) {
		int go = trie[cur_node].go[s[i]];
		if (go == 0) {
			node add;
			add.par = cur_node; add.c = s[i];
			trie.push_back(add);
			go = (int) trie.size() - 1;
			trie[cur_node].go[s[i]] = go;
		}
		cur_node = go;
	}   
	trie[cur_node].is_word = true;
}

int go(int cur_node, char c);

int getSuffLink(int cur_node) {
	if (trie[cur_node].suff_link != -1)
		return trie[cur_node].suff_link;
	if (trie[cur_node].par == 0) 
		return trie[cur_node].suff_link = 0;
	char c = trie[cur_node].c;
	int parent = trie[cur_node].par;
	return trie[cur_node].suff_link = go(trie[parent].suff_link, c); 
}

int go(int cur_node, char c) {
	if (trie[cur_node].go.count(c) > 0)
		return trie[cur_node].go[c];
	if (cur_node == 0)
		return trie[cur_node].go[c] = 0;
	int suff_link = getSuffLink(cur_node);
	return trie[cur_node].go[c] = go(suff_link, c);
}

void buildAhoCorasick() {
	queue <int> q;
	q.push(0);
	while (!q.empty()) {
		int cur_node = q.front();
		q.pop();

		for (map <char, int> :: iterator it = trie[cur_node].go.begin(); it != trie[cur_node].go.end(); it++) {
			q.push(it->second);
		}

		int suff_link = getSuffLink(cur_node);
		trie[cur_node].suff_link = suff_link;
		if (trie[suff_link].is_word)
			trie[cur_node].is_word = true;
	}
}

int tn;
int n, m, len;
char a[MAXN];
char b[MAXN];
double p[10 * MAXN];
int mx = 0;
int nn;
double ans = 0.0;

int main() {

	scanf("%d", &tn);

	for (int test = 1; test <= tn; test++) {
		scanf("%d %d %d\n", &n, &m, &len);
		
		gets(a);
		for (char c = 'A'; c <= 'Z'; c++)
			p[(int) c] = 0.0;
		for (int i = 0; i < n; i++)
			p[(int) a[i]] += 1.0 / n;

		trie.clear();
		node root;
		root.suff_link = 0;
		trie.push_back(root);
			
		gets(b);
		trieInsert(b);

		buildAhoCorasick();

		memset(dp, 0, sizeof(dp));
		memset(used, 0, sizeof(used));

		nn = (int) trie.size();
		dp[0][0][0] = 1.0;
		used[0][0][0] = true;

		mx = 0;
		ans = 0.0;

		for (int i = 0; i <= len; i++) {
			for (int j = 0; j < nn; j++) {
				for (int k = 0; k <= len; k++) {
					if (!used[i][j][k])
						continue;
					//printf("%d %d %d\n", i, j, k);
					if (k > mx)
						mx = k;
					double curp = dp[i][j][k];
					if (i == len) {
						ans += curp * k;
					}
					for (int c = 'A'; c <= 'Z'; c++) {
						if (p[c] <= 1e-6)
							continue;
						int goV = go(j, c);
						int add = 0;
						if (trie[goV].is_word) {
							add++;
						}
						used[i + 1][goV][k + add] = true;
						dp[i + 1][goV][k + add] += curp * p[(int) c];
					}			
				}	
			}
		}

		printf("Case #%d: %.12lf\n", test, 1.0 * mx - ans);
		//printf("MX: %d\n", mx); 
	}

	return 0;
}