#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>

using namespace std;

typedef long long LL;

int a[100],num;
int n,m,T;
int main()
{
	scanf("%d%d%d",&T,&n,&m);
	if (n==16)
	{
		printf("Case #1:\n");
		num=0;
		for (int i=2;i<=14;i+=2)
			for (int j=i+2;j<=14;j+=2)
			{
				for (int p=3;p<=15;p+=2)
					for (int q=p+2;q<=15;q+=2)
					{
						if (num>=m) continue;
						memset(a,0,sizeof(a));
						a[1]=1;a[16]=1;
						a[i]=1;a[j]=1;
						a[p]=1;a[q]=1;
						for (int i=1;i<=16;++i) printf("%d",a[i]);
						for (int i=2;i<=10;++i) printf(" %d",i+1);
						printf("\n");
						num++;
					}
			} 		
	}
	else
	{
		printf("Case #1:\n");
		num=0;
		for (int i=2;i<=30;i+=2)
			for (int j=i+2;j<=30;j+=2)
			{
				for (int p=3;p<=31;p+=2)
					for (int q=p+2;q<=31;q+=2)
					{
						if (num>=m) continue;
						memset(a,0,sizeof(a));
						a[1]=1;a[32]=1;
						a[i]=1;a[j]=1;
						a[p]=1;a[q]=1;
						for (int i=1;i<=32;++i) printf("%d",a[i]);
						for (int i=2;i<=10;++i) printf(" %d",i+1);
						printf("\n");
						num++;
					}
			} 		
	}
	return 0;
}
