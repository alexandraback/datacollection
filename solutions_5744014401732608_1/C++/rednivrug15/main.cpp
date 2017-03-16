#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define N 223456

long long power( long long a,long long b)
{
    long long ret=1;
    while( b ) {
            if( b%2==1 )
                ret = ( ret*a )%mod;
            a = ( a*a )%mod;
            b /= 2;
    }
    return ret;
}

long long gcd( long long a,long long b)
{
    return b==0?a:gcd(b,a%b);
}

int main()
{
    freopen("inp.txt","r",stdin);
    freopen("op.txt","w",stdout);

    int t;
    scanf("%d",&t);

    for( int tt=1; tt<=t; tt++ )
    {
        int B;
        long long M;
        printf("Case #%d: ",tt);
        scanf("%d %lld",&B,&M);

        if( M>(1LL<<(B-2)))
        {
            printf("IMPOSSIBLE\n");
            continue;
        }
        printf("POSSIBLE\n");
        int matrix[B][B];

        for( int i=0; i<B; i++ )
        {
            for( int j=0; j<B; j++ )
                matrix[i][j]=0;
        }

        //Now i have to choose least number such that 2^x>=M
        int numberreq = 1;

        while( true )
        {
            long long ways = (1LL<<(numberreq));
            if( ways>M )
                break;
            numberreq++;
        }

        long long waysmore = M - (1LL<<(numberreq-1));

        for( int i=0; i<numberreq; i++ )
        {
            matrix[i][B-1]=1;
            for( int j=i+1; j<numberreq; j++ )
                matrix[i][j]=1;
        }

        //Now comes the question of attaching the other things

        if( waysmore!=0 )
        {
            matrix[numberreq][B-1]=1;
            int x = numberreq-2 ;

            while( waysmore>0 )
            {
                 long long newways = (1LL<<(x));

                 if( newways>waysmore )
                     x--;
                else
                {
                    waysmore -= newways;
                    matrix[x+1][numberreq]=1;
                    x--;
                }
            }

            if( waysmore==1 )
                matrix[0][numberreq]=1;
        }

        for( int i=0; i<B; i++ )
        {
            for( int j=0; j<B; j++ )
                printf("%d",matrix[i][j]);
            printf("\n");
        }
    }
    return 0;
}
