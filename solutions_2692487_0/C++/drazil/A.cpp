#include <cstdio>
#include <set>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std ;

int s[110] ;

int main(void)
{
    int tc, cas ;
    
    scanf("%d",&tc) ;
    for(cas=1;cas<=tc;cas++)
    {
        int ans ;
        int n ;
        int a ;
        int i ;
        int cans ;
        
        scanf("%d%d",&a,&n) ;
        ans = n ;
        for(i=0;i<n;i++)
        {
            scanf("%d",&s[i]) ;
        }
        
        sort(s,s+n) ;
        
        cans = 0 ;
        for(i=0;i<n;i++)
        {
            if(cans+n-i<ans) ans = cans+n-i ;
            if(a>s[i]) a += s[i] ;
            else
            {
                cans++ ;
                a += a-1 ;
                if(a>2000000) a = 2000000 ;
                i-- ;
                if(a==1) break ;
            }
        }
        if(cans+n-i<ans) ans = cans+n-i ;

        printf("Case #%d: %d\n",cas,ans) ;
    }
    
    return 0;
}
