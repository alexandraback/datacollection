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

const int MAXN = 105;

int t;
int n;
string s[MAXN];
int ans = 0;
vector <char> let;
vector <int> num[MAXN];
bool bad;

int main() {
	//assert(freopen("input.txt","r",stdin));
	//assert(freopen("output.txt","w",stdout));

	scanf("%d", &t);

	for (int test = 1; test <= t; test++) {
		ans = 0;
		let.clear();
		bad = false;

		scanf("%d\n", &n);	
		for (int i = 1; i <= n; i++) {
			getline(cin, s[i]);
		}
		for (int i = 1; i <= n; i++) {
			num[i].clear();
		}

		for (int i = 0; i < (int) s[1].length(); i++) {
			if (let.empty() || s[1][i] != let.back()) {
				let.push_back(s[1][i]);
				num[1].push_back(1);
			}	
			else {
				num[1][ (int) num[1].size() - 1 ]++;
			}
		}

		for (int i = 2; i <= n; i++) {
			int cur = 0;
			int curnum = 0;
			for (int j = 0; j < (int) s[i].length(); j++) {	
				if (s[i][j] == let[cur]) {
					curnum++;	
				}	
				else {
					if (curnum != 0) {
						num[i].push_back(curnum);
						cur++;
						curnum = 1;
					}	
					else {
						bad = true;
					}
					if (cur >= (int) let.size() || s[i][j] != let[cur]) {
						bad = true;
						break;
					}
				}
			}	
			if (curnum != 0) {
				num[i].push_back(curnum);
				cur++;
			}
			else
				bad = true;
			if (cur < (int) let.size())
				bad = true;
		}

		if (bad) {
			printf("Case #%d: Fegla Won\n", test);
			continue;
		}

		for (int i = 0; i < (int) let.size(); i++) {
			int add = 1000 * 1000 * 1000;
			for (int j = 1; j <= 100; j++) {
				int cur = 0;
				for (int k = 1; k <= n; k++) {
					cur += abs(num[k][i] - j);
				}	
				if (cur < add)
					add = cur;
			}	
			ans += add;
		}

		printf("Case #%d: %d\n", test, ans);	
	}

	return 0;
}