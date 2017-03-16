#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cctype>
#include <ctime>

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <stack>
using namespace std;
typedef vector<int> vi;
typedef map<int,int> mii;
typedef long long ll;
template <class T> void checkmax(T &t, T x){if (x > t) t = x;}
template <class T> void checkmin(T &t, T x){if (x < t) t = x;}
template <class T> void _checkmax(T &t, T x){if (t == -1 || x > t) t = x;}
template <class T> void _checkmin(T &t, T x){if (t == -1 || x < t) t = x;}
#define INF (INT_MAX/10)
#define SQR(x) ((x)*(x))
#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define iter(v) __typeof((v).begin())
#define foreach(it, v) for (iter(v) it = (v).begin(); it != (v).end(); it++)
#define clr(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) a.begin(), a.end()
#define mid(x, y) ((x+y)/2)
#define vp vector<P>
#define N 100

int i,j,k,m,n,l;
int a[N+10];
ll f[N+10][N+10];

int main(){
    freopen("A-large (1).in", "r", stdin);
    freopen("A-large (1)2.out", "w", stdout);
    int tests;
    scanf("%d", &tests);
    repf(test, 1, tests){
        scanf("%d%d", &a[0], &n);
        repf(i, 1, n) scanf("%d", &a[i]);
        sort(a+1, a+1+n);
        clr(f, -1), f[0][0]=a[0];
        repf(i, 1, n){
            repf(j, 0, n) if (f[i-1][j]!=-1){
                 _checkmax(f[i-1][j+1], min((ll)1e6+10, f[i-1][j]*2-1));
            }
            repd(j, n, 0) 
                if (f[i-1][j]>a[i]) f[i][j]=f[i-1][j]+a[i];
                else if (j) f[i][j]=f[i-1][j-1];
        }
        int ret;
        repf(j, 0, n) if (f[n][j]!=-1){
            ret=j; break;
        }
        printf("Case #%d: %d\n", test, ret);
    }
    return 0;
}
