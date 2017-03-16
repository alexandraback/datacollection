#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int s[1001];
int main()
{
//	freopen("B-small-attempt0.in","r",stdin);
//	freopen("B-small-attempt0.out","w",stdout);
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
	int T,k=0;
	scanf("%d",&T);
	while(T!=0)
	{
		T--;
		k++;
		string x;
		cin>>x;
		int lx=x.size();
		int i,j;
		for(i=1;i<=lx;i++)
		{
			if(x[i-1]=='+')
				s[i]=1;
			else
				s[i]=0;
		}
		int sx=0;
		for(i=lx;i>=1;i--)
		{
			if(s[i]==0)
			{
				sx++;
				s[i]=1;
				for(j=1;j<=i-1;j++)
					s[j]=1-s[j];
			}
		}
		printf("Case #%d: %d\n",k,sx);
	}
	return 0;
}
