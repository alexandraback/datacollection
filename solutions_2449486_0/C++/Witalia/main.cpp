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
#define eps 10e-5
#define Inf 1000000000
#define Mi 1000000007
#define N 115
#define K 20

typedef double ld;
typedef long long ll;
typedef int i;
typedef vector<i> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef pair<double, char> pdc;
typedef enum {heavy, light} lbl;

const int mx[4] = {1, -1, 0, 0};
const int my[4] = {0, 0, 1, -1};

inline ll gcd (ll a, ll b){ return (!b ? a : gcd (b, a % b)); }

const ld PI = 2 * acos(0.0);
const ll InfLL = ll(Inf) * ll(Inf);

int rand15() { return rand() % (1 << 15); }
int rand30() { return (rand15() << 15) + rand15(); }
int rand(int L, int R) { if (L > R) return R; return rand30() % (R - L + 1) + L; }
ld random(ld L, ld R) { return rand(ceil((L-eps)*100), floor((R+eps)*100)) / 100.0;}

//#define DEBUG

int find_one(int in[], int cnt[N][N], int n, int num) {
    REP(i, n)
        if (in[i] == 1 && cnt[i][num] > 0)
            return i;
    return -1;
}

bool is_empty(int a[], int n) {
    REP(i, n)
        if (a[i])
            return false;
    return true;
}

void delete_occur(int in[], int cnt[N][N], int all[], int n, int num) {
    REP(i, n)
        if (in[i]) {
            cnt[i][num]--;
            if (cnt[i][num] == 0)
                in[i]--;
            all[num]--;
        }
}

int n, m;
int in_row[N], in_col[N];
int cnt_row[N][N], cnt_col[N][N];
int cnt[N];

//#define DEBUG_MODE
//#define ONLINE_JUDGE
int main ()
{
    std::ios_base::sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
        freopen ("input.txt", "r", stdin);
        freopen ("output.txt", "wb", stdout);
    #endif
    int T;
    scanf ("%d", &T);
    REP(t, T) {
        scanf("%d%d", &n, &m);
        printf("Case #%d: ", t + 1);
        CLR(in_col, 0); CLR(in_row, 0);
        CLR(cnt_col, 0); CLR(cnt_row, 0);
        CLR(cnt, 0);
        REP(i, n)
            REP(j, m) {
                int cur;
                scanf("%d", &cur);
                cnt_row[i][cur]++;
                if (cnt_row[i][cur] == 1)
                    in_row[i]++;
                cnt_col[j][cur]++;
                if (cnt_col[j][cur] == 1)
                    in_col[j]++;
                cnt[cur]++;
            }
        FOR(num, 1, 100) {
            while (cnt[num]) {
                int col = find_one(in_col, cnt_col, m, num);
                int row = find_one(in_row, cnt_row, n, num);
                if (col == -1 && row == -1)
                    break;
                if (row != -1) {
                    in_row[row] = 0;
                    delete_occur(in_col, cnt_col, cnt, m, num);
                } else {
                    in_col[col] = 0;
                    delete_occur(in_row, cnt_row, cnt, n, num);
                }
            }
        }
        printf("%s\n", is_empty(in_row, n) ? "YES" : "NO");
    }
    return 0;
}
