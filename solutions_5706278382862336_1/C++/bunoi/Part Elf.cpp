#include<cstdio>
#include<iostream>

using namespace std;

long long x,y,g;

long long gcd ( long long a , long long b )
{
    long long t;
    while ( b != 0 )
    {
        t = b;
        b = a%b;
        a = t;
    }
    return a;
}

long long ch[50];

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.txt","w",stdout);
    int T;
    scanf("%d",&T);
    ch[0] = 1;
    for ( int c=1 ; c<=40 ; c++ )   ch[c] = ch[c-1] * 2;
    for ( int X=1 ; X<=T ; X++ )
    {
        scanf("%I64d/%I64d",&x,&y);
        printf("Case #%d: ",X);
        g = gcd ( x , y );
        x /= g , y/=g;
        for ( int c=0 ; c<=40 ; c++ )
        {
            if ( ch[c] == y )   goto bun;
        }
        printf("impossible\n");
        continue;
        bun:;
        int d;
        double xx;
        for (  d=1 ; d<=40 ; d++ )
        {
            xx = (double) x/y;
            if ( xx >= 0.5 )
            {
                printf("%d\n",d);
                goto e2;
            }
            y/=2;
        }
        printf("impossible\n");
        e2:;
    }
}
