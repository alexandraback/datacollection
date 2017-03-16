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

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    for(int i = 1; i<=T; ++i)
    {
        string str;
        cin >> str;
        vector<bool> check(10,false);
        vector<int> ans;
        size_t pos;
        bool change = true;
        while(change)
        {
            change = false;
            pos = str.find('Z');
            if( pos != string::npos )
            {
                ans.PB(0);
                str.erase( pos , 1 );
                str.erase(str.find('E'),1);
                str.erase(str.find('R'),1);
                str.erase(str.find('O'),1);
                change = true;
            }
            pos = str.find('X');
            if( pos != string::npos )
            {
                ans.PB(6);
                str.erase( pos , 1 );
                str.erase(str.find('S'),1);
                str.erase(str.find('I'),1);
                change = true;
            }
            pos = str.find('G');
            if( pos != string::npos )
            {
                ans.PB(8);
                str.erase( pos , 1 );
                str.erase(str.find('E'),1);
                str.erase(str.find('I'),1);
                str.erase(str.find('H'),1);
                str.erase(str.find('T'),1);
                change = true;
            }
            pos = str.find('W');
            if( pos != string::npos )
            {
                ans.PB(2);
                str.erase( pos , 1 );
                str.erase(str.find('T'),1);
                str.erase(str.find('O'),1);
                change = true;
            }
            pos = str.find('U');
            if( pos != string::npos )
            {
                ans.PB(4);
                str.erase( pos , 1 );
                str.erase(str.find('F'),1);
                str.erase(str.find('O'),1);
                str.erase(str.find('R'),1);
                change = true;
            }
        }
        change = true;
        while(change)
        {
            change = false;
            pos = str.find('F');
            if( pos != string::npos )
            {
                ans.PB(5);
                str.erase( pos , 1 );
                str.erase(str.find('I'),1);
                str.erase(str.find('V'),1);
                str.erase(str.find('E'),1);
                change = true;
            }
            pos = str.find('R');
            if( pos != string::npos )
            {
                ans.PB(3);
                str.erase( pos , 1 );
                str.erase(str.find('T'),1);
                str.erase(str.find('H'),1);
                str.erase(str.find('E'),1);
                str.erase(str.find('E'),1);
                change = true;
            }
            pos = str.find('O');
            if( pos != string::npos )
            {
                ans.PB(1);
                str.erase( pos , 1 );
                str.erase(str.find('N'),1);
                str.erase(str.find('E'),1);
                change = true;
            }
            pos = str.find('S');
            if( pos != string::npos )
            {
                ans.PB(7);
                str.erase( pos , 1 );
                str.erase(str.find('E'),1);
                str.erase(str.find('V'),1);
                str.erase(str.find('E'),1);
                str.erase(str.find('N'),1);
                change = true;
            }
        }
        change = true;
        while(change)
        {
            change = false;
            pos = str.find('N');
            if( pos != string::npos )
            {
                ans.PB(9);
                str.erase( pos , 1 );
                str.erase(str.find('I'),1);
                str.erase(str.find('N'),1);
                str.erase(str.find('E'),1);
                change = true;
            }
        }
        sort( ALL(ans) );
        cout << "Case #" << i << ": ";
        FOR(i,SZ(ans))
        {
            cout << ans[i];
        }
        cout << endl;
    }
    return 0;
}
