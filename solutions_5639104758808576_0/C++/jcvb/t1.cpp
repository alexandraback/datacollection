#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<iostream>
using namespace std;
int n;
char str[11111];
int su[11111];
int main()
{
	freopen("me.in","r",stdin);
	freopen("me.out","w",stdout);

	int tes;scanf("%d",&tes);
	for (int tt=1;tt<=tes;tt++){
		scanf("%d",&n);
		scanf("%s",str);
		su[0]=str[0]-'0';
		for (int i=1;i<=n;i++)su[i]=su[i-1]+str[i]-'0';
		int ma=0;
		for (int i=1;i<=n;i++)if(su[i-1]<i)ma=max(ma,i-su[i-1]);
		printf("Case #%d: %d\n",tt,ma);
	}
	return 0;
}
		

