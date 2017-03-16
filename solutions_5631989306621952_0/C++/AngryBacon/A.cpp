#include <cmath>
#include <cstdio>
#include <cctype>
#include <climits>
#include <cstring>
#include <vector>
#include <string>
#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

void solve()
{
	string s;
	cin >> s;
	string s1, s2;
	int n = s.size();
	int ptr = n;
	for(int c = 25; c >= 0; -- c) {
		int flag = false;
		int st = -1;
		for(int i = 0; i < ptr; ++ i) {
			if (s[i] == c + 'A') {
				if (flag == false) {
					st = i;
					flag = true;
				}
			}
		}
		if (flag) {
			for(int i = ptr - 1; i >= st; -- i) {
				if (s[i] == c + 'A') {
					s1 += s[i];
				} else {
					s2 += s[i];
				}
			}
			ptr = st;
		}
	}
	reverse(s2.begin(), s2.end());
	cout << s1 + s2 << endl;
}

int main()
{
	freopen("A-small-attempt0.in", "r", stdin); freopen("A-small-attempt0.out", "w", stdout);
	//freopen("A-small-attempt1.in", "r", stdin); freopen("A-small-attempt1.out", "w", stdout);
	//freopen("A-small-attempt2.in", "r", stdin); freopen("A-small-attempt2.out", "w", stdout);
	//freopen("A-large.in", "r", stdin); freopen("A-large.out", "w", stdout);
	int test_case;
	cin >> test_case;
	for(int i = 0; i < test_case; ++ i) {
		printf("Case #%d: ", i + 1);
		cerr << "Start: " << i << endl;
		solve();
	}
	return 0;
}
