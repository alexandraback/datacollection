#line 2 "EllysJuice.cpp"
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP make_pair

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,l,h) for(int i=(l);i<=(h);++i)
#define FORD(i,h,l) for(int i=(h);i>=(l);--i)

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

int T, A, B;
double pp[101010], dp[101010];

int main()
{
    freopen("A-small-attempt0.in", "r", stdin); freopen("a.out","w",stdout);
    scanf("%d", &T);
    FOR(CAS, 1, T){
        scanf("%d%d", &A, &B);
        dp[0] = pp[0] = 1;
        FOR(i,1,A){
            scanf("%lf", &pp[i]);
            dp[i] = pp[i]*dp[i-1];
        }
        double ans = B+2;
        REP(i, A+1){
            double tmp = dp[A-i]*(i+B-A+i+1) + (1-dp[A-i])*(i+B-A+i+1+B+1);
            ans = min(ans, tmp);
        }
        printf("Case #%d: %.8lf\n", CAS, ans);
    }
    return 0;
}
