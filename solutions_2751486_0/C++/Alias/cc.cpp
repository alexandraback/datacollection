#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <ctime>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <math.h>
#include <queue>
#include <memory.h>
#include <iostream>
#include <stack>
#include <complex>
#include <list>

using namespace std;
 
void ASS(bool b)
{
    if (!b)
    {
        ++*(int*)0;
    }
}
 
#define FOR(i, x) for (int i = 0; i < (int)(x); ++i)
#define CL(x) memset(x, 0, sizeof(x))
#define CLX(x, y) memset(x, y, sizeof(x))
 
#pragma comment(linker, "/STACK:106777216")
 
typedef vector<int> vi;
typedef long long LL;

char w[256];

const int N = 1 << 20;


LL Solve() {
	string s;
	cin >> s;
	int n;
	cin >> n;
	vector< pair<int, int> > v;
	{
		int pos = 0;
		while (pos < (int)s.size()) {
			while (pos < (int)s.size() && w[s[pos]])
				pos++;
			pair<int, int> p;
			p.first = pos;
			while (pos < (int)s.size() && !w[s[pos]])
				pos++;
			p.second = pos;
			if (p.first != p.second)
				v.push_back(p);
		}
	}
	int R = 0;
	vi st;
	st.push_back(0);
	int vL = 0;
	int vR = 0;
	LL res = 0;
	FOR(L, s.size()) {
		while (vL < (int)v.size() && v[vL].second <= L) {
			vL++;
		}
		if (vL < (int)v.size() && v[vL].first == L) {
			if (st.back() == v[vL].second - v[vL].first)
				st.pop_back();
		}
		int cur = 0;
		while (1) {
			if (vL < (int)v.size() && v[vL].first <= L)
				cur = max(cur, min(R, v[vL].second) - L);
			cur = max(cur, st.back());
			if (vR < (int)v.size() && v[vR].first < R)
				cur = max(cur, R - max(v[vR].first, L));
			if (cur < n || R < L + 1) {
				R++;
				if (R == (int)s.size() + 1)
					return res;
				while (vR < (int)v.size() && v[vR].second <= R) {
					if (vR < (int)v.size() && L < v[vR].first && v[vR].second == R) {
						if (st.back() < v[vR].second - v[vR].first)
							st.push_back(v[vR].second - v[vR].first);
					}
					vR++;
				}
			}
			else {
				break;
			}
		}
		if (cur >= n)
			res += (int)s.size() + 1 - R;
	}
	return res;
}

int main()
{
	freopen("c:\\my\\in.txt", "r", stdin);
	freopen("c:\\my\\out.txt", "w", stdout);
	w['a'] = 1;
	w['e'] = 1;
	w['i'] = 1;
	w['o'] = 1;
	w['u'] = 1; 
	int n;
	cin >> n;
	FOR(i, n) {
		LL res = Solve();
		cout << "Case #" << (i + 1) << ": " << res << "\n";
	}

	return 0;
}