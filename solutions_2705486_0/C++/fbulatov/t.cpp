#pragma comment(linker, "/STACK:500000000")
#include <functional>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <sstream>
#include <ctype.h>
#include <stdio.h>
#include <bitset>
#include <vector>
#include <string>
#include <math.h>
#include <time.h>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#define Int long long
#define inf 0x3f3f3f3f
#define eps 1e-9
using namespace std;

char A[22][55];

struct T
{
	T() {}
	char s[12];
};

vector <T> v[12];
int tt;

int f(int len, int p, int L, int R)
{
	int d = 0;
	for(int i = 0; i < len; i++)
	{
		if(v[len][p].s[i] != A[tt][L + i])
			d++;
	}
	return d;
}

int main()
{
	freopen("i.txt", "rt", stdin);
	freopen("o.txt", "wt", stdout);
	int t, i;
	scanf("%d", &t);
	for(tt = 0; tt < t; tt++)
		scanf("%s", &A[tt]);
	freopen("dict.txt", "rt", stdin);
	int maxL = 0;
	T tmp;
	while(scanf("%s", &tmp.s) != EOF)
	{
		int len = strlen(tmp.s);
		v[len].push_back(tmp);
	}
	for(tt = 0; tt < t; tt++)
	{
		int res = 0;
		int L = 0;
		int len = strlen(A[tt]);
		while(L < len)
		{
			int R = L, pos = L;
			int minV = inf;
			for( ; R < len; R++)
			{
				for(i = 0; i < v[R - L + 1].size(); i++)
				{
					int cur = f(R - L + 1, i, L, R);
					if(cur == 0)
						cur = cur;
					if(cur <= minV)
						minV = cur, pos = R;
				}
			}
			res += minV;
			L = pos + 1;
		}
		printf("Case #%d: %d\n", tt + 1, res);
	}
}