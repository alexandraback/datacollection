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
#define ii pair<int,int>
#define INF 1000000000
using namespace std;
int main() {
	freopen("output.txt", "w", stdout);
	int t, l;
	cin >> t;
	for (l = 0; l < t; l++) {
		string s;
		cin >> s;
		int i = 0, ans = 0;
		while (i < s.size()) {
			if (s[i] == '+' && i < s.size() - 1 && s[i + 1] == '-') {
				ans += 2;
				i++;
				while (s[i] == '-')
					i++;
			} else if (s[i] == '+') {
				while ((i < s.size() - 1 && s[i + 1] == '+')
						|| (i == s.size() - 1 && s[i] == '+'))
					i++;
			} else {
				ans++;
				while (i < s.size() && s[i] == '-')
					i++;
			}
		}
		cout << "Case #" << l + 1 << ": " << ans << endl;
	}
	return 0;
}
