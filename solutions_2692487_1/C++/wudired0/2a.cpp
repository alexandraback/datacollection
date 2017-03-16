#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
int a[123];
int main()
{
    int cs,i,j,k,n,m;
    freopen("A-large (1).in","r",stdin);
    freopen("A.out","w",stdout);
    scanf("%d",&cs);
    for (int q = 1; q <= cs; q++)
    {
        scanf("%d%d",&m,&n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a+1,a+n+1);
        if (m == 1)
        {
              printf("Case #%d: %d\n", q, n);
              continue;
        }
        int best  = n;
        for (int i = 0 ; i <= n ; i++)
        {
            int k = n-i;
            int sum = m;
            for (int j = 1; j <=i ; j++)
            {
                while (sum <= a[j])
                {
                     sum+=sum-1;
                     k++;
                }
                sum+=a[j];
            }
            if (best >k)
            best=k;
        }
         printf("Case #%d: %d\n", q, best);
    }
}
            
