#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int nq,n,ans;
char a[1010];

int main()
{//freopen("Bl.out","w",stdout);

 int i,j,q,flag;
 
 scanf("%d",&nq);
 for(q=1;q<=nq;q++)
 {	scanf("%s",a+1);
 	n=strlen(a+1);
 	ans=0;
 	flag=0;
 	for(i=1;i<=n;i++)
 		if(a[i]!=a[i-1])
 		{	ans++;
 			if(a[i]=='+') flag=1; else flag=0;
 		}
 	if(flag) ans--;
	printf("Case #%d: %d\n",q,ans);
 }
 return 0;
}
