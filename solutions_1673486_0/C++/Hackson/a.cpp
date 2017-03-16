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
        printf("Case #%d: ", ca);
        int A, B;
        cin >> A >> B;
        double p[A];
        FOR(i, 0, A) cin >> p[i];
        double res = 1e30;
        double wrong_at[A];
        FOR(i, 0, A) if (!i) wrong_at[i] = 1-p[i];
        else wrong_at[i] = wrong_at[i-1] + (1. - wrong_at[i-1]) * (1 - p[i]);
        for (int i = A-1, j = 1; i >= 0; --i, ++j)
            if (i) res = fmin(res, (1-wrong_at[i-1]) * (2*j + B - i) + wrong_at[i-1] * (2*j+B-i + B+1));
            else res = fmin(res, j + B + 1);
        res = fmin(res, 2+B);
        res = fmin(res, wrong_at[A-1] * (B - A + B + 2) + (1-wrong_at[A-1]) * (B - A + 1));
        printf("%.10f\n", res);
    }
	return 0;
}
