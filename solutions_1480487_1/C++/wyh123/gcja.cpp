#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <time.h>
#include <cctype>
#include <functional>
#include <deque>
#include <iomanip>
#include <bitset>
#include <assert.h>
#include <numeric>
#include <sstream>
#include <utility>

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FORD(i,a,b) for (int i=(a); i>=(b); i--)
#define REP(i,b) FOR(i,0,b)
#define sf scanf
#define pf printf
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-10;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n;
double p[210], tot;

bool check(int now, double per)
{
    per /= 100.0;
    double need = per;
    double s = tot * per + p[now];
    double tmp;
    REP(i, n)
    if (i != now)
    {
        if (p[i] > s) continue;
        else
        {
            need += (s - p[i]) / tot ;
        }
    }
    
    return need > 1.0;
}
int main() 
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);   
    int T, ca = 0;
    sf("%d", &T);
    double lo, hi, mid;
    while (T--)
    {
        sf("%d", &n);
        tot = 0.0;
        REP(i, n) 
        {
            sf("%lf", &p[i]);
            tot += p[i];
        }
        pf("Case #%d:", ++ca);
        REP(i, n)
        {
            lo = 0.0, hi = 100.0, mid;
            REP(j, 100)
            {
                mid = (lo + hi)/2.0;
                if (check(i, mid)) hi = mid;
                else lo = mid;
            }
            pf(" %.6f", mid);
        }
        pf("\n");
    }
    
    return 0;
}


