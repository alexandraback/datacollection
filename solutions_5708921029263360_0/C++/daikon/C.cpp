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


int main()
{  
    int T;
    scanf("%d",&T);
    for(int ii = 1; ii<=T; ++ii)
    {
        int J,P,S,K;
        scanf("%d %d %d %d",&J,&P,&S,&K);
        bool tab[J][P][S];
        for(int j = 0; j<J; ++j)
            for(int p = 0; p<P; ++p)
                for(int s = 0; s<S; ++s)
                    tab[j][p][s] = false;
        int ansc = 0;
        for(int j = 0; j<J; ++j)
        {
            for(int p = 0; p<P; ++p)
            {
                for(int s = 0; s<S; ++s)
                {
                    if( tab[j][p][s] ) continue;
                    int c1 = 0, c2 = 0, c3 = 0;
                    for(int jj = 0; jj<J; ++jj)
                    {
                        if( tab[jj][p][s] ) ++c1;
                    }
                    for(int pp = 0; pp<P; ++pp)
                    {
                        if( tab[j][pp][s] ) ++c2;
                    }
                    for(int ss = 0; ss<S; ++ss)
                    {
                        if( tab[j][p][ss] ) ++c3;
                    }
                    if( c1 < K && c2 < K && c3 < K )
                    {
                        tab[j][p][s] = true;
                        ++ansc;
                    }
                }
            }
        }
        printf("Case #%d: %d\n",ii,ansc);
        for(int j = 0; j<J; ++j)
        {
            for(int p = 0; p<P; ++p)
            {
                for(int s = 0; s<S; ++s)
                {
                    if( tab[j][p][s] )
                        printf("%d %d %d\n",j+1,p+1,s+1);
                }
            }
        }
    }
}

