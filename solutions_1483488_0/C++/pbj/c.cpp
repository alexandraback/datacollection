#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n,s,p,tol[150];
char str[100],st[100],st1[100];
int main()
{
	int t,i,j,k,a,b;
	//freopen("d:\\gcj\\c.in","r",stdin);
	//freopen("d:\\gcj\\c.out","w",stdout);
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		int cnt=0;
		scanf("%d%d",&a,&b);
		for(j=a;j<=b;j++)
		{
			itoa(j,str,10);
			int len=strlen(str);
			st[len-1]=str[0];
			for(k=1;k<len;k++)
				st[k-1]=str[k];
			st[len]='\0';
			while(strcmp(st,str)!=0)
			{
				int tmp=atoi(st);
				if(tmp>=a && tmp<=b)
					cnt++;
				strcpy(st1,st);
				st[len-1]=st1[0];
				for(k=1;k<len;k++)
					st[k-1]=st1[k];
				st[len]='\0';
			}
		}
		printf("Case #%d: ",i);
		printf("%d\n",cnt/2);
	}
	return 0;
}