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

int sum[1048576];
int main()
{
    int tc;
    scanf("%d", &tc);
    for(int a=1; a<=tc; a++)
    {
         int n;
         bool flag = 0;
         scanf("%d", &n);
         int arr[n];
         bool bin[n];
         for(int i = 0;i<n;i++)
         {
                 scanf("%lld", &arr[i]);
                 bin[i] = 0;
         }
         for(int i = 0;i<1048576;i++)
         {
                 sum[i] = 0 ;
                 for(int j=0;j<n;j++)
                 {
                         bin[j] = (int)(i/pow(2.0,n-j-1))%2;
                         sum[i] = sum[i] + bin[j]*arr[j];
                 }
                 
         }
         
         printf("Case #%d:\n", a);
         for(int i = 0 ; i<1048576; i++)
         {
                 for(int j = i+1 ; j<1048576; j++)
                 {
                         if(sum[i] == sum[j])
                         {
                                   for(int k=0;k<n;k++)
                                   {
                                          bin[k] = (int)(j/pow(2.0,n-k-1))%2;
                                          if(bin[k] == 1)
                                                    printf("%d ", arr[k]);
                                   }
                                   printf("\n");
                                   for(int k=0;k<n;k++)
                                   {
                                          bin[k] = (int)(i/pow(2.0,n-k-1))%2;
                                          if(bin[k] == 1)
                                                    printf("%d ", arr[k]);
                                   }
                                   printf("\n");
                                   flag = 1;
                                   break;
                         }
                 }
                 if(flag == 1)
                         break;
         }
         if(flag == 0)
         printf("Impossible\n");
    }
    return 0;
}
