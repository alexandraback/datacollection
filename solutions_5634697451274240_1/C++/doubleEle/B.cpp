#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=110;
int n,m,x,y,z,len,ans;
char ch[N];
int main()
{
//	freopen("B-large.in","r",stdin);
//	freopen("B-large.out","w",stdout);
	int a,b,c,i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%s",ch+1);
		len=strlen(ch+1);
		ans=0;
		for(j=2;j<=len;j++)
			if(ch[j]!=ch[j-1]) ans++;
		if(ch[len]=='-') ans++;
		printf("Case #%d: %d\n",i,ans); 
	}
} 
