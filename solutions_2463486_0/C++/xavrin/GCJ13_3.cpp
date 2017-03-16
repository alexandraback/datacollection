#include <cstdio>
#include <utility>
#include <queue>
#include <set>
#include <list>
#include <map>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
typedef vector<int> VI;
typedef long long LL;
#define FOR(x, b, e) for(int x=b; x<=(e); ++x)
#define FORD(x, b, e) for(int x=b; x>=(e); ––x)
#define REP(x, n) for(int x=0; x<(n); ++x)
#define VAR(v,n) typeof(n) v=(n)
#define ALL(c) c.begin(),c.end()
#define SIZE(x) (int)x.size()
#define FOREACH(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second
#define MP make_pair
#define PII pair<int, int>

const LL N = 100000000000000;

LL kwad[10000000];
LL counter = 0;
char tab[30];

LL Sqr (LL x){
    LL k = 1;
    while (k * k < x){
        k++;
    }
    return k;
}

bool isPal (LL x){
    int size = 0;
    while ( x > 0){
        tab[size] = x % 10;
        x /= 10;
        size++;
    }
    bool t = true;
    for (int i = 0; i < size; i++)
        if (tab[i] != tab[size-1-i])
            t = false;
    return t;
}

void preproc(){
    LL d = 1LL;
    LL odd = 3LL;
    while (d <= N){
        if (isPal(d) && isPal(Sqr(d)))
            kwad[counter++] = d;
        d += odd;
        odd += 2LL;
    }
}

int how_many (LL x){
    int i = 0;
    while (i < counter && x >= kwad[i])
        i++;
    return i;
}

int main(){
    preproc();
    int T;
    scanf("%d", &T);
    LL a, b;
    FOR(k, 1, T){
        scanf("%lld %lld", &a, &b);
        printf("Case #%d: %d\n", k, how_many(b) - how_many(a-1));
    }
    return 0;
}
