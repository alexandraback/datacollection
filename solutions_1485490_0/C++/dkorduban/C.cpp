// MS Visual Studio
#include<cstdio>
#include<cstring>
#include<cstdio>
#include<iostream>
#include<map>
#include<vector>
using namespace std;

#define REP(i,n) FOR(i,0,n)
#define FOR(i,s,n) for(int i=(s); i<(n); ++i)
#define sz(X) int((X).size())
#define pb push_back
#define X first
#define Y second

typedef long long lint;

vector<pair<lint, int> > a, b;

void reduce(vector<pair<lint, int> > &a) {
    bool bb = true;
    while(bb) {
        bb = false;
        REP(i, sz(a) - 1) {
            if(a[i].Y == a[i+1].Y) {
                a[i].X += a[i+1].X;
                a.erase(a.begin() + (i + 1));
                bb = true;
                break;
            }
        }
    }
}

lint cnt(int from, int to, int id) {
    lint ret = 0;
    FOR(i, from, to) {
        if(b[i].Y == id) {
            ret += b[i].X;
        }
    }
    return ret;
}

int main() {
    freopen("C-small-attempt1 (1).in", "r", stdin);
    freopen("C.out", "w", stdout);
    int tc;
    scanf("%d", &tc);
    FOR(t, 1, tc+1) {
        cerr << t << endl;
        int n, m;
        printf("Case #%d: ", t);
        cin >> n >> m;
        a = vector<pair<lint, int> >(n);
        b = vector<pair<lint, int> >(m);
        REP(i, n) {
            cin >> a[i].X >> a[i].Y;
        }
        REP(i, m) {
            cin >> b[i].X >> b[i].Y;
        }
        reduce(a);
        n = sz(a);

        lint ans = 0;
        if(n == 1) {
            ans = min(cnt(0, m, a[0].Y), a[0].X);
        }
        else if(n == 2) {
            REP(i, m + 1) {
                ans = max(ans, min(cnt(0, i, a[0].Y), a[0].X) + min(cnt(i, m, a[1].Y), a[1].X));
            }
        }
        else {
            REP(i, m + 1) {
                FOR(j, i, m + 1) {
                    lint t = min(cnt(i, j, a[1].Y), a[1].X);
                    //if(a[0].Y != a[2].Y) {
                    t += min(cnt(0, i, a[0].Y), a[0].X) + min(cnt(j, m, a[2].Y), a[2].X);
                    //}
                    //else {
                    //    t += min(cnt(0, i, a[0].Y) + cnt(j, m, a[2].Y), a[0].X + a[2].X);
                    //}
                    //cerr << i << " " << j << " " << t << endl;
                    ans = max(ans, t);
                }
            }
            if(a[0].Y == a[2].Y) {
                ans = max(ans, min(cnt(0, m, a[0].Y), a[0].X + a[2].X));
            }
        }

        printf("%lld\n", ans);

        //REP(i, n+1) {
        //    REP(j, m+1) cout << h(i, j) << " ";
        //    cout << endl;
        //}
        //cout << endl;
    }
}