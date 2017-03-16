#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
using namespace std;

struct node {
	int value;
	node* next[26];
	bool fin;
};

vector<string> dic;
string s;
node* root = NULL;
int nNode = 1;
node* linkToNode[1200000];
int f[4004][6];

void build(string s) {
	node* p = root;
	for (int i = 0; i < s.size(); i++) {
		node* q;
		int x = s[i] - 'a';
		if (p->next[x] == NULL) {
			q = new node;
			q->value = nNode;
			linkToNode[nNode] = q;
			for (int c = 0; c < 26; c++) q->next[c] = NULL;
			p->next[x] = q;
			nNode++;
		} else {
			q = p->next[x];
		}
		p = q;
		if (i == s.size() - 1) p->fin = true;
	}
}

void dp(int i, int j, node* p, int ci, int cj, int cc) { //start from i, allow to change in j letters
	//cout << i << " " << j << " " << p << " " << ci << " " << cj << " " << cc << endl;
	if (p == NULL) return;
	if (p->fin) {
		if (f[i][j] == -1 || (f[i][j] > f[ci][cj] + cc))
			if (f[ci][cj] != -1)
				f[i][j] = f[ci][cj] + cc;
	}
	if (ci >= s.size()) return;
	int c = s[ci] - 'a';
	if (p->next[c] != NULL) {
		dp(i, j, p->next[c], ci + 1, max(cj - 1, 0), cc); // no changes, go on
	}
	if (cj == 0) { //do changes
		for (c = 0; c < 26; c++) if (p->next[c] != NULL && s[ci] - 'a' != c) {
			dp(i, j, p->next[c], ci + 1, 4, cc + 1);
		}
	}
}

int process() {
	memset(f, -1, sizeof(f));
	for (int j = 0; j <= 5; j++) f[s.size()][j] = 0;
	int res = 1000000000;
	for (int i = s.size() - 1; i >= 0; i--) {
		for (int j = 0; j <= 5; j++) {
			dp(i, j, root, i, j, 0);
			//cout << i << " " << j << " " << f[i][j] << endl;
			if (i == 0 && f[i][j] != -1 && f[i][j] < res) res = f[i][j];
		}
	}
	return res;
}



int main() {
	root = new node;
	root->value = 0;
	for (int c = 0; c < 26; c++) root->next[c] = NULL;
	root->fin = false;

	for (int i = 0; i < 1200000; i++) linkToNode[i] = NULL;
	linkToNode[0] = root;

	int maxL = 0;
	ifstream f("garbled_email_dictionary.txt");
	for (int i = 0; i < 521196; i++) {
		f >> s;
		dic.push_back(s);
		if (s.size() > maxL) maxL = s.size();
		build(s);
	}
	f.close();

	//cout << maxL << endl;
	//cout << nNode << endl;

	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);
	int ntest;
	cin >> ntest;

	for (int itest = 0; itest < ntest; itest++) {
		cin >> s;
		cout << "Case #" << itest+1 << ": " << process() << endl;
	}

}
