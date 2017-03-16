#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstdlib>

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

#define ri(X) scanf("%d", &(X))
#define rii(X, Y) scanf("%d%d", &(X), &(Y))
#define riii(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define all(a) (a).begin(),(a).end()
#define sz(s) ((int) ((s).size()))
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fornr(i, n) for (int i = (int)(n)-1; i>=0; --i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define for1r(i, n) for (int i = (int)(n); i>0; --i)

#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;

int mod1 = int(1e9) + 7;

#define MX 100100

deque<char> q;
string s;

void solve(int lst) {

    char mc = 0;
    int mcit = -1;
    for(int k=lst; k>=0; k--) {
        if(mc<s[k]) {
            mc = s[k];
            mcit = k;
        }
    }

    if(mcit>0) {
        solve(mcit-1);
    }

    q.push_front(mc);
    for(int i=mcit+1; i<=lst; i++) {
        q.pb(s[i]);
    }

}

void main2(){

    s.clear();
    cin >> s;

    int sl = s.length();

    q.clear();

    solve(sl-1);

    forn(i,q.size()) {
        printf("%c", q[i]);
    }
    printf("\n");
}


int main(){

    int t;
    ri(t);

    for1(cas,t) {
        printf("Case #%d: ", cas);
        main2();
    }

    return 0;
}
