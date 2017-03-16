#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#define forn(a,b) for(int a = 0; a < int(b); ++a)
#define forr(a,c,b) for(int a = int(c); a < int(b); ++a)
using namespace std;
typedef long long ll;
const int maxn = 1024;

int T, N;
map<int, int> S;

int main(){
    freopen("entrada.txt", "r", stdin);
    freopen("salida.txt", "w", stdout);
    int x;

    scanf("%i", &T);
    forn(t, T){
        S.clear();
        scanf("%i", &N);
        forn(i, 2*N-1)
            forn(j, N){
                scanf("%i", &x);
                ++S[x];
            }
        printf("Case #%i:", t+1);
        for(auto &c: S) if( c.second%2 ) printf(" %i", c.first); putchar('\n');
    }

    return 0;
}
