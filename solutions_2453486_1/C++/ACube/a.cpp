#include <algorithm>
#include <iostream>
#include <cassert>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <map>
#include <set>

#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)
#define PB(A) push_back(A)

typedef long long ll;
typedef double ld;

int	fx[] = {-1, 0, +1, 0}, fy[] = {0, +1, 0, -1},
	ex[] = {-1, -1, 0, +1, +1, +1, 0, -1}, ey[] = {0, +1, +1, +1, 0, -1, -1, -1};

using namespace std;

int test_num, case_number;

#define gout case_number++, printf("Case #%d: ",case_number), cout

char s[20][20];

bool check(char x)
{
	for (int i = 0; i < 4; i++)
	{
		bool ok=1;
		for (int j = 0; j < 4; j++)
			if (s[i][j]==x || s[i][j]=='T');
			else ok = 0;
		if (ok) return 1;
	}
	for (int i = 0; i < 4; i++)
	{
		bool ok=1;
		for (int j = 0; j < 4; j++)
			if (s[j][i]==x || s[j][i]=='T');
			else ok = 0;
		if (ok) return 1;
	}
	bool ok=1;
	for (int i = 0; i < 4; i++)
		if (s[i][i]==x || s[i][i] == 'T');
		else ok = 0;
	if (ok) return 1;
	ok = 1;
	for (int i = 0; i < 4; i++)
		if (s[3-i][i]==x || s[3-i][i]=='T');
		else ok = 0;

	return ok;
}

void main2()
{
	for (int i = 0; i < 4; i++)
		scanf("%s", s[i]);
	if (check('X')) gout << "X won\n";
	else if (check('O')) gout << "O won\n";
	else
	{
	 	int ok = 0;
	 	for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) if (s[i][j] == '.') ok = 1;
	 	if (ok) gout << "Game has not completed\n";
	 	else gout << "Draw\n";
	}
}

int main()
{
	scanf("%d", &test_num);

	for (int i = 0; i < test_num; i++)
		main2();

	return 0;
}
