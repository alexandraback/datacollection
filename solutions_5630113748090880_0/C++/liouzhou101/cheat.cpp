#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <set>
#include <algorithm>
#include <bitset>

using namespace std;

#define X first
#define Y second

const int MAXN=55;

int v[MAXN*MAXN];

int main()
{
	freopen("try.in", "r", stdin);
	freopen("try.out", "w", stdout);
	int Test;
	scanf("%d", &Test);
	for (int TT=1; TT<=Test; ++TT)
	{
		printf("Case #%d:", TT);
		int n;
		scanf("%d", &n);
		for (int i=0; i<=2500; ++i)
			v[i] = 0;
		for (int i=0; i<2*n-1; ++i)
		{
			for (int j=0; j<n; ++j)
			{
				int x;
				scanf("%d", &x);
				v[x] ++;
			}
		}
		for (int i=0; i<=2500; ++i)
			if (v[i]%2==1)
				printf(" %d", i);
		puts("");
	}
	return 0;
}
