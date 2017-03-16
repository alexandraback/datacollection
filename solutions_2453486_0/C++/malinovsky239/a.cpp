#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <complex>
#include <cstdio>
#include <vector>
#include <cctype>
#include <string>
#include <ctime>
#include <cmath>
#include <set>
#include <map>

typedef long double LD;
typedef long long LL;

using namespace std;

#define sz(A) (int)(A).size()
#define mp make_pair
#define pb push_back

string ans[] = {"Draw", "X won", "O won"};
char t[4][4];

int main() {
	int tst;
	cin >> tst;

	for (int i = 0; i < tst; i++) {
		bool draw = 0;

		for (int j = 0; j < 4; j++)
			for (int k = 0; k < 4; k++) {
				cin >> t[j][k];
				if (t[j][k] == '.')
					draw = 1;
			}		

		int win = 0;

		for (int j = 0; j < 4; j++) {
			int c1 = 0, c2 = 0;
			for (int k = 0; k < 4; k++) {
				if (t[j][k] == 'X' || t[j][k] == 'T') 
					c1++;
				if (t[j][k] == 'O' || t[j][k] == 'T') 				
					c2++;
			}
			if (c1 == 4) 
				win = 1;
			if (c2 == 4) 
				win = 2;
		}

		for (int j = 0; j < 4; j++) {
			int c1 = 0, c2 = 0;
			for (int k = 0; k < 4; k++) {
				if (t[k][j] == 'X' || t[k][j] == 'T') 
					c1++;
				if (t[k][j] == 'O' || t[k][j] == 'T') 				
					c2++;
			}
			if (c1 == 4) 
				win = 1;
			if (c2 == 4)
				win = 2;
		}

		int c1 = 0, c2 = 0;
		for (int j = 0; j < 4; j++) {
			if (t[j][j] == 'X' || t[j][j] == 'T') 
				c1++;
			if (t[j][j] == 'O' || t[j][j] == 'T') 				
				c2++;
		}

		if (c1 == 4)
			win = 1;
		if (c2 == 4)
			win = 2;

		c1 = c2 = 0;

		for (int j = 0; j < 4; j++) {
			if (t[j][4 - j - 1] == 'X' || t[j][4 - j - 1] == 'T') 
				c1++;
			if (t[j][4 - j - 1] == 'O' || t[j][4 - j - 1] == 'T') 				
				c2++;
		}		

		if (c1 == 4)
			win = 1;
		if (c2 == 4)
			win = 2;

		if (draw && win == 0) {
			printf("Case #%d: Game has not completed\n", i + 1);
			continue;
		}

		printf("Case #%d: %s\n", i + 1, ans[win].c_str());
	}

	return 0;
}

