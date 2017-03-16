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
#define N 4

int i,j,k,m,n,l;
char a[N+10][N+10], b[N+10];
char s[][100]={"X won", "O won", "Draw", "Game has not completed"};

int gao(char a[]){
    char ch='.';
    rep(j, N) if (strchr("XO", a[j])!=NULL) ch=a[j];
    
    if (ch!='.'){
        bool flag=true;
        rep(j, N) if (a[j]!=ch && a[j]!='T') flag=false;
        if (flag==true){
            if (ch=='X') return 0;
            else return 1;
        }
    }
    return -1;
}

char *solve(){
    rep(i, N){
        rep(j, N) b[j]=a[i][j]; k=gao(b);
        if (k!=-1) return s[k];
        
        rep(j, N) b[j]=a[j][i]; k=gao(b);
        if (k!=-1) return s[k];
    }
    rep(i, N) b[i]=a[i][i]; k=gao(b);
    if (k!=-1) return s[k];
    
    rep(i, N) b[i]=a[N-i-1][i]; k=gao(b);
    if (k!=-1) return s[k];
    
    rep(i, N) rep(j, N) if (a[i][j]=='.') return s[3];
    return s[2];
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tests;
    scanf("%d", &tests);
    repf(test, 1, tests){
        rep(i, N) rep(j, N){
            a[i][j]=getchar();
            while (strchr("XTO.", a[i][j])==NULL) a[i][j]=getchar();
        }
        printf("Case #%d: %s\n", test, solve());
    }
    return 0;
}
