// c Hewr
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
using namespace std;
#define clr(a,x) memset(&a, x, sizeof(a))
#define SIZE(a) ((int) (a).size())
#define MP make_pair
#define fi first
#define se second

const int mc = 26, mn = 4000000;

struct Node {
	int ch[mc];
	bool flag;
	Node(){
		clr(ch, 0);
		flag = 0;
	}
} T[mn];
int tt;

void prepareDictionary() {
	tt = 1;
	ifstream fin("dic.txt");
	string S;
	while (getline(fin, S)) {
		if (S == "") break;
		int x = 1;
		for (int i = 0; i < SIZE(S); ++i) {
			int t = S[i] - 'a';
			if (!T[x].ch[t]) 
				T[x].ch[t] = ++tt;
			x = T[x].ch[t];
		}
		T[x].flag = 1;
	}
}

const int ml = 4100, GAP = 5;
int a[ml];
int n, Ans, oo;
int f[ml][GAP + 1];

void dfs(int p, int len, int cd, int now) {
	if (T[p].flag) {
		f[len][cd] = min(f[len][cd], now);
	}
	if (len >= n) return;

	if (T[p].ch[a[len + 1]]) {
		dfs(T[p].ch[a[len + 1]], len + 1, max(cd - 1, 0), now);
	}
	if (!cd) {
		for (int i = 0; i < mc; ++i) if (T[p].ch[i]){
			dfs(T[p].ch[i], len + 1, GAP - 1, now + 1);
		}
	}
}

void work() {
	clr(f, 60), f[0][0] = 0;
	oo = f[0][1];
	for (int len = 0; len < n; ++len) for (int cd = 0; cd <= GAP; ++cd) if (f[len][cd] != oo){
		dfs(1, len, cd, f[len][cd]);
	}
	Ans = oo;
	for (int cd = 0; cd <= GAP; ++cd) Ans = min(Ans, f[n][cd]);
}

int main() {
	prepareDictionary();
	ifstream fin("c.in");
	int CA;
	fin >> CA;
	for (int Ca = 1; Ca <= CA; ++Ca) {
		string ori;
		do { getline(fin, ori); } while (ori == "");
		n = SIZE(ori);
		for (int i = 1; i <= n; ++i) a[i] = ori[i - 1] - 'a';
		work();
		cout << "Case #" << Ca << ": " << Ans << endl;
	}
}
