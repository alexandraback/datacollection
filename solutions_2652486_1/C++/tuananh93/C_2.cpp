//Written by technolt~h

#pragma comment(linker, "/STACK:16777216")
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
 #include <stack>
#include <set>
#include <map>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <memory.h>
#include <sstream>
 #include <complex>

#define REP(i,n) for(int i = 0, _n = (n); i < _n; i++)
#define REPD(i,n) for(int i = (n) - 1; i >= 0; i--)
#define FOR(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
 #define FORN(i,a,b) for(int i=a;i<b;i++)
#define FOREACH(it,c) for (__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define RESET(c,x) memset (c, x, sizeof (c))

#define sqr(x) ((x) * (x))
#define PB push_back
 #define MP make_pair
#define F first
#define S second
#define Aint(c) (c).begin(), (c).end()
#define SIZE(c) (c).size()

#define DEBUG(x) { cerr << #x << " = " << x << endl; }
#define PR(a,n) {cerr<<#a<<" = "; FOR(_,1,n) cerr << a[_] << ' '; cerr <<endl;}
#define PR0(a,n) {cerr<<#a<<" = ";REP(_,n) cerr << a[_] << ' '; cerr << endl;}
#define LL long long
#define PI acos(-1.0)

using namespace std;

#define maxn 100000

int R, N, M, K, P[100];
int A[maxn + 10][10];
set <long long> Pro[maxn + 10];

bool check(int i) {
    FOR (j, 1, K)
        if (P[j] != 1 && Pro[i].find(P[j]) == Pro[i].end()) return false;
    return true;
}

int main() {
    //freopen("C-small-1-attempt0.in", "r", stdin);
    freopen("C-small-2-attempt1.in", "r", stdin);
    freopen("c.out", "w", stdout);

    int ntest;
    cin >> ntest;
    cout << "Case #1:"<< endl;
    cin >> R >> N >> M >> K;

/*
    FOR (i, 1, maxn) {
       // if ((i % 1000) == 0) cerr << i << endl;
        FOR (j, 1, N)
            A[i][j] = ( rand() % (M - 1) ) + 2;

        FOR (j, 0, 100) {
            long long t = 1;
            FOR (k, 1, N)
                if ((rand() % 100) <= 50)
                        t *= A[i][j];
            Pro[i].insert(t);
        }
    }
    */
    int res = 0;
    FOR (test, 1, R) {
        int C5 = 0, C7 = 0, C3 = 0, C2 = 0, C4 = 0, C8, P2 = 0;
        FOR (i, 1, K) {
            cin >> P[i];
            int t = 0;
            while ((P[i] % 2) == 0) {
                t ++;
                P[i] /= 2;
            }
            if (t) {
                P2 = max(t, P2);
                C8 = P2/3;

                if ((t % 3) == 1) C2 = 1;
                if ((t % 3) == 2) C4 = 1;
            }

            t = 0;
            while ((P[i] % 3) == 0) {
                t ++;
                P[i] /= 3;
            }
            C3 = max(C3, t);

            t = 0;
            while ((P[i] % 5) == 0) {
                t ++;
                P[i] /= 5;
            }
            C5 = max(C5, t);

            t = 0;
            while ((P[i] % 7) == 0) {
                t ++;
                P[i] /= 7;
            }
            C7 = max(C7, t);
        }

        int ok = 1;
        vector <int> a;
        FOR (i, 1, C7) a.PB(7);
        FOR (i, 1, C5) a.PB(5);
        FOR (i, 1, C3) a.PB(3);
        FOR (i, 1, C8) a.PB(8);
        FOR (i, 1, C2) a.PB(2);
        FOR (i, 1, C4) a.PB(4);

        while (a.size() < N) a.PB((rand()% (M - 1) ) + 2);
        ok = (a.size() == N);

        res += ok;

        FOR (i,0, N - 1) cout << a[i];
        cout << endl;

    }
    cerr << res << endl;
    return 0;
}



