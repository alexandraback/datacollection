#include<bits/stdc++.h>
using namespace std;
int a[1005] ;
int main()
{
    int T , step = 0 ;
    int n,t,i ,j,max1,min1,sum ;
    scanf("%d", &T) ;
    for(t=1;t<=T;t++)
    {
        scanf("%d",&n) ;
        max1=INT_MIN;
        for(i = 0 ; i < n ; i++)
        {
            scanf("%d", &a[i]);
            max1 = max(max1,a[i]) ;
        }
        min1 = max1 ;
        for(i = 1 ; i <= max1 ; i++)
        {
            sum = i ;
            for(j = 0 ; j < n ; j++)
            {
                if( a[j] > i )
                {
                    if( a[j]%i == 0 )
                        sum += (a[j]/i -1);
                    else
                        sum += (a[j]/i);
                }
            }
            min1 = min(min1,sum) ;
        }
        printf("Case #%d: %d\n",t, min1) ;
    }
    return 0 ;
}
