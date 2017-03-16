#include <iostream>
#include <stdio.h>

using namespace std;

double dyna[2500][2500];

void calc()
{
    dyna[0][0] = 1;
    for( int i=0; i<2500; i++)
        for( int j=0; j<2500; j++ )
        {
            double temp = dyna[i][j]/2;
            dyna[i+1][j] += temp;
            dyna[i][j+1] += temp;
        }
}

int main()
{
    //calc();
    int t;
    scanf("%d", &t);
    for( int tt=1; tt<=t; tt++ )
    {
        int n, x, y;
        scanf("%d%d%d", &n, &x, &y);
        
        if( (x+y)%2 == 1 )
        {
            printf("Case #%d: 0.0\n", tt);
            continue;
        }
        
        if( x < 0 )
            x = -x;
        
        int step = (x+y)/2;
        int ns = 1, cnt=0;
        int total=0;
        while(total+ns < n)
        {
            total += ns;
            ns += 4;
            cnt++;
        }
        
        int rem = n - total;
        //printf("## %d\n", rem);

        if( cnt > step || (cnt==step && ( (x!=0 && rem > ns/2+y) || rem >= ns ) ) )
        {
            //printf("++ %d %d %d %d\n", cnt, step, rem, ns);
            printf("Case #%d: 1.0\n", tt);
            continue;
        }
        else if( cnt < step || (cnt==step && (rem<=y || (x==0 && rem < ns))) )
        {
            printf("Case #%d: 0.0\n", tt);
            continue;
        }
        else
        {
            double ans=0;
            for( int i=0; i<=ns/2+10; i++ )
                for( int j=0; j<=ns/2+10; j++ )
                    dyna[i][j] = 0;
            dyna[0][0] = 1.0;
            for( int i=0; i<=ns/2; i++ )
                for( int j=0; j<=ns/2 && i+j<=rem; j++ )
                {
                    if( i+j < rem )
                    {
                        double temp = dyna[i][j]/2;
                        if( i<ns/2 )
                            dyna[i+1][j] += temp;
                        else dyna[i][j+1] += temp;
                        
                        if( j<ns/2 )
                            dyna[i][j+1] += temp;
                        else dyna[i+1][j] += temp;
                    }
                    
                    if( i > y && i+j==rem )
                    {
                        //printf("@@ %d %d %lf\n", i, j, dyna[i][j]);
                        ans += dyna[i][j];
                    }
                }
                    
/*            double ans = 0;
            
            int x1=rem-y, y1=y;
            if( x1 > ns/2 )
            {
                
            }
            else ans += dyna[x1][y1];
            
            for( y1++,x1--; y1<=ns/2 && y1<rem; y1++,x1--)
            {
                ans += dyna[x1][y1];
            }*/
            
            printf("Case #%d: %.8lf\n", tt, ans);
        }
    }
    
    return 0;
}