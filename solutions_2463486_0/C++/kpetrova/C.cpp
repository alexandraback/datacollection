#include <iostream>

using namespace std;

int ts[32];

long long calc(long long x)
{
    if ( x == 0 ) return 0;
    
    long long i=1,j,g,br,oth,eq,num,flag,brr=0,oth1,eq1,l,numnum;
    do
    {
        br = 0;
        eq = 1;
        oth = i;
        while (oth)
        {
            br++;
            oth /= 10;
            eq *= 10;
        }
        
        oth = i;
        
        oth1 = oth;
        eq1 = eq;
        
        for ( l=0; l<2; l++ )
        {
        
            if ( l&1 ) 
            { 
                oth = oth1/10;
                eq = eq1/10;
            }
            
            g = i*eq;
            eq/=10;
            
            while (oth)
            {
                g += (oth%10)*eq;
                eq /= 10;
                oth /= 10;
            }
            
            num = g*g;
            numnum = num;
            
            ts[0] = 0;
            while ( num )
            {
                ts[0]++;
                ts[ ts[0] ] = num%10;
                num/=10;
            }
                            
            flag = 0;
            for ( j=1; j<=ts[0]; j++ )
                if ( ts[j] != ts[ ts[0] + 1 - j ] ) flag = 1;
            if ( !flag && numnum <= x ) brr++; 
        }
        
        i++;
        
    }
    while ( g*g <= x );
    
    return brr;
}

int main()
{
    int t;
    cin >> t;
    
    long long ans;
    
    for ( int tt=1; tt<=t; tt++ )
    {
        long long a,b;
        cin >> a >> b;
        ans = calc(b) - calc(a-1);
        cout << "Case #" << tt << ": " << ans << endl;
    }
}