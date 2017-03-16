#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
using namespace std;
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define DOW(i, a, b) for(int i=a; i>=b; i--)
#define FOREACH(it, c) for(typeof(c.begin()) it=c.begin(); it!=c.end(); it++)
#define RESET(c, val) memset(c, val , sizeof(c))

#include <conio.h>

int test, n, x, y;
double f[1000][1000];

void solve(int test) {
    printf("Case #%d: ", test);
    cin >> n >> x >> y;
    if (x<0) x=-x;
    FOR(i, 0, (x+y)/2-1) n-=4*i+1;
    if (n<=0) printf("0\n");
    else if (n>=(4*(x+y)/2+1)) printf("1\n");
    else {
        int k=4*(x+y)/2+1; k=(k-1)/2;
        int a=y+1;
        //cout << n << " " << " " << k << " " << a << endl;
        RESET(f, 0);
        f[0][0]=1;
        FOR(i, 1, n) FOR(j, 0, k) if (i-j<=k) {
            if (j>0) {
                if (i-j<k) f[i][j]+=f[i-1][j-1]/2;
                else if (i-j==k) f[i][j]+=f[i-1][j-1];
            }
            
                if (j<k) f[i][j]+=f[i-1][j]/2;
                else if (j==k) f[i][j]+=f[i-1][j];
            
        }
        double res=0;
        FOR(j, a, k) res+=f[n][j];
        printf("%.9lf\n", res);
    }
}
int main() {
    //freopen("r1b_2s.in", "r", stdin);
    freopen("test.in", "r", stdin);
    freopen("test2.out", "w", stdout);
    cin >> test;
    FOR(t, 1, test) solve(t);
    getch();
    return 0;
}
