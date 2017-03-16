#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
using namespace std;

int i,j,k,m,n,l;
int a[10], b[10];

int f(int i)
{
	k=0;
	while (i!=0)
	{
		k++;
		i=i/10;
	}
	return k;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int T;
	scanf("%d",&T);
	
	a[0]=1;
	for (i=1; i<10; i++) a[i]=a[i-1]*10;
	
	for (int t=1; t<=T; t++)
	{
		int ans=0;
		scanf("%d%d",&n,&m);
		for (i=n; i<=m; i++)
		{
			k=f(i);
			b[0]=0;
			for (j=1; j<k; j++)
			{
				l=i%a[j]*a[k-j]+i/a[j];			
				if (l>i && l<=m)
				{
                    bool flag=true;
                    for (int ii=1; ii<=b[0]; ii++)
                        if (b[ii]==l)
                            flag=false;
                    if (flag)
                    {
                        b[++b[0]]=l;
                        ans++;                            
                    }
                }
			}
		}
		printf("Case #%d: %d\n",t,ans);
	}
    return 0;
}
