/*
 * File: B.cpp
 * Author: wym510 
 * Email: <wym6110@gmail.com>
 * Create Date: 2012-4-28 10:05:28
*/

#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#define S size()
#define B begin()
#define E end()
#define P push_back
#define fu(i,a,b) for(int i=a;i<b;++i)
#define fd(i,a,b) for(int i=b-1;i>=a;--i)
typedef long long int64;
using namespace std;

const int MaxN=3000;

struct node
{
	int a,b;
}p[MaxN];

struct Tnode
{
	int no;

	Tnode(int x) {no=x;}
};

bool operator <(Tnode x,Tnode y) { return p[x.no].b<p[y.no].b; }

int vis[MaxN];
int num1[MaxN],num2[MaxN];

bool cmp2(int x,int y)
{
	return p[x].b<p[y].b;
}

bool cmp1(int x,int y)
{
	return p[x].a<p[y].a;
}

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);

	int test;

	cin>>test;
	for(int no=1;no<=test;no++)
	{
		int n;

		scanf("%d",&n);
		memset(vis,0,sizeof vis);
		for(int i=0;i<n;i++) scanf("%d%d",&p[i].a,&p[i].b);
		for(int i=0;i<n;i++) num1[i]=num2[i]=i;
		sort(num1,num1+n,cmp1);
		sort(num2,num2+n,cmp2);

		int now=0,times=0;
		priority_queue<Tnode> h;
		
		while(!h.empty()) h.pop();
		
		for(int i=0,j=0;i<n || j<n;)
		{
			while(j<n && now>=p[num2[j]].b)
			{
				times++;
				now+=2-vis[num2[j]];
				vis[num2[j]]=2;
				j++;
			}
			
			if(j==n) break;

			while(i<n && now>=p[num1[i]].a)
			{
				h.push(Tnode(num1[i]));
				i++;
			}

			if(h.empty())
			{
				times=-1;
				break;
			}else
			{
				int u=h.top().no;

				h.pop();
				if(vis[u]==0)
				{
					times++;
					now++;
					vis[u]=1;
				}
			}
		}

		printf("Case #%d: ",no);
		if(times!=-1) printf("%d\n",times);
		else printf("Too Bad\n");
	}
	return 0;
}

/* vim: set ts=4 sw=4: */

