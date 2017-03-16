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

const int SIZE = 3;

char C[SIZE+5];
char J[SIZE+5];

int bestC = -1;
int bestJ = -1;
int bestDiff = -1;

int getNumber(char *s, int n) {
    int num = 0;
    FOR (i, 0, n) {
        num = num * 10 + (s[i] - '0');
    }

    return num;
}

void updateResult(int n) {
    int c = getNumber(C, n);
    int j = getNumber(J, n);
    int diff = abs(c-j);

    if (bestDiff == -1 || diff < bestDiff || (diff == bestDiff && c < bestC) || (diff == bestDiff && c == bestC && j < bestJ)) {
        bestC = c;
        bestJ = j;
        bestDiff = diff;
    }
}

void fun(int pos, int n) {
    if (pos == n) {
        updateResult(n);
        return;
    }

    if (C[pos] == '?') {
        FOR (i, 0, 10) {
            C[pos] = i + '0';
            fun(pos, n);
        }
        C[pos] = '?';
        return;
    }

    if (J[pos] == '?') {
        FOR (i, 0, 10) {
            J[pos] = i + '0';
            fun(pos, n);
        }
        J[pos] = '?';
        return;
    }

    fun(pos+1, n);
}

void printNumber(int x, int n) {
    char s[n+1];
    s[n] = 0;
    while (n--) {
        s[n] = (x%10) + '0';
        x /= 10;
    }
    printf("%s", s);
}

void rob(int test) {
    scanf("%s %s", C, J);
    int n = strlen(C);

    bestC = bestJ = bestDiff = -1;
    fun(0, n);
    printf("Case #%d: ", test);
    printNumber(bestC, n);
    printf(" ");
    printNumber(bestJ, n);
    printf("\n");
}

int main() {
    int test = 1;
    scanf("%d", &test);

    FORE (i, 1, test) rob(i);

    return 0;
}
