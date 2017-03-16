#ifdef SHTRIX 
#include "/Users/roman/Dev/SharedCpp/DebugOutput.h"
#endif
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
#include <sstream>
#include <map>
#include <set>
#include <stack>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <memory>
using namespace std;
#define pb push_back
#define INF 1000000000
#define L(s) (int)((s).end()-(s).begin())
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for(int i = (a); i >= (b); i--)
#define rep(i,n) FOR(i,1,(n))
#define rept(i,n) FOR(i,0,(n)-1)
#define C(a) memset((a),0,sizeof(a))
#define ll long long
#define all(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))
#define VI vector<int>
#define ppb pop_back
#define mp make_pair
#define pii pair<int,int>
#define pdd pair<double,double>
//#define x first
//#define y second
#define sqr(a) (a)*(a)
#define D(a,b) sqrt(((a).x-(b).x)*((a).x-(b).x)+((a).y-(b).y)*((a).y-(b).y))
#define pi 3.1415926535897932384626433832795028841971
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())

vector<int> open;
vector<vector<int> > keys;
vector<int> start;

int pred[1 << 20];

void f(int mask, int pr = -1) {
    if (pred[mask] != -1) return;
    pred[mask] = pr;
    map<int, int> cnt;
    rept(i, L(start))
        cnt[start[i]]++;
    rept(i, L(open))
        if (mask & (1 << i)) {
            cnt[open[i]]--;
            rept(j, L(keys[i])) cnt[keys[i][j]]++;
        }
    rept(i, L(open))
        if (!(mask & (1 << i)) && cnt[open[i]] > 0) {
            f(mask | (1 << i), mask);
        }
}

int xw(int mask) {
    int res = 0;
    while (mask > 0) {
        res++;
        mask /= 2;
    }
    return res;
}

void solve(int case_id) {
    printf("Case #%d: ", case_id);
    int k, n;
    scanf("%d%d", &k, &n);
    start.clear();
    rept(i, k) {
        int x;
        scanf("%d", &x);
        start.push_back(x);
    }

    open.assign(n, 0);
    keys.assign(n, vector<int>());
    rept(i, n) {
        int q;
        scanf("%d%d", &open[i], &q);
        rept(j, q) {
            int x;
            scanf("%d", &x);
            keys[i].push_back(x);
        }
    }
    memset(pred, -1, sizeof(pred));
    f(0);
    int x = (1 << n) - 1;
    if (pred[x] == -1) {
        puts("IMPOSSIBLE");
        return;
    }
    VI b;
    while (x != -1) {
        b.push_back(x);
        x = pred[x];
    }

    VI a;
    rept(i, L(b) - 1) a.push_back(xw(b[i] ^ b[i + 1]));
    reverse(all(a));
    rept(i, L(a)) {
        if (i) printf(" ");
        printf("%d", a[i]);
    }
    puts("");
}

int main()
{
    #ifdef SHTRIX 
    freopen("input.txt","rt",stdin); 
    //freopen("output.txt","wt",stdout); 
    #endif
	int TC;
    scanf("%d", &TC);
    rep(tc, TC) {
        solve(tc);
    }
    return 0;
}
