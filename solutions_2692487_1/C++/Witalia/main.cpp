#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <string>
#include <memory.h>
#include <map>
#define _USE_MATH_DEFINES
#include <math.h>
#include <list>
#include <fstream>
#include <time.h>
#include <iomanip>
#include <queue>
#include <stack>
#include <complex>
//#include <assert.h>

using namespace std;

#define For(i,a,b,d) for (int i = (a); i != (b); i += d)
#define FORD(i,a,b) for (int i = (a); i >= b; i--)
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define REPD(i,n) for (int i = (n - 1); i >= 0; i--)
#define REP(i,n) for (int i = 0; i < (n); i++)
#define ALL(a) (a).begin(), (a).end()
#define CLR(a,x) memset(a,x,sizeof(a))
#define min(a,b) (((a) < (b)) ? (a) : (b))
#define max(a,b) (((a) > (b)) ? (a) : (b))
#define debug(x) cout << #x << "=" << x << endl;
#define Abs(a) (a < 0) ? (-(a)) : (a)
#define sqr(a) ((a)*(a))
#define pb push_back
#define mp make_pair

typedef double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

const int mx[4] = {1, -1, 0, 0};
const int my[4] = {0, 0, 1, -1};

const int Inf = 1000000000;
const int Mi = 1000000009;
const int N = 105;
const int K = 30;
const ld eps = 10e-6;
const ld PI = 2 * acos(0.0);
const ll InfLL = ll(Inf) * ll(Inf);

inline ll gcd (ll a, ll b){ return (!b ? a : gcd (b, a % b)); }

int rand15() { return rand() % (1 << 15); }
int rand30() { return (rand15() << 15) + rand15(); }
int rand(int L, int R) { if (L > R) return R; return rand30() % (R - L + 1) + L; }
ld random(ld L, ld R) { return rand(ceil((L-eps)*100), floor((R+eps)*100)) / 100.0;}

//#define DEBUG

int a, n;
int A[N];

//#define DEBUG_MODE
//#define ONLINE_JUDGE
int main ()
{
    std::ios_base::sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int T;
    scanf("%d", &T);
    REP(_t, T) {
        scanf("%d%d", &a, &n);
        REP(i, n) {
            scanf("%d", &A[i]);
        }
        sort (A, A + n);
        int ans = Inf;
        if (a != 1) {
            REP(l, n + 1) {
                int cur = l;
                ll st = a;
                REP(i, n - l) {
                    while (st <= A[i]) {
                        st += st - 1;
                        cur++;
                    }
                    st += A[i];
                }
                if (cur < ans)
                    ans = cur;
            }
        } else {
            ans = n;
        }
        printf ("Case #%d: %d\n", _t + 1, ans);
    }
    return 0;
}
