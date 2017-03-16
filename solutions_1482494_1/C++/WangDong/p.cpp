#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<map>
#include<iostream>

using namespace std;

const int maxn = 1010;

int T;
int n;
int a1[maxn], a2[maxn];
bool c[maxn][2];

void init()
{
	scanf("%d", &n);
	memset(a1,0,sizeof(a1));
	for (int i=0; i<n; i++) scanf("%d%d", &a1[i], &a2[i]);
	memset(c, 0, sizeof(c));
}

int answer = 2010;
void work()
{
	for (int i=0; i<n; i++)
		for (int j=i; j<n; j++)
			if (a2[i] <a2[j])
			{
				int t = a1[i];a1[i] = a1[j];a1[j] = t;
				t = a2[i];a2[i] = a2[j]; a2[j] = t;
			}
	int tot = 0, tots = 0, count =n;
	for (int i=0; i<n + n; i++)
	{
		bool flag = false;
		for (int j=0; j<n; j++)
			if (c[j][1] == 0 && a2[j]<=tots)
			{
				if (c[j][0] == 1)
					tots+=1;
				else
					tots+=2;
				c[j][1] = 1;
				c[j][0] = 1;
				tot+=1;
				count--;
				flag = true;
			}
		if (flag) continue;
		if (count == 0) break;
		for (int j=0; j<n; j++)
			if (c[j][0] == 0 && a1[j]<=tots)
			{
				c[j][0] = 1;
				tot+=1;
				tots+=1;
				flag = true;
				break;
			}
		if (!flag) break;
	}
	answer = tot;
	for (int i=0; i<n; i++)
		if (c[i][1] == 0)
			answer = 2010;
}

int main()
{
	//freopen("C:/Users/yaoyao/Downloads/in.txt", "r", stdin);
	freopen("C:/Users/yaoyao/Downloads/B-large.in", "r", stdin);
	freopen("D:/workspace/Topcoder/Algorithm/Algorithm/out.txt", "w", stdout);
	scanf("%d", &T);
	for (int i=1; i<=T; i++)
	{
		init();
		work();
		if (answer == 2010)
			printf("Case #%d: Too Bad\n", i);
		else
			printf("Case #%d: %d\n", i, answer);
	}
}