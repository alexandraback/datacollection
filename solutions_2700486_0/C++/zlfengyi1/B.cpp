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
#include <ctime>
#include <string.h>

using namespace std;

const double pi = acos(-1.0);
const double eps = 1E-7;
const int inf = int(1e9)+7;

typedef long long int64;
typedef unsigned long long uint64;
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
#define contain(S,X) (((S)&two(X))!=0)
#define containL(S,X) (((S)&twoL(X))!=0)
#define sqr(x) ((x)*(x))
typedef pair<int,int> ipair;
#define SIZE(A) ((int)A.size())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)
#define ME(a) memset((a), 0, sizeof((a)))
#define MM(a, b) memcpy((a), (b), sizeof((a)))
#define FOR(i,n) for (int (i) = 0; (i) < (n); ++(i))
#define REP(i,a,b) for (int (i) = (a); (i) < (b); ++(i))

const int MAXN = 5000+5;
double dp[MAXN][MAXN];

void init() {
    ME(dp);
    dp[0][0] = 1;
    FOR(i,MAXN-1) FOR(j,i+1) {
        dp[i+1][j] += dp[i][j]*0.5;
        dp[i+1][j+1] += dp[i][j]*0.5;
    }
}

double hzz() {
    int n, x, y;
    scanf("%d%d%d", &n, &x, &y);
    int h = (abs(x)+abs(y)) - 2;
    if (h == -2) return 1;
    
    int total = 0;
    for (int i = 0; i <= h; i+=2) {
        total += i*2+1;
        if (n <= total) return 0;
    }
    
    int t = n-total;
    int need = y+1;
   // cout<<h<<" "<<need<<" "<<t<<endl;
    if (h+2+need <= t) return 1;
    if (x == 0) return 0;
    double ans = 0;
    for (int i = need; i <= t; i++) ans += dp[t][i];
    return ans;
}
int main()
{
    init();
    int caseNum;
    scanf("%d", &caseNum);
    for (int ca = 1; ca <= caseNum; ca++)
    {
        double ans = hzz();
        printf("Case #%d: %.10lf\n", ca, ans);        
    }
    return 0;
}
