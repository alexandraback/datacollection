#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<vector>
int n,now,ans,x;
char s[1010];
void task()
{
	scanf("%d %s",&n,s);
	now=s[0]-48;ans=0;
	for(int i=1;i<=n;i++)
    {
    	x=s[i]-48;
    	if(now<i){now++;ans++;}
    	now+=x;
    }
    printf("%d\n",ans);
}
	
int main()
{
	int T;
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d",&T);
	for(int ti=1;ti<=T;ti++)
	{
		printf("Case #%d: ",ti);
		task();
	}
}
