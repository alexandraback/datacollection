#include <iostream>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <stack>
#include <cstdio>
#include <cmath>
using namespace std;
char a[4][5], ans;
void check(char s, int i){
	int j;
	for (j = 0; j < 4; j++)
	{
		if (j == i)
			continue;
		if (a[i][j] != s && a[i][j] != 'T')
			break;
	}
	if (j == 4)
		ans = s;
	for (j = 0; j < 4; j++)
	{
		if (j == i)
			continue;
		if (a[j][i] != s && a[j][i] != 'T')
			break;
	}
	if (j == 4)
		ans = s;
}
int main(){
	int T, i, j;
	char s, del[2];
	cin >> T;
	for (int k = 1; k <= T; k++){
		ans = 'D';
		cin.getline(del, 2);
		for (i = 0; i < 4; i++)
			cin.getline(a[i] , 5);
		for (i = 0; i < 4; i++)
			for (j = 0; j < 4; j++)
				if (a[i][j] == '.')
					ans = '.';
		for (i = 0; i < 4; i++)
		{
			if (a[i][i] == 'X')
				check('X',i);
			else if (a[i][i] == 'O')
				check('O',i);
			else if (a[i][i] == 'T')
			{
				check('X',i);
				check('O',i);
			}
		}
		s = a[0][0];
		i = 0;
		if (s == 'T')
			s = a[1][1];
		if (s == 'X' || s == 'O')
		{
			for (i = 1; i < 4; i++)
				if (a[i][i] != s && a[i][i] != 'T')
					break;
		}
		if (i == 4)
			ans = s;
		s = a[0][3];
		i = 0;
		if (s == 'T')
			s = a[1][2];
		if (s == 'X' || s == 'O')
		{
			for (i = 1; i < 4; i++)
				if (a[i][3 - i] != s && a[i][3 - i] != 'T')
					break;
		}
		if (i == 4)
			ans = s;
		if (ans == 'X' || ans == 'O')
			printf("Case #%d: %c won\n", k, ans);
		if (ans == '.')
			printf("Case #%d: Game has not completed\n", k);
		if (ans == 'D')
			printf("Case #%d: Draw\n", k);
	}
	return 0;
}
