#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <stdint.h>
#include <bitset>
#include <cmath>

#define INPUTFILE "c.in"
#define OUTPUTFILE "c.out"


using namespace std;


int J, P, S, K;
int C = 0;
int _ans;

int cur[64];
int ans[64];

struct ss {
	int j, p, s;
} sss[64];

void gen()
{
	C = 0;
	for (int j=1;j<=J;++j) {
		for (int p=1;p<=P;++p) {
			for (int s=1;s<=S;++s) {
				sss[C++] = {j,p,s};
			}
		}
	}
}

int check2(ss o, int s, int len)
{
	int cnt = 0;
	for (int j=s;j<len;++j) {
		int match = 0;
		if (o.j == sss[cur[j]].j) match ++;
		if (o.p == sss[cur[j]].p) match ++;
		if (o.s == sss[cur[j]].s) match ++;
		if (match >= 2) {
			cnt ++;
		}
	}
	return cnt;
}

bool check(int l) {
	for (int i=0;i<l;++i) {
		ss t;
		t = sss[cur[i]]; t.j = -1;
		if (check2(t, i+1, l) >= K) return false;
		t = sss[cur[i]]; t.p = -1;
		if (check2(t, i+1, l) >= K) return false;
		t = sss[cur[i]]; t.s = -1;
		if (check2(t, i+1, l) >= K) return false;
	}
	return true;
}

void dfs(int x, int l)
{
	if (l + C - x < _ans ) return;
	if (x >= C) {
		if (l > _ans) {
			for (int i=0;i<l;++i) {
				ans[i] = cur[i];
			}
			_ans = l;
		}
		return;
	}
	cur[l] = x;
	if (check(l+1)) {
		dfs(x+1, l+1);
	}
	dfs(x+1, l);
}

void solve_one() {
	cin >> J >> P >> S >> K;
	_ans= 0;
	dfs(0, 0);
	cout << _ans << endl;
	for (int i=0;i<_ans;++i) {
		cout  << sss[ans[i]].j <<  " " <<sss[ans[i]].p << " "<< sss[ans[i]].s << endl;
	}
}


int main()
{
	int T, cases = 0;
	string dummy;

	freopen(INPUTFILE,"r",stdin);
	freopen(OUTPUTFILE,"w",stdout);

	cin >> T;

	getline(cin, dummy);

	while (T--) {

		cout << "case #" << ++cases << ": ";

		solve_one();

//		cout << endl;
	}

	return 0;
}

