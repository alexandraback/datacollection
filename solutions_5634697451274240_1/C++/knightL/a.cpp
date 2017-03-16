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

const int MAXN=100;

int dist[MAXN][2];
char str[MAXN+1];

int main()
{
	int T;
	scanf("%d",&T);
	for(int test=1;test<=T;test++)
	{
		scanf("%s",str);
		int n=strlen(str);
		memset(dist,0x7F,sizeof(dist));

		int cnt=1;
		for(int i=1;i<n;i++)
			if(str[i]!=str[i-1])
				cnt++;
		dist[cnt][str[n-1]=='-'?0:1]=0;
		deque<pair<int,int> > q;
		q.push_front(make_pair(cnt,str[n-1]=='-'?0:1));
		while(!q.empty())
		{
			int cur=q.front().first;
			int last=q.front().second;
			q.pop_front();
			if(cur!=0)
			{
				if(last==1)
				{
					if(dist[cur-1][last^1]>dist[cur][last])
					{
						dist[cur-1][last^1]=dist[cur][last];
						q.push_front(make_pair(cur-1,last^1));
					}
				}

				for(int i=1;i<=cur;i++)
				{
					for(int j=0;j<cur;j++)
						str[cur-j-1]=(last^(j%2))?'+':'-';
					reverse(str,str+i);
					for(int j=0;j<i;j++)
						str[j]='+'+'-'-str[j];
					int cnt=1;
					for(int j=1;j<cur;j++)
						if(str[j-1]!=str[j])
							cnt++;
					int nlast=str[cur-1]=='-'?0:1;
					if(dist[cnt][nlast]>dist[cur][last]+1)
					{
						dist[cnt][nlast]=dist[cur][last]+1;
						q.push_back(make_pair(cnt,nlast));
					}
				}
			}
		}
		printf("Case #%d: %d\n",test, min(dist[0][0], dist[0][1]));

	}
}
