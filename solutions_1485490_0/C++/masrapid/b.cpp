
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
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
#include <ctime>
#include <cstring>
using namespace std;

#define rep(i,s,n) for( int i = s; i < n; ++i)
#define min(a, b) (a < b? a: b)
#define max(a, b) (a > b? a: b)

#define MAX 101
int A[MAX], B[MAX], n, m;
long long a[MAX], b[MAX], tb[MAX][MAX];
long long tb2[MAX][MAX];
long long tb3[MAX][MAX];
long long dp(int i, int j);
long long dp3(int i, int j);
long long dp2(int i, int j){
    if(i == n || j == m) return 0;
    long long &ret = tb2[i][j];
    if(ret != -1) return ret;
    if(A[i] == B[j]){
        if(a[i] == b[j])
            return ret = a[i] + dp(i + 1, j + 1);
        else if(a[i] < b[j]){
            b[j] -= a[i];
            ret = a[i] + dp2(i + 1, j);
            b[j] += a[i];
            return ret;
        }
        else{
            a[i] -= b[j];
            ret = b[j] + dp3(i, j + 1);
            a[i] += b[j];
            return ret;
        }
    }
    long long t1 = dp(i + 1, j);
    long long t2 = dp(i, j + 1);
    return ret = max(t1, t2);
}
long long dp3(int i, int j){
    if(i == n || j == m) return 0;
    long long &ret = tb3[i][j];
    if(ret != -1) return ret;
    if(A[i] == B[j]){
        if(a[i] == b[j])
            return ret = a[i] + dp(i + 1, j + 1);
        else if(a[i] < b[j]){
            b[j] -= a[i];
            ret = a[i] + dp2(i + 1, j);
            b[j] += a[i];
            return ret;
        }
        else{
            a[i] -= b[j];
            ret = b[j] + dp3(i, j + 1);
            a[i] += b[j];
            return ret;
        }
    }
    long long t1 = dp(i + 1, j);
    long long t2 = dp(i, j + 1);
    return ret = max(t1, t2);
}

long long dp(int i, int j){
    if(i == n || j == m) return 0;
    long long &ret = tb[i][j];
    if(ret != -1) return ret;
    if(A[i] == B[j]){
        if(a[i] == b[j])
            return ret = a[i] + dp(i + 1, j + 1);
        else if(a[i] < b[j]){
            b[j] -= a[i];
            ret = a[i] + dp2(i + 1, j);
            b[j] += a[i];
            return ret;
        }
        else{
            a[i] -= b[j];
            ret = b[j] + dp3(i, j + 1);
            a[i] += b[j];
            return ret;
        }
    }
    long long t1 = dp(i + 1, j);
    long long t2 = dp(i, j + 1);
    return ret = max(t1, t2);
}

int main(){
//        freopen("b.in", "r", stdin);
    freopen("C-small-attempt2.in", "r", stdin);
    freopen("C-small-attempt2.out", "w", stdout);

    int t, kase = 0;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        rep(i, 0, n) scanf("%lld%d", &a[i], &A[i]);
        rep(i, 0, m) scanf("%lld%d", &b[i], &B[i]);
        memset(tb, -1, sizeof(tb));
        memset(tb2, -1, sizeof(tb2));
        memset(tb3, -1, sizeof(tb3));
        printf("Case #%d: %lld\n", ++kase, dp(0, 0));
    }

    return 0;
}
