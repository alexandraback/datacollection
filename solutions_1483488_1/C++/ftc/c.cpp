#include <iostream>
#include <fstream>
#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <string>
#include <map>
#include <cstring>

using namespace std;

#define NextLine() { char c = getchar(); while (c != 10 && c != EOF) { c = getchar(); } }

int a, b;

void Load()
{
	scanf("%d%d", &a, &b);
}

int tenpow[9] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};
int was[2000001];

void Solve()
{
	memset(was, 0, sizeof(was));
	int i;
	int ans = 0;
	for (i = a; i <= b; i++)
	{
		int j;
		int len = 1;
		j = i / 10;
		while (j > 0)
		{
			len++;
			j /= 10;
		}
		for (j = 1; i >= tenpow[j]; j++)
		{
			int nw = i / tenpow[j] + (i % tenpow[j]) * tenpow[len - j];
			//cerr << i << " " << j << " " << nw << "\n";
			if (nw <= b && nw > i) 
			{
				if (was[nw] == i) continue;
				was[nw] = i;
				ans++;
			}	
		}
	}
	cout << ans << "\n";
}

int main()
{
	int nt;
	scanf("%d", &nt);
	NextLine();
	int it;
	for (it = 0; it < nt; it++)
	{
		Load();
		printf("Case #%d: ", it + 1);
		Solve();
	}
	return 0;
}