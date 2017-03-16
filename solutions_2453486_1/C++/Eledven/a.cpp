#include <iostream>
#include <cassert>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <map>
#include <iomanip>
#define nextLine() { for (int c = getchar(); c != '\n' && c != EOF; c = getchar()); }
#define sqr(a) ((a)*(a))
#define has(mask,i) (((mask) & (1<<(i))) == 0 ? false : true)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
using namespace std;

#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define fi first
#define se second

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

typedef long long LL;
typedef long double ldb;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <bool> vb;
typedef vector <vb> vvb;

const int INF = (1 << 30) - 1;
const ldb EPS = 1e-9;
const ldb PI = fabs(atan2(0.0, -1.0));

char a[10][10];
void load()
{
	for (int i = 0; i < 4; i++)
		scanf("%s", a[i]);
}

int ti, tj;

bool check(char c)
{
	if (ti != -1) a[ti][tj] = c;
	for (int i = 0; i < 4; i++)
	{
		bool ok = true;
		for (int j = 0; j < 4; j++)
			ok &= a[i][j] == c;
		if (ok) return true;	
	}

	for (int j = 0; j < 4; j++)
	{
		bool ok = true;
		for (int i = 0; i < 4; i++)
			ok &= a[i][j] == c;
		if (ok) return true;	
	}

	{
		bool ok = true;
		for (int i = 0; i < 4; i++)
			ok &= a[i][i] == c;
		if (ok) return true;	
	}

	{
		bool ok = true;
		for (int i = 0; i < 4; i++)
			ok &= a[i][3 - i] == c;
		if (ok) return true;	
	}
	return false;
}

string solve()
{
	ti = tj = -1;
	bool empty = false;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			empty |= a[i][j] == '.';
			if (a[i][j] == 'T')
			{
				ti = i;
				tj = j;
			}
		}	
	}
	if (check('X'))
		return "X won";
	if (check('O'))
		return "O won";	
	return empty ? "Game has not completed" : "Draw";
}

int main()
{
	int tests;
	scanf("%d", &tests);
	for (int test = 1; test <= tests; test++)
	{
		load();
		string answer = solve();
		printf("Case #%d: %s\n", test, answer.c_str());
	}	
	return 0;
}
