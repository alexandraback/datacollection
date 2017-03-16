#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>

#define sqr(x) ((x) * (x))
#define ALL(c) (c).begin(), (c).end()

using namespace std;

const double PI = 2.0 * acos (0.0);
const int INF = 2123123123;
const int EPS = 1e-9;

typedef long long LL;

inline int NUM (char c) { return (int)c - 48; }
inline char CHAR (int n) { return (char)(n + 48); }
template <class T> inline T MAX (T a, T b) { if (a > b) return a; return b; }
template <class T> inline T MIN (T a, T b) { if (a < b) return a; return b; }

inline void OPEN(const string &s) 
{
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int x,o,draw,d1,d2,r,c,t;
char a[10][10];
string s;

int main()
{
	OPEN("gcjqa");
	int tc,i,j,k;
	scanf("%d", &t); getchar();
	for (tc = 1; tc <= t; tc++)
	{
		x = 0; o = 0; draw = 1;
		
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++) 
			{
				scanf("%c", &a[i][j]);
				if (a[i][j] == '.') draw = 0;
			}
			getchar();
		}
		
		for (i = 0; i < 4; i++)
			for (j = 0; j < 4; j++)
			{
				r = 0; c = 0; d1 = 0; d2 = 0;
				for (k = 0; k < 4; k++)
				{
					if ((a[i][j+k] == 'X') || (a[i][j+k] == 'T')) ++c;
					if ((a[i+k][j] == 'X') || (a[i+k][j] == 'T')) ++r;
					if ((a[i+k][j+k] == 'X') || (a[i+k][j+k] == 'T')) ++d1;
					if ((i-k >= 0) && ((a[i-k][j+k] == 'X') || (a[i-k][j+k] == 'T'))) ++d2;
				}
				if ((c == 4) || (r==4) || (d1==4) || (d2 == 4)) x = 1;
			}
			
		for (i = 0; i < 4; i++)
			for (j = 0; j < 4; j++)
			{
				r = 0; c = 0; d1 = 0; d2 = 0;
				for (k = 0; k < 4; k++)
				{
					if ((a[i][j+k] == 'O') || (a[i][j+k] == 'T')) ++c;
					if ((a[i+k][j] == 'O') || (a[i+k][j] == 'T')) ++r;
					if ((a[i+k][j+k] == 'O') || (a[i+k][j+k] == 'T')) ++d1;
					if ((i-k >= 0) && ((a[i-k][j+k] == 'O') || (a[i-k][j+k] == 'T'))) ++d2;
				}
				if ((c == 4) || (r==4) || (d1==4) || (d2==4)) o = 1;
			}
		printf("Case #%d: ", tc);
		if (x) puts("X won");
		if (o) puts("O won");
		if (!x && !o && draw) puts("Draw");
		if (!x && !o && !draw) puts("Game has not completed");
		getline(cin,s);
	}
}