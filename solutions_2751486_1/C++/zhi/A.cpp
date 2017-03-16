#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#define MAX_L 1000000
using namespace std;
typedef double LL;
int T,n,L,m[MAX_L],c[MAX_L],a[MAX_L],ans;
char s[MAX_L+1],v[]="aeiou";
int main()
{
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		scanf("%s%d",s,&n);
		L=strlen(s);
		for(int j=0;j<L;j++)
		{
			m[j]=1;
			for(int k=0;k<5;k++)
				if(s[j]==v[k])
					m[j]=0;
		}
		c[0]=m[0];
		for(int j=1;j<L;j++)
			if(m[j-1]&&m[j])
				c[j]=c[j-1]+m[j];
			else
				c[j]=m[j];
		if(n==1&&m[0]==1)
			a[0]=1;
		else
			a[0]=0;
		for(int j=1;j<L;j++)
			if(c[j]>=n)
				a[j]=j-n+2;
			else
				a[j]=a[j-1];
		ans=0;
		for(int j=0;j<L;j++)
			ans+=a[j];
		printf("Case #%d: %d\n",i+1,ans);
	}
	return 0;
}
