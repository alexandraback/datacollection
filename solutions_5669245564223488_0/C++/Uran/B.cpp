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

int brute(vector<string> v) {
    int ans = 0;
    vector<int> p;
    rept(i, L(v)) p.pb(i);
    do {
        string s;
        rept(i, L(v)) s += v[p[i]];

        bool ok = true;
        for (char c = 'a'; c <= 'z'; c++) {
            int last = -1;
            rept(j, L(s)) {
                if (s[j] == c) {
                    if (last != -1 && last != j - 1) {
                        ok = false;
                        break;
                    }
                    last = j;
                }
            }
            if (!ok) break;
        }
        if (ok) ans++;
    } while (next_permutation(all(p)));
    return ans % (INF + 7);
}

void solve(int case_id) {
    cerr << case_id << endl;
    printf("Case #%d: ", case_id);
    int n;
    cin >> n;
    vector<string> v(n);
    rept(i, n) cin >> v[i];
    printf("%d\n", brute(v)); return;

    int G[26][26];
    C(G);
    rept(i, n) {
        rept(j, L(v[i])) {
            rept(k, j) {
                if (v[i][k] != v[i][j])
                    G[v[i][k] - 'a'][v[i][j] - 'a'] = 1;
            }
        }
    }
    cerr << endl << DEB(G, 5, 5) << endl;
    rept(k, 26)
        rept(i, 26)
            rept(j, 26)
                if (G[i][k] && G[k][j])
                    G[i][j] = 1;
    rept(i, 26)
        rept(j, 26)
            if (G[i][j] && G[j][i]) {
                printf("0\n");
                return;
            }
    int P[111][111];
    C(P);
    rept(i, n)
        rept(j, n) 
            if (i != j) {
                rept(k, L(v[i]))
                    rept(t, L(v[j]))
                        if (G[v[i][k] - 'a'][v[j][t] - 'a']) {
                            P[i][j] = 1;
                        }
            }
    rept(k, n)
        rept(i, n)
            rept(j, n)
                if (P[i][k] && P[k][j])
                    P[i][j] = 1;
    rept(i, n)
        rept(j, n)
            if (P[i][j] && P[j][i]) {
                printf("0\n");
                return;
            }
    rept(i, n)
        rept(j, n) 
            if (i != j) {
                rept(k, L(v[i]))
                    rept(t, L(v[j]))
                        if (v[i][k] == v[j][t]) {
                            P[i][j] = 1;
                        }
            }

    int col[111], c = 0;
    C(col);
    rept(i, n) {
        if (col[i]) continue;
        int cnt = 0;
        rept(j, n)
            if (!col[j] && P[j][i]) cnt++;
        if (!cnt) {
            col[i] = c + 1;
            rept(j, n)
                if (P[i][j])
                    col[i] = c + 1;
            c++;
        }
    }
    ll res = 1;
    rep(i, c) {
        res *= i;
        res %= INF + 7;
    }
    printf("%d\n", (int)res);
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
