// MS Visual Studio
#include<cstdio>
#include<cstring>
#include<cstdio>
#include<cmath>
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

double T[1000], x[1000];
int main() {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B.out", "w", stdout);
    int tc;
    scanf("%d", &tc);
    FOR(t, 1, tc+1) {
        //cerr << t << endl;
        printf("Case #%d:\n", t);
        int n, a;
        double X;
        cin >> X >> n >> a;
        REP(i, n) {
            cin >> T[i] >> x[i];
        }
        double to;
        if(n == 1) {
            to = 0;
        } else {
            to = ((X - x[0]) / (x[1] - x[0])) * T[1];
        }
        REP(i, a) {
            double g;
            cin >> g;
            double t_our = sqrt(2 * X / g);
            printf("%.10lf\n", max(to, t_our));
        }
    }
}