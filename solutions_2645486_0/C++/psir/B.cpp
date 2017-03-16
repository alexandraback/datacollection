#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <cstdlib>
#include <string>
#include <sstream>

using namespace std;

#define VS vector<string>
#define VI vector<int>
#define VVI vector< VI >
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORC(it,kont) for(__typeof((kont).begin()) it = (kont).begin(); it!=(kont).end(); ++it)

char buff[20000];
//long long dp[10001][10001];

long long E, R, N;
vector<long long> v;

long long solve( long long p, long long e, long long se, long long fe )
    {
    long long sol = 0;
    //long long& sol = dp[p][e];
    //if( sol != - 1) return sol;
    if( p == e ) return 0;
    long long pos;
    long long tmx = -1;
    //cout << p << " " << e << endl;
    FOR(i,p,e)
        {
        if(tmx < v[i])
            { tmx = v[i]; pos = i; }
        }
    //cout << tmx << " " << pos << endl;
    //system("pause");
    long long mx = max( fe-(e-pos)*R, 0LL );
    if( se + (pos - p)*R <= mx )
        sol = 0;
    else if( se + (pos - p)*R <= E )
        sol = max(se + (pos-p)*R - mx, 0LL)*tmx + solve(pos+1,e,mx+R,fe);
    else
        sol = solve(p,pos,se,E) + solve(pos+1,e,mx+R,fe) + min(se + (pos - p)*R - mx,E-mx)*tmx;
    //cout << p << " " << e << " " << tmx << " "<< sol<< endl;
    return sol;
    }

int main()
    {
    int T;
    gets(buff);
    sscanf(buff,"%d",&T);

    FOR( t, 0, T )
        {
        long long sol = 0;        
        cin >> E>> R >> N;
        v.resize(N);
        FOR(i,0,N) cin >> v[i];
        //memset(dp,-1,sizeof(dp));

        sol = solve(0,N,E,0);

        printf("Case #%d: %d\n",t+1,sol);
        }
    return 0;
    }
