#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
char s[1200000];
int f[1200000];


int main()
{
	//	freopen("A.in","r",stdin);freopen("A.out","w",stdout);
//	freopen("A-small-attempt0.in","r",stdin);freopen("A-small-attempt0.out","w",stdout);
//	freopen("A-small-attempt1.in","r",stdin);freopen("A-small-attempt1.out","w",stdout);
//	freopen("A-small-attempt2.in","r",stdin);freopen("A-small-attempt2.out","w",stdout);
	freopen("A-large.in","r",stdin);freopen("A-large.out","w",stdout);
	int tt,ii,k,n,i,j,kk;
	__int64 tot;
	scanf("%d",&tt);
	for(ii=1;ii<=tt;ii++)
	{
		if (ii==10)
		{
			int kgt=0;
		}
		scanf("%s",s);
		scanf("%d",&n);
	//	cout<<strlen(s)<<endl;
		kk=strlen(s);
	    for(i=0;i<kk;i++)
			f[i]=0;
		k=0;
		for(i=0;i<kk;i++)
		{
			if (s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
			{
				k=0;
				if (i==0)  f[i]=0;
				else
					f[i]=f[i-1];
				continue;
			}
			k=k+1;
			if (k>=n)  f[i]=i+2-n;
			else
			{
				if (i==0)  f[i]=0;
				else
					f[i]=f[i-1];
			}
		}
		tot=0;
		for(i=0;i<kk;i++)
			tot=tot+f[i];
		printf("Case #%d: %I64d\n",ii,tot);
	}
	return 0;
}