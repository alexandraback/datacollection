/* ***********************************************
Author        :kuangbin
Created Time  :2014/5/11 17:18:36
File Name     :E:\2014ACM\比赛\2014_GCJ_R1C\B.cpp
************************************************ */

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
const int MOD = 1e9+7;

string str[110];
long long f[110];
void init()
{
	f[0] = 1;
	for(int i = 1;i < 110;i++)
		f[i] = f[i-1]*i%MOD;
}
int a[50][3];

int F[30];
int find(int x)
{
	if(F[x] == -1)return x;
	else return F[x] = find(F[x]);
}
void bing(int x,int y)
{
	int t1 = find(x);
	int t2 = find(y);
	if(t1 != t2)
		F[t1] = t2;
}
long long b[30];
bool used[30];

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
	int n;
	int iCase = 0;
	scanf("%d",&T);
	init();
	while(T--)
	{
		iCase++;
		scanf("%d",&n);
		for(int i = 0;i < n;i++)
			cin>>str[i];
		memset(a,0,sizeof(a));
		bool ff = true;
		memset(F,-1,sizeof(F));
		for(int i = 0;i < n;i++)
		{
			bool same = true;
			for(int j = 1;j < str[i].length();j++)
			{
				if(str[i][j] != str[i][j-1])
				{
					same = false;
					break;
				}
			}
			if(same)//全部相同的
			{
				a[str[i][0] - 'a'][2]++;
				continue;
			}
			int len = str[i].length();
			memset(used,false,sizeof(used));
			used[str[i][0] - 'a'] = true;
			for(int j = 1;j < len;j++)
			{
				if(str[i][j] != str[i][j-1] && used[str[i][j] - 'a'])
				{
					ff = false;
					break;
				}
				used[str[i][j] - 'a'] = true;
			}
			a[str[i][0]-'a'][0]++;
			a[str[i][len-1]-'a'][1]++;
			bing(str[i][0] - 'a',str[i][len-1] - 'a');
			int lx = 0, rx = len-1;
			while(str[i][lx+1] == str[i][lx])lx++;
			while(str[i][rx-1] == str[i][rx])rx--;
			memset(used,false,sizeof(used));
			for(int j = 0;j < n;j++)
				if(j != i)
					for(int k = 0;k < str[j].length();k++)
						used[str[j][k] - 'a'] = true;
			for(int x = lx+1;x < rx;x++)
			{
				if(used[str[i][x] - 'a'])
				{
					ff = false;
					break;
				}
			}
		}
		if(ff)
		{
			for(int i = 0;i < 26;i++)
				if(a[i][0] > 1 || a[i][1] > 1)
					ff = false;
		}
		if(!ff)
		{
			printf("Case #%d: 0\n",iCase);
			continue;
		}
		for(int i = 0;i < 26;i++)b[i] = 1;
		for(int i = 0;i < 26;i++)
		{
			b[find(i)] *= f[a[i][2]];
			b[find(i)] %= MOD;
		}
		long long ans = 1;
		int num = 0;
		for(int i = 0;i < 26;i++)
			if(F[i] == -1)
			{
				ans = ans*b[i]%MOD;
				if(a[i][0] || a[i][1] || a[i][2])
					num++;
			}
		for(int i = 0;i < 26;i++)
			if(F[i] == -1)
			{
				bool you = false;
				for(int j = 0; j < 26;j++)
					if(find(j) == find(i))
						if(a[j][0] == 0 || a[j][1] == 0)
							you = true;
				if(!you)
				{
					ans = 0;
				}
			}
		ans = ans*f[num]%MOD;
		printf("Case #%d: %I64d\n",iCase,ans);
	}
    return 0;
}
