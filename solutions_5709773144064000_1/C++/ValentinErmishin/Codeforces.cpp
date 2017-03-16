#include "stdafx.h" 
#include "wchar.h"
#include "conio.h"
#include "iostream"
#include "string.h"
#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "limits.h"
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <functional>
#include <bitset>
#include <iomanip>
#include <stack>
#include <queue>
#define PI 3.14159265358979323846
#define ull unsigned long long int
#define ll long long int
#define EPS 1e-11
#define pb push_back
#define EOS(c) (c != EOF && c != '\0' && c != '\n' && c != ' ')
#define oo 1000000005
#define ALL(v) v.begin(), v.end()
#define mp make_pair
#define win return 0 

//#define FILE "brackets"

using namespace std;

template<class telem>telem MAX(telem a, telem b)
{
	return (a > b) ? a : b;
}

template<class telem>telem MIN(telem a, telem b)
{
	return (a < b) ? a : b;
}

template<class telem>telem GCD(telem a, telem b)
{
	return b ? GCD(b, a % b) : a;
}

template<class telem>telem LCM(telem a, telem b)
{
	return a / GCD(a, b) * b;
}

template<class telem>telem UNSIGNED(telem a)
{
	return (a > 0) ? a : a * (-1);
}

template<class telem>void bez_swop(telem &a, telem &b)
{
	telem c = a;
	a = b;
	b = c;
}

int Case;
int T;

double c, f, x, s, t;

int main()
{  
	//freopen(FILE".in", "r", stdin);
	//freopen(FILE".out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	//time_t start = clock();

	scanf("%d", &T);
	Case = T;

	while(T --> 0)
	{
		printf("Case #%d: ", Case - T);

		s = 2.0;
		t = 0.0;

		scanf("%lf %lf %lf", &c, &f, &x);

		while(0==0)
		{
			double a, na, tc;

			tc = c / s;

			na = x / s;
			a = x / (s + f);
			a += tc;

			if(na < a)
			{
				printf("%0.9lf\n", t + na);
				break;
			}

			t += tc;
			s += f;
		}
	}

	//printf("\n%0.3lf", (clock() - start) * 1.0 / CLOCKS_PER_SEC);

	win;
}