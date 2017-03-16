#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <bitset>
#include <deque>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
using namespace std;

typedef long long ll;

char s[2001];
int n;
map<char, int>freq;
vector<int> sol;

int main(int argc, char **argv) {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%s", s);
		n = strlen(s);
		freq.clear();
		for (int i = 0; i < n; ++i)
			++freq[s[i]];
		sol.clear();
		while (freq['Z'] != 0) { // 0
			--freq['Z'];
			--freq['E'];
			--freq['R'];
			--freq['O'];
			sol.push_back(0);
		}
		while (freq['W'] != 0) { // 2
			--freq['T'];
			--freq['W'];
			--freq['O'];
			sol.push_back(2);
		}
		while (freq['U'] != 0) { // 4
			--freq['F'];
			--freq['O'];
			--freq['U'];
			--freq['R'];
			sol.push_back(4);
		}
		while (freq['F'] != 0) { // 5
			--freq['F'];
			--freq['I'];
			--freq['V'];
			--freq['E'];
			sol.push_back(5);
		}
		while (freq['X'] != 0) { // 6
			--freq['S'];
			--freq['I'];
			--freq['X'];
			sol.push_back(6);
		}
		while (freq['V']) { // 7
			--freq['S'];
			--freq['E'];
			--freq['V'];
			--freq['E'];
			--freq['N'];
			sol.push_back(7);
		}
		while (freq['G'] != 0) { // 8
			--freq['E'];
			--freq['I'];
			--freq['G']; 
			--freq['H'];
			--freq['T'];
			sol.push_back(8);
		}
		while (freq['O'] != 0) { // 1
			--freq['O'];
			--freq['N'];
			--freq['E'];
			sol.push_back(1);
		}
		while (freq['T'] != 0) { // 3
			--freq['T'];
			--freq['H'];
			--freq['R'];
			--freq['E'];
			--freq['E'];
			sol.push_back(3);
		}
		while (freq['I'] != 0) { // 9
			--freq['N'];
			--freq['I'];
			--freq['N'];
			--freq['E'];
			sol.push_back(9);
		}
		sort(sol.begin(), sol.end());
		string s = "";
		for (int i = 0; i < sol.size(); ++i)
			s += char(sol[i] + '0');
		static int cas = 1;
		printf("Case #%d: %s\n", cas++, s.c_str());
	}
	return 0;
}