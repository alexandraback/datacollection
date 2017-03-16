#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN=1010;

struct node
{
	int a,b;
}p[MAXN];

int n;
bool flag[MAXN];
pair<int,int> s[MAXN*2];

bool check(int m)
{
	memset(flag,false,sizeof(flag));
	int nowscore=0;
//	for(int i=0;i<m;++i)
//	{
//		cout<<s[i].first<<' '<<s[i].second/2<<' '<<s[i].second%2<<endl;
//	}
//	cout<<endl;
//	cout<<m<<endl;
	for(int i=0;i<m;++i)
	{
//		cout<<nowscore<<' '<<s[i].first<<' '<<s[i].second%2<<endl;
		int idx=s[i].second/2,kind=s[i].second%2;
		if(nowscore>=s[i].first)
		{
			if(flag[idx])nowscore++;
			else
			{
				flag[idx]=true;
				if(kind==1)nowscore+=2;
				else nowscore++;
			}
		}
		else return false;
	}
	return true;
}
void init()
{
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		scanf("%d%d",&p[i].a,&p[i].b);
	}
	int ans=~0U>>2,mask=1<<n;
	for(int i=0;i<mask;++i)
	{
		int u=0;
		for(int j=0;j<n;++j)
		{
			s[u++]=make_pair(p[j].b,j*2+1);
			if(i&(1<<j))s[u++]=make_pair(p[j].a,j*2);
		}
		sort(s,s+u);
		if(check(u))ans=min(ans,u);
	}
	if(ans==~0U>>2)puts("Too Bad");
	else printf("%d\n",ans);
}
int main()
{
	int t,cases=1;
	for(scanf("%d",&t);t--;)
	{
		printf("Case #%d: ",cases++);
		init();
	}
	return 0;
}
