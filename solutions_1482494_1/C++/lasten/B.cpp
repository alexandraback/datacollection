#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define maxn 1010
struct fff
{
	int x,y;
	int id;
	void in()
	{
		scanf("%d %d",&x,&y);
	}
};
fff p[maxn];
int num[maxn];
int main()
{
//	freopen("r","r",stdin);
	int cas;
	scanf("%d",&cas);
	for(int cc=1;cc<=cas;cc++)
	{
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			p[i].in();
		int now=0;
		int tmp=0;
		memset(num,0,sizeof(num));
		while(now != n*2)
		{
			bool flag=false;
			for(int i=0;i<n && !flag;i++)
			{
				if(num[i] != 2 && p[i].y <= now)
				{
					now+=2-num[i];
					num[i]=2;
					flag=true;
					tmp++;
				}
			}
			if(flag)
				continue;
			int id=-1;
			int mark=0;
			for(int i=0;i<n;i++)
			{
				if(p[i].x <= now && num[i] == 0 && p[i].y > mark)
				{
					mark=p[i].y;
					id=i;
				}
			}
			if(id == -1)
				break;
			num[id]=1;
			now++;
			tmp++;
		}
		if(now != n*2)
			printf("Case #%d: Too Bad\n",cc);
		else
			printf("Case #%d: %d\n",cc,tmp);
	}
	return 0;
}

