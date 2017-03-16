
#include <bits/stdc++.h>

#define FOR(i,b,e) for(int i=(b); i <= (e); ++i)
#define FORD(i,b,e) for(int i=(b); i >= (e); --i)
#define SIZE(c) (int) (c).size()
#define FORE(i,c) FOR(i,0,SIZE(c)-1)
#define FORDE(i,c) FORD(i,SIZE(c)-1,0)
#define PB push_back
#define MP make_pair
#define ST first
#define ND second

using namespace std;

typedef long long int LLI;
typedef pair < int , int > PII;
typedef pair < LLI , LLI > PLL;

typedef vector < int > VI;
typedef vector < bool > VB;
typedef vector < PII > VP;
typedef vector < LLI > VL;
typedef vector < PLL > VPL;

typedef vector < VI > VVI;
typedef vector < VL > VVL;
typedef vector < VB > VVB;
typedef vector < VP > VVP;

const int MOD = 1000000007;
const int INF = 1000000001;
const LLI LLINF = 1000000000000000001LL;

/*************************************************************************/

string bestX, bestY;

LLI abs(string x, string y) {
    return abs(atoll(x.c_str()) - atoll(y.c_str()));
}

void see(string x, string y) {
    bool better = false;

    if (bestX == "") {
        better = true;
    } else if (abs(x,y) < abs(bestX,bestY)) {
        better = true;
    } else if (abs(x,y) == abs(bestX,bestY)) {
        if (x < bestX || (x == bestX && y < bestY)) {
            better = true;
        }
    }

    if (better) {
        bestX = x;
        bestY = y;
    }
}

void solve(string a, string b, bool firstSmaller) {
    int n = SIZE(a);

    FOR(eq,0,n) {
        string na = a, nb = b;
        bool possible = true;

        FOR(i,0,eq-1) {
            if (na[i] != '?' && nb[i] != '?' && na[i] != nb[i]) {
                possible = false;
                break;
            }

            if (na[i] == '?' && nb[i] == '?') {
                na[i] = nb[i] = '0';
            } else if (na[i] != '?') {
                nb[i] = na[i];
            } else {
                na[i] = nb[i];
            }
        }

        if (!possible) continue;

        if (eq < n) {
            if (na[eq] == '?' && nb[eq] == '?') {
                na[eq] = '0';
                nb[eq] = '1';

                if (!firstSmaller) swap(na[eq], nb[eq]);
            } else if (na[eq] != '?' && nb[eq] == '?') {
                if (firstSmaller) nb[eq] = na[eq] + 1;
                else nb[eq] = na[eq] - 1;

                if (nb[eq] < '0' || nb[eq] > '9') continue;
            } else if (nb[eq] != '?' && na[eq] == '?') {
                if (firstSmaller) na[eq] = nb[eq] - 1;
                else na[eq] = nb[eq] + 1;

                if (na[eq] < '0' || na[eq] > '9') continue;
            } else {
                if (firstSmaller && na[eq] >= nb[eq]) continue;
                if (!firstSmaller && na[eq] <= nb[eq]) continue;
            }
        }

        FOR(i,eq+1,n-1) {
            if (firstSmaller) {
                if (na[i] == '?') na[i] = '9';
                if (nb[i] == '?') nb[i] = '0';
            } else {
                if (na[i] == '?') na[i] = '0';
                if (nb[i] == '?') nb[i] = '9';
            }
        }

        see(na, nb);
    }
}

/*************************************************************************/

int main() {
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;

    FOR(i,1,t) {
        string a, b;
        cin >> a >> b;

        bestX = bestY = "";

        solve(a, b, false);
        solve(a, b, true);

        cout << "Case #" << i << ": " << bestX << ' ' << bestY << '\n';
    }

    return 0;
}

/*************************************************************************/

