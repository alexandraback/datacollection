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
#define Abs(a) ((a < 0) ? -(a) : a)
#define sqr(a) ((a)*(a))
#define pb push_back
#define mp make_pair

typedef double ld;
typedef long long ll;
typedef int i;
typedef vector<i> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef pair<double, char> pdc;
typedef enum {heavy, light} lbl;

const ld eps = 10e-7;
const int Inf = 10e9;
const int Mi = 10e9 + 7;
const int N = 205;
const int K = 23;
const ld PI = 2 * acos(0.0);
const ll InfLL = ll(Inf) * ll(Inf);

const int mx[4] = {1, -1, 0, 0};
const int my[4] = {0, 0, 1, -1};

inline ll gcd (ll a, ll b){ return (!b ? a : gcd (b, a % b)); }

int rand15() { return rand() % (1 << 15); }
int rand30() { return (rand15() << 15) + rand15(); }
int rand(int L, int R) { if (L > R) return R; return rand30() % (R - L + 1) + L; }
ld random(ld L, ld R) { return rand(ceil((L-eps)*100), floor((R+eps)*100)) / 100.0;}

//#define DEBUG

int n, k;
int have[N];
int types[K];
vector<int> keys[K];
bool used[1100000];
bool found;
vector<int> ans;

void search(int mask) {
    used[mask] = true;
    if (mask == (1 << n) - 1) {
        found = true;
        for (int i = 0; i < ans.size(); i++)
            printf(" %d", ans[i]);
        printf("\n");
        return ;
    }
    for (int i = 0; i < n && !found; i++)
        if ((mask >> i) % 2 == 0 && have[types[i]] > 0)
            if (used[mask | (1 << i)] == false) {
                for (int j = 0; j < keys[i].size(); j++)
                    have[keys[i][j]]++;
                have[types[i]]--;
                ans.push_back(i + 1);
                search(mask | (1 << i));
                ans.pop_back();
                have[types[i]]++;
                for (int j = 0; j < keys[i].size(); j++)
                    have[keys[i][j]]--;
            }
}


//#define DEBUG_MODE
//#define ONLINE_JUDGE
int main ()
{
    std::ios_base::sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
        freopen ("input.txt", "r", stdin);
        freopen ("output.txt", "w", stdout);
    #endif
    int T;
    scanf("%d", &T);
    REP(t, T) {
        printf("Case #%d:", t + 1);
        scanf("%d%d", &k, &n);
        CLR(have, 0);
        REP(i, k) {
            int a;
            scanf("%d", &a);
            have[a]++;
        }
        REP(i, n) {
            int ki;
            scanf("%d%d", &types[i], &ki);
            keys[i].resize(ki);
            REP(j, ki) {
                scanf("%d", &keys[i][j]);
            }
        }
        found = false;
        CLR(used, false);
        ans.clear();
        search(0);
        if (!found) {
            printf(" IMPOSSIBLE\n");
        }
    }
    return 0;
}
