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
        int J,P,S,K;
        scanf("%d %d %d %d",&J,&P,&S,&K);
        printf("Case #%d: ",tt);
        printf("%d\n",min(J*P*S,J*P*K));

        if( J*P*S<=J*P*K )
        {
            for( int i=1; i<=J; i++ )
            {
                for( int j=1; j<=P; j++ )
                {
                    for( int k=1; k<=S; k++ )
                        printf("%d %d %d\n",i,j,k);
                }
            }
        }


        else
        {
            map < pair < int , int > , int  > X,Y,Z;
            int x=0,y=0,z=0;

            for( int i=1; i<=J*P*K; i++ )
            {
                int A = X[mp(x,y)];
                int B = Y[mp(y,z)];
                int C = Z[mp(z,x)];

                if( A>=K )
                {
                     x = (x+1)%J;
                }
                else if( B>=K )
                {
                     z = (z+1)%S;
                }
                else if( C>=K )
                {
                     z = (z+1)%S;
                }


                printf("%d %d %d\n",x+1,y+1,z+1);
                A = X[mp(x,y)];
                B = Y[mp(y,z)];
                C = Z[mp(z,x)];

                //cerr<<J<<" "<<P<<" "<<S<<" "<<K<<endl;
                //cerr<<x<<" "<<y<<" "<<z<<" "<<K<<endl;

                assert(A<K);
                assert(B<K);
                assert(C<K);



                X[mp(x,y)]++;
                Y[mp(y,z)]++;
                Z[mp(z,x)]++;

                x = (x+1)%J;
                z = (z+1)%S;

                if( x==0 )
                    y=(y+1)%P;
            }
        }
    }
    return 0;
}
