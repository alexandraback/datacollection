#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cmath>
#include <cctype>
using namespace std;
template <class T> void checkmin(T &a, T b){ if (b<a) a=b; }
#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define clr(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define sz(a) ((int)(a).size())
#define ll long long 
#define N 10

int i,j,k,m,n,l;
bool v[N+10][N+10], w[N+10][N+10];
int a[N+10][N+10];

bool check(int i, int j){
    return i>=0 && j>=0 && i<n && j<m && v[i][j];
}

void gao(){
    clr(a, 0);
    rep(i, n) rep(j, m) if (!v[i][j])
        repf(x, -1, 1) repf(y, -1, 1)
            if (check(i+x, j+y)) a[i][j]++;
}

void gao(int i, int j){
    w[i][j]=0;
    repf(x, -1, 1) repf(y, -1, 1){
        int ii=i+x, jj=j+y;
        if (ii>=0 && jj>=0 && ii<n && jj<m){            
            if (v[ii][jj]==0 && w[ii][jj]==1 && a[ii][jj]==0) gao(ii, jj);
            else w[ii][jj]=0;
        }
    }
}

bool check(){
    rep(i, n) rep(j, m) if (w[i][j]!=v[i][j]) return false;
    return true;
}

bool dfs(int d, int l){
    if (l==0){
        gao();
        rep(i, n) rep(j, m) if (!v[i][j] && a[i][j]==0){
            clr(w, 1);
            gao(i, j);
            if (check()){
                rep(x, n){
                    rep(y, m)
                        putchar(v[x][y]?'*':(x==i&&y==j?'c':'.'));
                    putchar('\n');
                }
                return true;
            }
            return false;
        }
        return false;
    }
    if (d==n*m) return false;
    if (dfs(d+1, l)) return true;
    
    v[d/m][d%m] = 1;
    if (dfs(d+1, l-1)) return true;
    v[d/m][d%m] = 0;
    return false;
}

int main(){
    freopen("C-small-attempt1.in", "r", stdin);
    freopen("C.out", "w", stdout);
    int ts;
    scanf("%d", &ts);
    repf(te, 1, ts){
	   scanf("%d%d%d", &n, &m, &l);
	    printf("Case #%d:\n", te);
	   if (n*m-l==1){
            rep(i, n){
                rep(j, m)
                    putchar(i==n-1&&j==m-1?'c':'*');
                putchar('\n');
            }
            continue;
        }
	   clr(v, 0);
	   if (!dfs(0, l)) puts("Impossible");
    }
    return 0;
}
