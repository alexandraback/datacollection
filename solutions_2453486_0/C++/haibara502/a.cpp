#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 5;
string a[maxn];

void read()
{
	for (int i = 0; i < 4; ++i) cin >> a[i];
	// for (int i = 0; i < 4; ++i) cerr << a[i] << endl;
}

void getans()
{
	for (int i = 0; i < 4; ++i)
	{
		bool x = true, o = true;
		for (int j = 0; j < 4; ++j) 
		{
			if ((a[i][j] != 'X') && (a[i][j] != 'T')) x = false;
			if ((a[i][j] != 'O') && (a[i][j] != 'T')) o = false;
		}
		if (x)
		{
			printf("X won\n");
			return;
		}
		if (o)
		{
			printf("O won\n");
			return;
		}
	}
	
	for (int j = 0; j < 4; ++j)
	{
		bool x = true, o = true;
		for (int i = 0; i < 4; ++i)
		{
			if ((a[i][j] != 'X') && (a[i][j] != 'T')) x = false;
			if ((a[i][j] != 'O') && (a[i][j] != 'T')) o = false;
		}
		if (x)
		{
			printf("X won\n");
			return;
		}
		if (o)
		{
			printf("O won\n");
			return;
		}
	}
	
	bool x = true, o = true;
	for (int i = 0; i < 4; ++i)
	{
		if ((a[i][i] != 'X') && (a[i][i] != 'T')) x = false;
		if ((a[i][i] != 'O') && (a[i][i] != 'T')) o = false;
	}
	if (x)
	{
		printf("X won\n");
		return;
	}
	if (o)
	{
		printf("O won\n");
		return;
	}
	
	x = true, o = true;
	for (int i = 0; i < 4; ++i)
	{
		if ((a[i][3 - i] != 'X') && (a[i][3 - i] != 'T')) x = false;
		if ((a[i][3 - i] != 'O') && (a[i][3 - i] != 'T')) o = false;
	}
	if (x)
	{
		printf("X won\n");
		return;
	}
	if (o)
	{
		printf("O won\n");
		return;
	}
	
	bool full = true;
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j) if (a[i][j] == '.') full = false;
	if (full)
	{
		printf("Draw\n");
		return;
	}
	
	printf("Game has not completed\n");
}

int main()
{
	int T, t1(1);
	scanf("%d", & T);
	for (; T--; ++t1)
	{
		printf("Case #%d: ", t1);
		read();
		getans();
	}
}