#include <string>
#include <cstring>
#include <vector>
#include <cmath> 
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <utility>
#include <sstream>
#include <iostream>
 
using namespace std;
 
#define REP(a,n) for(int a=0; a<(n); ++a)
#define FOR(a,b,c) for(int a=(b); a<=(c); ++a)
#define INIT(a, v) __typeof(v) a = (v)
#define FOREACH(a, v) for (INIT(a, (v).begin()); a!=(v).end(); ++a)
 
template<class T>
inline int size(const T&t){return t.size();}
 
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef long long LL;

#define INF 1000000000
#define PB push_back
#define MP make_pair
 
//////////////////////////////////////////

char buf[3000];

int ile[300];

char napisy[10][20] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

int res[10];

void wynik(int c, int z) {
    res[c] = ile[z];
    int len = strlen(napisy[c]);
    REP(x, len)
        ile[napisy[c][x]] -= res[c];
}

void licz() {
    scanf("%s", buf);
    REP(a, 300)
        ile[a] = 0;
    int len = strlen(buf);
    REP(a, len)
        ++ile[buf[a]];
    wynik(0, 'Z');
    wynik(6, 'X');
    wynik(4, 'U');
    wynik(3, 'R');
    wynik(8, 'G');
    wynik(5, 'F');
    wynik(7, 'S');
    wynik(2, 'W');
    wynik(9, 'I');
    wynik(1, 'O');
    REP(a, 10)
        REP(b, res[a])
            printf("%d", a);
    printf("\n");
}


int main() {
    int TT;
    scanf("%d", &TT);
    REP(tt, TT) {
        printf("Case #%d: ", (tt+1));
        licz();
    }
}


