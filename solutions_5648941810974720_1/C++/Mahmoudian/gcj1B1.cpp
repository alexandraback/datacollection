// In the name of God

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; ++i)

const int N = 0, mod = 0;

string a[] = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };

ifstream fin("A-large.in");
#define cin fin
ofstream fout("outp.out");
#define cout fout

int find(string s) {
	rep(i, 10) if (s == a[i])
		return i;
}

int num[1 << 9];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	rep(it, tc) {
		cout << "Case #" << it + 1 << ": ";
		string t; cin >> t;
		memset(num, 0, sizeof num);
		for (auto c : t)
			num[c]++;
		string res = "";
		set<string> st;
		rep(i, 10) st.insert(a[i]);
		rep(i, 10) {
			int id = -1;
			for (auto s : st) {
				if (id != -1)
					break;
				for (auto c : s) { 
					int flag = 1;
					for (auto x : st) if (x != s) {
						for (auto ch : x) if (c == ch)
							flag = 0;
					}
					if (flag) {
	//					cout << s << endl;
						int cnt = 0;
						for (auto ch : s)
							if (ch == c)
								cnt++;
	//					cout << cnt << endl;
						int seen = num[c] / cnt;
						char p = find(s) + '0';
	//					cout << seen << endl;
						rep(i, seen)
							res += p;
						for (auto ch : s)
							num[ch] -= seen;
						id = find(s);
						break;
					}
				}
			}
			st.erase(a[id]);
		}
		sort(res.begin(), res.end());
		cout << res << endl;
	}
	return 0;
}







