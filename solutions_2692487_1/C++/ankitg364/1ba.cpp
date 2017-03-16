#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<map>
#include<math.h>
#include<climits>
using namespace std;

int main()
{
    long long t, a, n, arr[200], answ, temp1, temp2;
    scanf("%lld",&t);
    for(int c=1; c<=t; c++)
    {
        answ=2000;
        scanf("%lld%lld", &a, &n);
        for(int i=0; i<n; i++)
            scanf("%lld",&arr[i]);
        sort(arr, arr+n);
        for(int i=0; i<=n; i++)
        {
            temp1=a;
            temp2=(n-i);
            for(int j=0; j<i; )
            {
                if(temp1>arr[j])
                {
                    temp1+=arr[j];
                    j++;
                }
                else
                {
                    temp2++;
                    temp1+=temp1-1;
                    if(temp1==1)
                    {
                        temp2+=110;
                        break;
                    }
                }
            }
            answ=min(temp2, answ);
        }
        printf("Case #%d: %lld\n", c, answ);
    }
    return 0;
}
