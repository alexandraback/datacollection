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
#define ALL(c) (c).begin(), (c).end()
#define SIZE(c) (c).size()
 
#define DEBUG(x) { cerr << #x << " = " << x << endl; }
#define PR(a,n) {cerr<<#a<<" = "; FOR(_,1,n) cerr << a[_] << ' '; cerr <<endl;}
#define PR0(a,n) {cerr<<#a<<" = ";REP(_,n) cerr << (a[_]) << ' '; cerr << endl;}
#define ll long long
using namespace std;
 
const double PI = 2.0 * acos (0.0);
 
typedef long long LL;
typedef pair <int, int> PII;
 
template <class T> inline T MAX (T a, T b) { if (a > b) return a; return b; }
template <class T> inline T MIN (T a, T b) { if (a < b) return a; return b; }

#define maxn

double a[1111], b[1111], used[1111];

int main() {
	freopen("a.inp","r",stdin);
	freopen("a.out","w",stdout);
	int _;
	cin >> _;
	FOR(test, 1, _) {
        cout << "Case #" << test << ": ";
        int n;
        cin >> n;
        //DEBUG(n);
        
        FOR(i, 1, n) cin >> a[i];
        FOR(i, 1, n) cin >> b[i];
        sort(a + 1, a + n + 1);
        sort(b + 1, b + n + 1);
        //PR(a,n);PR(b,n);
        
        int x = n, i = 1, j = n, res1 = 0;
        FOR (turn, 1, n) {
            if (a[j] > b[x]) {
                x--;
                j--;
                res1++;
            } else {
                x--;
                i++;
            }
        }
        int res2 = 0;
        RESET(used, false);
        FOR (i, 1, n) {
            bool lose = false;
            FOR(j, 1, n)
                if (!used[j] && a[i] < b[j]) {
                    lose = true;
                    used[j] = true;
                    break;
                }
            
            if (!lose) res2++;
                
        }
        cout << res1 <<  " " << res2 << endl;
	}
}

 