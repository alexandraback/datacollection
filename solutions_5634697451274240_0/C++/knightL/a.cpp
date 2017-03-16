#include <set>
#include <queue>
#include <cassert>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <utility>
#include <algorithm>
#include <iterator>
#include <numeric>
using namespace std;

typedef long long ll;

const int MAXN=10;

int n;
int dist[1<<MAXN];
char str[MAXN+1];

int testbit(int n, int m)
{
	return (n>>m)&1;
}

int getMask()
{
	int res=0;
	for(int i=0;i<n;i++)
		res|=(str[i]=='-')<<i;
	return res;
}

void parseMask(int msk)
{
	for(int i=0;i<n;i++)
		if(testbit(msk,i))
			str[i]='-';
		else
			str[i]='+';
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int test=1;test<=T;test++)
	{
		scanf("%s",str);
		n=strlen(str);
		memset(dist,0x7F,sizeof(dist));
		dist[getMask()]=0;
		queue<int> q;
		q.push(getMask());
		while(!q.empty())
		{
			int cur=q.front();
			q.pop();
			for(int i=1;i<=n;i++)
			{
				parseMask(cur);
				reverse(str,str+i);
				for(int j=0;j<i;j++)
					str[j]='+'+'-'-str[j];
				int nxt=getMask();
				if(dist[nxt]>dist[cur]+1)
				{
					dist[nxt]=dist[cur]+1;
					q.push(nxt);
				}
			}
		}
		printf("Case #%d: %d\n",test, dist[0]);
	}
	return 0;
}
