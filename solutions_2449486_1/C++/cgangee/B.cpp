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
int a[N+10][N+10];

char *solve(){
    repf(i, 1, n) repf(j, 1, m){
        bool r=0, c=0;
        repf(k, 1, n) if (a[k][j]>a[i][j]) c=1;
        
        repf(k, 1, m) if (a[i][k]>a[i][j]) r=1;
        if (r && c) return "NO";            
    }
    return "YES";
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tests;
    scanf("%d", &tests);
    repf(test, 1, tests){
        scanf("%d%d", &n, &m);
        repf(i, 1, n) repf(j, 1, m) scanf("%d", &a[i][j]);
        printf("Case #%d: %s\n", test, solve());
    }
    return 0;
}
