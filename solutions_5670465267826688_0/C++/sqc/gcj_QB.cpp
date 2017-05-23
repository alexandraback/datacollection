#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>

using namespace std;
int main() {
	//freopen("C-small-attempt0.in", "r", stdin);
	//freopen("C-small-attempt0.out", "w", stdout);
	//freopen("C-large.in", "r", stdin);
	//freopen("C-large.out", "w", stdout);
	int dp[4][4] = { {0, 1, 2, 3},
					 {1, 4, 3, 6},
					 {2, 7, 4, 1},
					 {3, 2, 5, 4},
					};
	int t;
	scanf("%d", &t);
	int l, x;
	string str;
	vector<int> s;
	vector<int> s1;
	vector<int> prefix;
	
	char ch;
	int tmpNum;
	int state;
	for (int i = 1; i <= t; i++) {
		scanf("%d %d\n", &l, &x);
		if (x >= 4) {
			x %= 4;
			x += 4;
		}
		if (x == 4) {
			cin >> str;
			printf("Case #%d: NO\n", i);
			continue;
		}
		
		s.resize(l);
		s1.resize(x * l);
		for (int j = 0; j < l; j++) {
			scanf("%c", &ch);
			if (ch == 'i') {
				tmpNum = 1;
			} else if (ch == 'j') {
				tmpNum = 2;
			} else if (ch == 'k') {
				tmpNum = 3;
			}
			s[j] = tmpNum;
		}
		scanf("%c", &ch);
		
		//s1.assign(s.begin(), s.end());
		int ind = 0;
		for (int j = 0; j < x; j++) {
			for (int k = 0; k < s.size(); k++) {				
				s1[ind] = s[k];
				ind++;
			}
		}
		
		prefix.resize(l * x);
		
		prefix[0] = s1[0];
		for (int j = 1; j < l *x; j++) {
			if (prefix[j - 1] < 4 && s1[j] < 4 || prefix[j - 1] >= 4 && s1[j] >= 4 ) {
				prefix[j] = dp[prefix[j - 1]][s1[j]];
			} else if (prefix[j - 1] >= 4) {
				prefix[j] = (dp[prefix[j - 1] - 4][s1[j]] + 4) % 8;
			} else {
				prefix[j] = (dp[prefix[j - 1]][s1[j] - 4] + 4) % 8;
			}
		}
		
		state = 0;
		for (int j = 0; j < l * x; j++) {
			if (state == 0) {
				if (prefix[j] == 1) {
					state = 1;
				} 
			} else if (state == 1) {
				if (prefix[j] == 3) {
					state = 2;
					break;
				}
			}
		}
		if (state == 2 && prefix[l * x - 1] == 4) {			
			printf("Case #%d: YES\n", i);
		} else {			
			printf("Case #%d: NO\n", i);
		}
	}
	return 0;
}
