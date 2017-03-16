#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 2000;

int n1, n2, k;

//n1,n2为二分图的顶点集,其中x∈n1,y∈n2

int m[N][N], vis[N], link[N];

//link记录n2中的点y在n1中所匹配的x点的编号

int find(int x)
{
	int i;
	for (i = 1;i <= n2;i++)
	{
		if (m[x][i] && !vis[i])//x->i有边,且节点i未被搜索
		{
			vis[i] = 1;//标记节点已被搜索
					   //如果i不属于前一个匹配M或被i匹配到的节点可以寻找到增广路
			if (link[i] == 0 || find(link[i]))
			{
				link[i] = x;//更新
				return 1;//匹配成功
			}
		}
	}
	return 0;
}
/*
int main()
{
	int i, x, y, s = 0;
	scanf("%d%d%d", &n1, &n2, &k);
	for (i = 0;i<k;i++)
	{
		scanf("%d%d", &x, &y);
		m[x][y] = 1;
	}
	for (i = 1;i <= n1;i++)
	{
		memset(vis, 0, sizeof(vis));
		if (find(i))
			s++;
	}
	printf("%d\n", s);
	return 0;
}
*/
int main()
{
	int T;
	scanf("%d", &T);
	for (int cases = 1; cases <= T; cases++)
	{
		memset(vis, 0, sizeof(vis));
		memset(link, 0, sizeof(link));
		memset(m, 0, sizeof(m));
		map<string, int> m1, m2;
		int k;
		scanf("%d", &k);
		for (int i = 0; i < k; i++)
		{
			char str1[30], str2[30];
			scanf("%s%s", str1, str2);
			string s1(str1), s2(str2);
			if (m1.find(str1) == m1.end())
			{
				m1[str1] = m1.size()+1;
			}
			if (m2.find(str2) == m2.end())
			{
				m2[str2] = m2.size()+1;
			}
			m[m1[str1]][m2[str2]] = 1;
		}
		n1 = m1.size();
		n2 = m2.size();
		int sum = 0;
		for (int i = 1;i <= n1; i++)
		{
			memset(vis, 0, sizeof(vis));
			if (find(i))
				sum++;
		}
		printf("Case #%d: %d\n", cases, k - (n1 + n2 - sum));
	}
	return 0;
}