#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <ctime>
#include <cctype>
#include <utility>

using namespace std;

string s[4];

int get () {
	int emptyCnt = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (s[i][j] == '.')
				emptyCnt++;
	for (int i = 0; i < 4; i++) {
		int xi = 0, yi = 0, yj = 0, xj = 0;
		for (int j = 0; j < 4; j++) {
			if (s[i][j] == 'X' || s[i][j] == 'T')
				xi++;
			if (s[j][i] == 'X' || s[j][i] == 'T')
				xj++;
			if (s[i][j] == 'O' || s[i][j] == 'T')
				yi++;
			if (s[j][i] == 'O' || s[j][i] == 'T')
				yj++;		
		}
		if (xi == 4 || xj == 4)
			return 1;
		if (yi == 4 || yj == 4)
			return 2;
	}

	int yd1 = 0, xd1 = 0, yd2 = 0, xd2 = 0;

	for (int i = 0; i < 4; i++) { 
		if (s[i][i] == 'X' || s[i][i] == 'T')
			xd1++;
		if (s[3-i][i] == 'X' || s[3-i][i] == 'T')
			xd2++;	
		if (s[i][i] == 'O' || s[i][i] == 'T')
			yd1++;
		if (s[3-i][i] == 'O' || s[3-i][i] == 'T')
			yd2++;	
	}            
	if (yd1 == 4 || yd2==4)
		return 2;
	if (xd1 == 4 || xd2==4)
		return 1;	

	if (emptyCnt)
		return 4;

	return 3;
}

int main () {
                                     
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int t, now = 0;
	cin >> t;
	while (t--) {
		for (int i = 0; i < 4; i++)
			cin >> s[i];
		string ln;
		getline(cin, ln);	 
		int res = get ();
		printf("Case #%d: ", ++now);               
		if (res == 1) {
			puts("X won");
		} else 
		if (res == 2) {
			puts("O won");
		} else 
		if (res == 3) {
			puts("Draw");
		} else 
			puts("Game has not completed");

	}
                             
	

	return 0;
}
