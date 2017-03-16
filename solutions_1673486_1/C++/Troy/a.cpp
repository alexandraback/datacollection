/*
 * Author:  Troy
 * Created Time:  2012/4/28 8:55:10
 * File Name: a.cpp
 */
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
#define Maxn 10010
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, m;
double p[100010], ans;
int main() 
{
    //freopen("A-large.in", "r", stdin);
    //freopen("A-large.out", "w", stdout);
    int T, ca = 0;
    sf("%d", &T);
    while (T--)
    {
        sf("%d%d", &n, &m);
        REP(i, n) sf("%lf", &p[i]);
        ans = (double)(m+1+1);
        double tt = 1.0 * (double)(n+m+1);
        if (tt < ans) ans = tt;
        
        double sum = 1.0;
        REP(i, n)
        {
            sum *= p[i];
            double tmp = sum * (double)(n - i - 1 + m - i)  +  (1.0 - sum) * (n - i - 1 + m - i + m + 1);
            if (tmp < ans) ans = tmp;
            //cout <<tmp <<endl;
        }
        double tmp = sum * (m - n + 1) + (1.0 - sum) * (m - n + 1 + m + 1);
        if (tmp < ans) ans = tmp;
        pf("Case #%d: %.6f\n", ++ca, ans);
    }
    return 0;
}

