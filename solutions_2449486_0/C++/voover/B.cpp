#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <cmath>
#include <cstring>
#include <string>
#include <iostream>
#include <complex>
#include <sstream>
using namespace std;
 
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef vector<int> VI;
typedef pair<int,int> PII;
 
#define REP(i,n) for(int i=0;i<(n);++i)
#define SIZE(c) ((int)((c).size()))
#define FOR(i,a,b) for (int i=(a); i<(b); ++i)
#define FOREACH(i,x) for (__typeof((x).begin()) i=(x).begin(); i!=(x).end(); ++i)
#define FORD(i,a,b) for (int i=(a)-1; i>=(b); --i)
#define ALL(v) (v).begin(), (v).end()
 
#define pb push_back
#define mp make_pair
#define st first
#define nd second

int grass[500][500];
bool activerow[500], activecol[500];

void scase() {    
    int N,M;
    scanf("%d%d",&N,&M);
    REP(i,N)REP(j,M) scanf("%d",&grass[i][j]);
    REP(i,N) activerow[i] = true;
    REP(i,M) activecol[i] = true;
    
    vector<pair<int,PII> > V;
    REP(i,N)REP(j,M) V.push_back(mp(grass[i][j], PII(i,j)));

    sort(V.begin(), V.end());
    REP(k,N*M) {
        int x = V[k].nd.st;
        int y = V[k].nd.nd;
        if (!activerow[x] || !activecol[y]) continue;
        REP(y0,M) if (grass[x][y0] > grass[x][y]) goto fail;
        activerow[x] = false;
        continue;
        fail:;
        
        REP(x0,N) if (grass[x0][y] > grass[x][y]) {
            printf("NO\n");
            return;
        }
        activecol[y] = false;        
    }
    printf("YES\n");
}

int main() {
    int C;
    scanf("%d",&C);
    FOR(i,1,C+1) {
        printf("Case #%d: ", i);
        scase();
    }
}  
