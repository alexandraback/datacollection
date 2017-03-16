#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

#define PI acos(-1.0)
#define MP make_pair
#define PB push_back
#define SET(a,v) memset(a, v, sizeof(a))

#define VI vector <int>
#define PII pair <int, int>
#define LL long long 

#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define REP(i,a,b) for (int i = a; i < b; i++)
#define REPD(i,a,b) for (int i = a; i > b; i--)
#define FIT(it,v) for (typeof(v.begin()) it = v.begin(); it != v.end(); it++)
#define FITD(it,v) for (typeof(v.rbegin()) it = v.rbegin(); it != v.rend(); it++)
#define FALL(i,v) for (int i = 0; i < (v.size()); i++)


int n, a[1000], X;
double f[1000];

int cmp(double x, double y) {
    if (fabs(x - y) <= 0.000000001) return 0;
    if (x < y) return -1;
    if (x > y) return 1;    
}

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("a.out", "w", stdout);
    
    int _;
    cin >> _;
    FOR (test, 1, _) {
        cin >> n;
        
        X = 0;
        FOR (i, 1, n) {
            cin >> a[i];
            X += a[i];
        }
        
        FOR (ith, 1, n) {
            swap(a[ith], a[1]);
            double l = 0, r = 1, m, sc, tg;
            int step = 100;
            while (step--) {
                  tg = 1;
                  m = (l + r) / 2.0;
                  sc = m * X + a[1];
                  tg -= m;
                  
                  
                  FOR (i, 2, n) 
                      if (cmp(a[i], sc) == -1)
                         tg -= (sc - a[i])/X;
                         
                  if (cmp(tg, 0) <= 0 && cmp(m, 1) != 0) r = m;           
                  else l = m;
            }
            
            f[ith] = l;
        }
        
        printf("Case #%d: ", test);
        FOR (i, 1, n) printf("%.9lf ", f[i]*100);
        printf("\n");
    }        
    return 0;    
}
