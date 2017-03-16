#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include<functional>
#include <fstream>
#include <iomanip>
#define ii pair<int,int>
#define INF 1000000000
using namespace std;
int ans1, ans2;
string s1, s2;
bool valid(string s,int x) {
	string st;
	while (x > 0) {
		st += x % 10 + '0';
		x /= 10;
	}
	while (st.size() < s.size()) {
		st += '0';
	}
	if (st.size() != s.size())
		return false;
	else {
		for (int i = 0; i < st.size(); i++) {
			if (st[st.size() - 1 - i] != s[i] && s[i] != '?')
				return false;
		}
		return true;
	}
}

int main()
{
	freopen("outputBSMALL.txt","w",stdout);
	int n;
	cin >> n;
	for (int l = 0; l < n; l++) {
		int min = INF;
		ans1 = ans2 = 0;
		cin >> s1 >> s2;
		cout << "Case #" << l + 1 << ": ";
		for (int i = 0; i < 1000; i++) {
			if (valid(s1, i)) {
				for (int j = 0; j < 1000; j++) {
					if (valid(s2, j) && abs(i - j) < min ) {
						min = abs(i - j);
						ans1 = i;
						ans2 = j;
					}
				}
			}
		}
		int cnt = 0,x = ans1;
		if (ans1 == 0)	cnt++;
		while (x > 0) {
			x /= 10;
			cnt++;
		}
		while (cnt < s1.size()) {
			cout << 0;
			cnt++;
		}
		cout << ans1 << ' ';
		cnt = 0, x = ans2;
		if (ans2 == 0)	cnt++;
		while (x > 0) {
			x /= 10;
			cnt++;
		}
		while (cnt < s1.size()) {
			cout << 0;
			cnt++;
		}
		cout << ans2 << endl;
	}
	return 0;
}
