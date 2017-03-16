//Krzysztof Pieprzak
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define Size(x) (int)x.size()
#define VAR(v,n) auto v = (n)
#define FOR(i,a,b) for(VAR(i,a); i < (b); ++i)
#define FORE(i,a,b) for(VAR(i,a); i <= (b); ++i)
#define FORREV(i,a,b) for(VAR(i,b); i >= (a); --i)
#define FORSTEP(i,a,b,step) for(VAR(i,a); i < (b); i += (step))
#define FOREACH(i,c) for(auto i : (c))
#define FOREACHS(i,c,n) for(VAR(i,&(c)[0]); i-(c)<(n); ++i)
#define ALL(x) x.begin(),x.end()
#define CLEAR(t) memset(t, 0, sizeof(t))
#define F first
#define S second
#define MP make_pair
#define PUB push_back
#define POB pop_back
#define pieprzu ios_base::sync_with_stdio(0);

const int    INF = 1000000001;
const double EPS = 10e-9;

const int SIZE = 2000;

char s[SIZE + 5];
int lettersCnts[1000];
int digitsCnts[1000];

void removeLetters(string ss, int n, int x) {
    FOR (i, 0, n) {
        lettersCnts[ss[i]] -= x;
    }
}

void processDigit(char letter, string ss, int n, int digit) {
    digitsCnts[digit] += lettersCnts[letter];
    removeLetters(ss, n, lettersCnts[letter]);
}

void rob(int test) {
    scanf("%s", s);
    int n = strlen(s);

    FOR (i, 0, 500) {
        lettersCnts[i] = digitsCnts[i] = 0;
    }

    FOR (i, 0, n) {
        ++lettersCnts[s[i]];
    }

    processDigit('Z', "ZERO", 4, 0);
    processDigit('W', "TWO", 3, 2);
    processDigit('X', "SIX", 3, 6);
    processDigit('G', "EIGHT", 5, 8);
    processDigit('H', "THREE", 5, 3);
    processDigit('S', "SEVEN", 5, 7);
    processDigit('R', "FOUR", 4, 4);
    processDigit('V', "FIVE", 4, 5);
    processDigit('O', "ONE", 3, 1);
    processDigit('I', "NINE", 4, 9);

    printf("Case #%d: ", test);
    FOR (i, 0, 10) {
        FOR (j, 0, digitsCnts[i]) {
            printf("%d", i);
        }
    }
    printf("\n");
}

int main() {
    int test = 1;
    scanf("%d", &test);

    FORE (i, 1, test) rob(i);

    return 0;
}
