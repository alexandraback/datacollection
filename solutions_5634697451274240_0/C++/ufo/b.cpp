#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
char w[1000];
int n,ans;
int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	int t,tt;
	int i,j;
	scanf("%d",&tt);
	for(t=1;t<=tt;++t)
	{
		scanf("%s",w+1);
		ans=0;
		n=strlen(w+1);
		w[++n]='+';
		for(i=2;i<=n;++i)
			if(w[i]!=w[i-1])
				++ans;
		printf("Case #%d: %d\n",t,ans);
	}
	return 0;
} 
