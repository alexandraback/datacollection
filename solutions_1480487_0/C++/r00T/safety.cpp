#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cctype>
#include<cstring>
#include<string>
#include<algorithm>
#include<stack>
#include<vector>
using namespace std;

int main()
{
    int tc;
    scanf("%d", &tc);
    for(int a = 1; a<=tc; a++)
    {
            int n,cnt=0;
            scanf("%d", &n);
            int arr[n];
            int tot = 0,sum = 0;
            for(int i = 0; i<n; i++)
            {
                    scanf("%d", &arr[i]);
                    tot = tot + arr[i];
            }
            printf("Case #%d: ", a);
            double cut = (2.0*tot)/(double)n;
            double f[n];
            for(int i = 0; i<n; i++)
            {
                   f[i] = ((cut - arr[i])/tot)*100;
                   if(f[i] < 0)
                   {  
                       f[i] = 0;
                       cnt++;
                       sum = sum + arr[i];
                   }
            }
            cut = (2.0*tot-sum)/(double)(n-cnt);
            for(int i = 0; i<n; i++)
            {
                   if(f[i] != 0)
                           f[i] = ((cut - arr[i])/tot)*100;
                   printf("%.6lf ", f[i]);
            }
            printf("\n");
    }
    return 0;
}
