#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#define forn(a,b) for(int a = 0; a < int(b); ++a)
#define forr(a,c,b) for(int a = int(c); a < int(b); ++a)
using namespace std;
typedef long long ll;
const int maxn = 1024;

enum { UNVISITED = 0, VISITING, DONE };

int T, N, R, BFF, A, B, S;
vector<int> V, G[maxn];
int P[maxn], D[maxn];

void f(int v, int d){
    if( V[v] != UNVISITED ) return;
    V[ v ] = VISITING;
    D[ v ] = d;
    int w = P[ v ];
    if( V[ w ] == VISITING ) R = max(R, d - D[ w ] + 1);
    else if( V[ w ] == UNVISITED ) f(w, d+1);
    V[ v ] = DONE;
}

int LongPath(int v, int p, int d){
   int s = d;
   for( auto &w : G[v] )
        if( w != p ) s = max(s, LongPath(w, v, d+1));
   return s;
}

int main(){
    freopen("entrada.txt", "r", stdin);
    freopen("salida.txt", "w", stdout);
    int x;

    scanf("%i", &T);
    forn(t, T){
        scanf("%i", &N);

        V.clear(); R = 0; BFF = 0, S = 0;
        V.resize(N+1, UNVISITED);
        forn(v, N) G[v].clear();

        forn(i, N){
            D[i] = 0;
            scanf("%i", P+i);
            --P[i];
            G[ P[i] ].push_back( i );
        }
        forn(i, N)
            if( i == P[ P[i] ] )
                S += LongPath(i, P[i], 1) + LongPath(P[i], i, 1);
        S /= 2;
        forn(v, N) f(v, 0);
        printf("Case #%i: %i\n", t+1, max(R, S));
        //return 0;
    }

    return 0;
}
