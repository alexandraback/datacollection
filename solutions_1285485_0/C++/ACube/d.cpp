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

int	fx[] = {-1, 0, +1, 0}, fy[] = {0, +1, 0, -1};
int sign[] = {-1, 1};

using namespace std;

int test_num, case_number;

#define gout case_number++, printf("Case #%d: ",case_number), cout
#define MAXN 300

int n, m, d, sx, sy;
int hor[2][MAXN*2][MAXN*2], ver[2][MAXN*2][MAXN*2];
char s[MAXN][MAXN];

int a, b, num, divisor;
int sign1, sign2;

int tot;

bool dfs(int x, int y)
{
	tot++;
	if (!a) x = 0;
	if (!b) y = 0;	
//	cout << "Here at x = " << (sx + 1.*x*a/divisor)/2. << " " << " y = " << (sy + 1.*y*b/divisor)/2. << endl;
//	cout << "And num = " << num << " " << x << " " << y << endl;
	if (1LL*num*num*(a*a+b*b) > 1LL*d*d*divisor*divisor) return 0;
	if (!x && !y && num) return 1;

	bool v1 = 0, v2 = 0;

	//Horizontal reflection
	if ((x*a)%divisor == 0)
	{
		int l, r;
		l = r = int(sy + (y*b)/divisor);
		if ((y*b)%divisor == 0) l = max(0, l-1);
		int dir = ((a*sign1)<0)?1:0;
		v1 = hor[dir][sx+(x*a)/divisor][l]&&hor[dir][sx+(x*a)/divisor][r];
	}

	//Vertical reflection
	if ((y*b)%divisor == 0)
	{
		int l, r;
		l = r = int(sx + (x*a)/divisor);
		if ((x*a)%divisor == 0) l = max(0, l-1);
		int dir = ((b*sign2)<0)?1:0;
		v2 = ver[dir][sy+(y*b)/divisor][l]&&ver[dir][sy+(y*b)/divisor][r];
	}

	if (v1) sign1 = -sign1;
	if (v2) sign2 = -sign2;

	if (!v1 && !v2 && (x*a)%divisor==0 && (y*b)%divisor==0)
	{
		int xx = sx+(x*a)/divisor, yy = sy+(y*b)/divisor;
		int dir1 = a*sign1, dir2 = b*sign2;

		if (dir1 > 0 && dir2 > 0)
		{
			if (hor[0][xx][yy] && ver[0][yy][xx]) return 0;
		}
		else
		if (dir1 < 0 && dir2 < 0)
		{
			if (yy && xx && hor[1][xx][yy-1] && ver[1][yy][xx-1]) return 0;
		}
		else
		if (dir1 > 0 && dir2 < 0)
		{
			if (yy && hor[0][xx][yy-1] && ver[1][yy][xx]) return 0;
		}
		else
		if (dir1 < 0 && dir2 > 0)
		{
			if (xx && hor[1][xx][yy] && ver[0][yy][xx-1]) return 0;
		}
	}

	int min1, min2;

	if (!a || !b)
	{
	 	min1 = min2 = 1;
	}
	else
	{
		if ((sign1 < 0 && x < 0) || (sign1 > 0 && x > 0))
		{
			min1 = b-abs(x)%b;
		}
		else
		{
			min1 = x%b?(abs(x)%b):b;
		}

		if ((sign2 < 0 && y < 0) || (sign2 > 0 && y > 0))
		{
		 	min2 = a-abs(y)%a;
		}
		else
		{
		 	min2 = y%a?(abs(y)%a):a;
		}
	}

	assert(min1>0 && min2>0);
//	min1 = 1;

	num += min(min1, min2);
	return dfs(x+sign1*min(min1, min2), y+sign2*min(min1, min2));
}

void main2()
{
	scanf("%d%d%d", &n, &m, &d);
	d += d;

	memset(hor, 0, sizeof(hor));
	memset(ver, 0, sizeof(ver));
	for (int i = 0; i < n; i++)
	{
	 	scanf("%s", s[i]);
	 	for (int j = 0; j < m; j++)
	 		if (s[i][j] == '#')
	 		{
	 			for (int i1 = 0; i1 < 2; i1++)
	 				for (int j1 = 0; j1 < 2; j1++)
	 					hor[i1][2*(i+i1)][2*j+j1] = 1;
	 			for (int i1 = 0; i1 < 2; i1++)
	 				for (int j1 = 0; j1 < 2; j1++)
	 					ver[j1][2*(j+j1)][2*i+i1] = 1;
	 		}
	 		else
	 		if (s[i][j] == 'X')
	 		{
				sx = i*2+1;
				sy = j*2+1;
	 		}
	}

	int res = 0;
	for (int i = 0; i <= 150; i++)
		for (int j = 0; j <= 150; j++)
			if (__gcd(i, j)==1)
			{
				int val = 0;
				for (int i1 = 0; i1 < 2; i1++)
					for (int j1 = 0; j1 < 2; j1++)
					{
//						if (val & (1 << (i1^j1))) continue;
						a = i; b = j; num = 0; divisor = i*j;
						if (!divisor) divisor = 1;
					 	sign1 = sign[i1]; sign2 = sign[j1];

					 	if (i1 && !a) continue;
					 	if (j1 && !b) continue;

//						cout << "Entered for i = " << i << " j = " << j << endl;
						if (dfs(0, 0))
						{
						 	res++;

//						 	if (sign1 == sign[i1] && sign2 == sign[j1]) res++, val |= (1 << (i1^j1));

//						 	cout << "OK FOR " << i << " " << j << endl;
						}
//						cout << endl;
					}
			}

	gout << res << endl;
}

int main()
{
	scanf("%d", &test_num);

	for (int i = 0; i < test_num; i++)
		main2();
	cerr << tot << endl;

	return 0;
}
