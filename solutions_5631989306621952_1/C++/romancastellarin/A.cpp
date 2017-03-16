#include<iostream>
#include<cstdio>
#include<algorithm>
#include<deque>
#define forn(a,b) for(int a = 0; a < int(b); ++a)
#define forr(a,c,b) for(int a = int(c); a < int(b); ++a)
using namespace std;
typedef long long ll;
const int maxn = 1024;

int T;
char S[maxn];
deque<char> Q;

void dp(int n){
    if( n == 0 ){
        Q.push_back(S[0]);
        return;
    }
    dp(n-1);
    if(S[n] >= Q[0] ) Q.push_front(S[n]); else Q.push_back(S[n]);
}

int main(){
    freopen("entrada.txt", "r", stdin);
    freopen("salida.txt", "w", stdout);

    scanf("%i", &T);
    forn(t, T){
        scanf("%s", S);
        Q.clear();
        int n = 0; while( S[n] ) ++n;
        dp( n-1 );
        printf("Case #%i: ", t+1);
        for(auto &c: Q) printf("%c", c); putchar('\n');
    }

    return 0;
}
