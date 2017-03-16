#include <iostream>
#include <string.h>
#include <string>

using namespace std;

int T;
string s[4];

bool check(char c)
{
	for(int i = 0; i < 4; i++)
	{
		int cnt = 0;
		for(int j = 0; j < 4; j++)
			if (s[i][j] == c) cnt += 2;
			else if (s[i][j] == 'T') cnt += 1;
		if (cnt >= 7) return 1;
	}
	for(int i = 0; i < 4; i++)
	{
		int cnt = 0;
		for(int j = 0; j < 4; j++)
			if (s[j][i] == c) cnt += 2;
			else if (s[j][i] == 'T') cnt += 1;
		if (cnt >= 7) return 1;
	}
	int cnt = 0;
	for(int i = 0; i < 4; i++)
		if (s[i][i] == c) cnt += 2;
		else if (s[i][i] == 'T') cnt += 1;
	if (cnt >= 7) return 1;
	cnt = 0;
	for(int i = 0; i < 4; i++)
		if (s[i][3 - i] == c) cnt += 2;
		else if (s[i][3 - i] == 'T') cnt += 1;
	if (cnt >= 7) return 1;
	return 0;
}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> T;
	for(int t = 1; t <= T; t++)
	{
		for(int i = 0; i < 4; i++) cin >> s[i];
		bool full = 1;
		for(int i = 0; i < 4; i++)
			for(int j = 0; j < 4; j++)
				if (s[i][j] == '.')
					full = 0;
		bool x = check('X');
		bool o = check('O');
		printf("Case #%d: ", t);
		if (x) printf("X won\n");
		else if (o) printf("O won\n");
		else if (full) printf("Draw\n");
		else printf("Game has not completed\n");
	}
	return 0;
}
