#include<iostream>
#include<cassert>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<string>
#include<vector>
#include<cstdlib>
#include<iterator>
#include<ctime>
#include<map>
#include<sstream>
#include<set>
#include<cctype>
#include<queue>
#include <memory.h>

using namespace std;

#define all(c) (c).begin(), (c).end()

template<typename T> inline string intToString(T x){ostringstream q;q << x;return q.str();}
template<typename T> inline T myPow(T x, T n, T MOD){T res = 1;while (n>0) {if (n & 1) {res = 1ll*res * x % MOD;}x = 1ll*x * x % MOD;n/=2;}return res;}
template<typename T> inline T gcd(T a, T b){a=abs(a);b=abs(b);while ((a>0) && (b>0)) {if (a>b)a%=b;else b%=a;}return a+b;}


typedef unsigned long long LLong;
typedef long double LDb;

int n,m,k;
int res,used;
bool a[31][31];
bool w[25][25];
bool good;
void dfs(int x, int y)
{
    if (w[x][y])
        return;
    w[x][y] = true;
    if (a[x][y])
        return;
    if (!good)
        return;
    if (x==0 || x==n-1 || y==0 || y==m-1) {
        good =false;
        return;
    }
    dfs(x-1,y);
    dfs(x+1,y);
    dfs(x,y+1);
    dfs(x,y-1);
}

void calc()
{
    int q=0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j]) {
                q++;
                continue;
            }
            memset(w,0,sizeof w);
            good = true;
            dfs(i,j);
            if (good)
                q++;
        }
    }
    if (q>=k)
        res = used;
}

void rec(int x, int y) {
    if (used>=res)
        return;
    if (x==n) {
        calc();
        return;
    }
    int nx = x;
    int ny = y+1;
    if (ny==m) {
        ny = 0;
        nx++;
    }

    used++;
    a[x][y] = true;
    rec(nx,ny);
    a[x][y] = false;
    used--;
    rec(nx,ny);
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    for (int tt = 0; tt < t; ++tt) {
        cout << "Case #" << tt+1 << ": ";
        
        cin >> n >> m >> k;
        res = k;
        used = 0;
        memset(a,0,sizeof a);
        rec(0,0);
        cout << res <<endl;
    }
    return 0;
} 