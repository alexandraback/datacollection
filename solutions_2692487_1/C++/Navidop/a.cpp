#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    
    for( int tt=1; tt<=t; tt++ )
    {
        int n, a, num[200];
        scanf("%d%d", &a, &n);
        for( int i=0; i<n; i++ )
            scanf("%d", &num[i] );
        
        sort( num, num+n);
        
        int best = n;
        int cur = 0;
        for( int i=0; i<n; i++ )
        {
            if( num[i] < a )
                a += num[i];
            else
            {
                if( best > cur + n-i )
                    best = cur + n-i;
                cur++;
                a += a-1;
                i--;
            }

            if( cur > best )
                break;
        }
        if( best > cur )
            best = cur;
        
        printf("Case #%d: %d\n", tt, best);
    }
}