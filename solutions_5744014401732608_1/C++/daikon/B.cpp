#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long double LD;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef pair<LD,LD> PLD;

#define FI first
#define SE second
#define PB push_back
#define MP make_pair
#define ALL(x) (x).begin(), (x).end()

vector<bool> table(2501,false);

long long int mypow( long long int p )
{
    long long int rtn = 1;
    while(p--) { rtn *= 2; }
    return rtn;
}

int main()
{  
    int T;
    scanf("%d",&T);
    for(int ii = 1; ii<=T; ++ii)
    {
        long long int B,M;
        scanf("%lld %lld",&B,&M);
        if( B == 2 )
        {
            if( M != 1 )
                printf("Case #%d: IMPOSSIBLE\n",ii);
            else
            {
                printf("Case #%d: POSSIBLE\n",ii);
                printf("01\n00\n");
            }
            continue;
        }
        if( mypow(B-2) < M )
        {
            printf("Case #%d: IMPOSSIBLE\n",ii);
            continue;
        }
        printf("Case #%d: POSSIBLE\n",ii);
        long long int sum = 1;
        int p = 0;
        for( ; p<B; ++p)
        {
            long long int tmp = mypow(p);
            if( sum + tmp > M ) break;
            sum += tmp;
        }
        p += 1;
        //cout << "p: " << p << endl; 
        long long int diff = M-sum;
        vector<int> bit;
        long long int one = 1;
        for(int i = 63; i>=0; --i)
        {
            if( diff & (one<<i) ) bit.PB( i+2 );
        }
        for(int i = 1; i<B; ++i)
        {
            for(int j = 1; j<=B; ++j)
            {
                if( j == B && i == p+1 ) printf("1");
                else if( j <= i ) printf("0");
                else if( j <= p+1 ) printf("1");
                else if ( !bit.empty() && bit.back() == i && j == B ) printf("1"), bit.pop_back();
                else printf("0");
            }
            puts( "" );
        }
        for(int i = 1; i<=B; ++i) printf("0");
        puts( "" );
    }  
}


