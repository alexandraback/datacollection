#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 200;
int a[maxn][maxn];
int N, M, total;

void read()
{
	scanf("%d%d", & N, & M);
	total = N * M;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j) scanf("%d", & a[i][j]);
}

int find()
{
	int ans = -1, temp1 = 101, all_temp = 100;
	for (int i = 1; i <= N; ++i)
	{
		int temp2 = 101;
		for (int j = 1; j <= M; ++j) if (a[i][j]) temp2 = min(temp2, a[i][j]);
		if (temp2 >= 100) continue;
		all_temp = min(all_temp, temp2);
		bool ff = true;
		for (int j = 1; j <= M; ++j) if ((a[i][j]) && (a[i][j] != temp2))
		{
			ff = false; break;
		}
		if ((ff) && (temp2 < temp1))
			ans = i, temp1 = temp2;
	}
	
	for (int j = 1; j <= M; ++j)
	{
		int temp2 = 101;
		for (int i = 1; i <= N; ++i) if (a[i][j]) temp2 = min(temp2, a[i][j]);
		if (temp2 >= 100) continue;
		all_temp = min(all_temp, temp2);
		bool ff = true;
		for (int i = 1; i <= N; ++i) if ((a[i][j]) && (a[i][j] != temp2))
		{
			ff = false; break;
		}
		if ((ff) && (temp2 < temp1))
			ans = N + j, temp1 = temp2;
	}
	
	if (temp1 > all_temp) ans = -1;
	return ans;
}

void change(int v)
{
	if (v <= N)
	{
		for (int j = 1; j <= M; ++j) 
		{
			if (a[v][j])
				--total, a[v][j] = 0;
		}
	}
	else
	{
		v -= N;
		for (int i = 1; i <= N; ++i)
		{
			if (a[i][v])
				--total, a[i][v] = 0;
		}
	}
}

void getans()
{
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j) 
			if (a[i][j] > 100)
			{
				printf("NO\n");
				return;
			}
			else if (a[i][j] == 100) --total;

	for (int i = 1; i <= N + M; ++i)
	{
		int t1 = find();
		// cerr << t1 << endl;
		if (t1 == -1) break;
		change(t1);
	}
	
	if (total == 0) printf("YES\n");
	else printf("NO\n");
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