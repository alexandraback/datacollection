#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long double LD;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef pair<LD,LD> PLD;

#define FOR(i, n) for(int i = 0; i<(n); ++i)
#define FOR1(i, n) for(int i = 1; i<=(n); ++i)
#define FORR(i, m, n) for(int i = (m); i<(n); ++i)

#define SD(X) scanf("%d", &(X))
#define SDD(X, Y) scanf("%d%d", &(X), &(Y))
#define SDDD(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))

#define DSD(X) long long int (X); scanf("%d", &X)
#define DSDD(X, Y) long long int X, Y; scanf("%d%d", &X, &Y)
#define DSDDD(X, Y, Z) long long int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)

#define SLLD(X) scanf("%lld", &(X))
#define SLLDD(X, Y) scanf("%lld%lld", &(X), &(Y))
#define SLLDDD(X, Y, Z) scanf("%lld%lld%lld", &(X), &(Y), &(Z))

#define SS(X) scanf("%s", (X))

#define NL printf("\n")
#define PC(X) printf("%c\n",(X))
#define PD(X) printf("%d\n",(X))
#define PDD(X, Y) printf("%d %d\n", (X), (Y))
#define PDDD(X, Y, Z) printf("%d %d %d\n", (X), (Y), (Z))

#define PB push_back
#define MP make_pair

#define VI vector<int>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long> >

#define F first
#define S second

#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()

int ii = 0;

void process()
{
    string s1, s2;
    cin >> s1;
    getchar();
    cin >> s2;
    int n = s1.length();
    bool first_time = true;
    int compare = 0;
    vector<int> pos;
    vector<string> all1, all2;
    FOR(i,n)
    {
        if( s1[i] == '?' )
        {
            if( first_time )
            {
                for(int j = 0; j<10; ++j)
                {
                    string tmp = s1;
                    tmp[i] = (char)(j+48);
                    all1.PB(tmp);
                }
                first_time = false;
            }
            else
            {
                for(int j = 0, nn = all1.size(); j<nn; ++j)
                {
                    string tmp = all1[0];
                    for(int k = 0; k<10; ++k)
                    {
                        tmp[i] = (char)(k+48);
                        all1.PB(tmp);
                    }
                    all1.erase(all1.begin());
                }
            }
        }
    }
    if( all1.empty() ) all1.PB(s1);
    first_time = true;
    FOR(i,n)
    {
        if( s2[i] == '?' )
        {
            if( first_time )
            {
                for(int j = 0; j<10; ++j)
                {
                    string tmp = s2;
                    tmp[i] = (char)(j+48);
                    all2.PB(tmp);
                }
                first_time = false;
            }
            else
            {
                for(int j = 0, nn = all2.size(); j<nn; ++j)
                {
                    string tmp = all2[0];
                    for(int k = 0; k<10; ++k)
                    {
                        tmp[i] = (char)(k+48);
                        all2.PB(tmp);
                    }
                    all2.erase(all2.begin());
                }
            }
        }
    }
    if( all2.empty() ) all2.PB(s2);
    int min = 1000, ansi, ansj;
    sort( ALL(all1) );
    sort( ALL(all2) );
    FOR(i,SZ(all1))
    {
        FOR(j,SZ(all2))
        {
            int diff_sum = 0;
            FOR(k,n)
            {
                if( k == 0 ) diff_sum += (all1[i][k]-all2[j][k])*100;
                else if( k == 1 ) diff_sum += (all1[i][k]-all2[j][k])*10;
                else if( k == 2 ) diff_sum += (all1[i][k]-all2[j][k]);
            }
            diff_sum = abs(diff_sum);
            if( diff_sum < min ) min = diff_sum, ansi = i, ansj = j;
        }
    }
    cout << "Case #" << ii << ": " << all1[ansi] << " " << all2[ansj] << endl;
    //printf("Case #%d: %s %s\n",ii,all1[ansi],all2[ansj]);
}

int main()
{//ios_base::sync_with_stdio(0); cin.tie(0);
    
    DSD(T);
    for(ii = 1; ii<=T; ++ii)
    {
        process();
    }
    return 0;
}
