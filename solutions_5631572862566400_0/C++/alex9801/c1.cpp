#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>

#define TEST_NUM "c1"
//#define DEBUGGGGGGGGGGGGGGGGGGGGGGGGGG
char inname[100];
char outname[100];

bool chk[1001];
int cnt[1001];
int arr[1001];
std::vector<int> adj[1001];

int f(int x, int c)
{
	chk[x] = 1;
	int r = 0;
	for(auto y: adj[x])
	{
		if(cnt[y]==c)
			continue;
		r = std::max(r, f(y, c)+1);
	}
	return r;
}

void process()
{
	int n, r1 = 0, r2 = 0, c, x, t, i, j;
	scanf("%d", &n);
	for(i = 1; i<=n; i++)
		scanf("%d", &arr[i]);

	memset(chk, 0, sizeof(chk));
	memset(cnt, 0, sizeof(cnt));
	for(i = 1; i<=n; i++)
		adj[i].clear();

	for(i = 1; i<=n; i++)
		adj[arr[i]].push_back(i);

	for(i = 1; i<=n; i++)
	{

		if(chk[i])
			continue;
		x = i;
		while(!chk[x])
		{
			chk[x] = 1;
			x = arr[x];
		}
		t = x;

		cnt[t] = i;
		x = arr[t];
		for(c = 1; x!=t; c++)
		{
			cnt[x] = i;
			x = arr[x];
		}

		if(c>2)
		{
			r1 = std::max(r1, c);

			f(t, i);
			x = arr[t];
			while(x!=t)
			{
				f(x, i);
				x = arr[x];
			}
		}
		else if(c==2)
		{
			r1 = std::max(r1, c);
			r2 += c+f(t, i)+f(arr[t], i);
		}
	}

	printf("%d", std::max(r1, r2));
}

void pre_process()
{

}

int main()
{
#ifndef DEBUGGGGGGGGGGGGGGGGGGGGGGGGGG
	sprintf(inname, "%s.in", TEST_NUM);
	sprintf(outname, "%s.out", TEST_NUM);
#endif
	freopen(inname, "r", stdin);
	freopen(outname, "w", stdout);
	int tn, ti;
	scanf("%d", &tn);
	pre_process();
	for(ti = 1; ti<=tn; ti++)
	{
		printf("Case #%d: ", ti);
		process();
		printf("\n");
	}
	return 0;
}