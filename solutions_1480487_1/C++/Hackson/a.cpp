#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define eps 1e-9
#define FOR(x, s, e) for(int x = (s); x < (e); ++x)
#define FORc(x, s, e, c) for(int x = (s); x < (e) && (c); ++x)
#define STEP(x, s, e, d) for(int x = (s); x < (e); x+=(d))
#define ROF(x, s, e) for(int x = (s); x >= (e); --x)
#define ROFc(x, s, e, c) for(int x = (s); x >= (e) && (c); --x)
#define vb vector<bool>
#define vi vector<int>
#define vii vector<pair<int, int> >
#define vs vector<string>
#define pb push_back
#define mp make_pair
#define ALL(X) X.begin(), X.end()
#define LL long long
#define pii pair<int, int>
#define x first
#define y second
#define gcd(x, y) __gcd((x), (y))
#define countbit(x) __builtin_popcount(x)

using namespace std;

double fmin(double x, double y){ return x-y>eps?y:x;}

int main(int argc, char **argv){
    int T;
    cin >> T;
    FOR(ca, 1, T+1){
        printf("Case #%d:", ca);
        int N, S=0, L = 1<<29;
        cin >> N;
        vi A(N);
        bool haszero = 0;
        FOR(i, 0, N) cin >> A[i], S += A[i], L = min(L, A[i]), haszero |= A[i] == 0;
        double lo = 0, hi = 1e30, res = 1e30, rq = 1e30;
        FOR(TT, 0, 100000){
            double mi = (lo+hi)/2.;
            double q = 0;
            FOR(i, 0, N){
                if (mi - A[i] >= eps) q += mi - A[i];
            }
            if (fabs(rq-S) - fabs(q-S) > eps)
                rq = q, res = mi;
            if ((q - S) > eps){
                hi = mi; 
            }else{
                lo = mi;
            }
        }
        FOR(i, 0, N) printf(" %.10f", (res-A[i]>eps?((res- A[i]) / S * 100.):0));
        puts("");
    }
	return 0;
}
