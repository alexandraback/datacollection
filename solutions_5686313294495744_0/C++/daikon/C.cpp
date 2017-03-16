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

typedef pair<string,string> pss;

void process()
{
    map<string,int> M1,M2;
    int N;
    cin >> N;
    int count1 = 0, count2 = 0;
    FOR(i,N)
    {
        string tmp;
        cin >> tmp;
        //all1.PB(tmp);
        if( !M1.count(tmp) ) M1[tmp] = count1++;
        cin >> tmp;
        if( !M2.count(tmp) ) M2[tmp] = count2++;
        //all2.PB(tmp);
    }
    int max = (count1>count2)?count1:count2;
    cout << "Case #" << ii << ": " << N-max << endl;
    /*
    bool table[count1][count2];
    FOR(i,count1)
    {
        FOR(j,count2)
        {
            table[i][j] = false;
        }
    }
    FOR(i,n)
    {
        table[M1[all1[i]]][M2[all2[i]]] = true;
    }
    */
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    for(ii = 1; ii<=T; ++ii)
    {
        process();
    }
    return 0;
}
