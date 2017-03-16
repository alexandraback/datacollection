#include <iostream>
#include <cstdio>
using namespace std;
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define DOWN(i, a, b) for(int i=a; i>=b; i--)
#define maxn 1005

int test, n, d[maxn][maxn];

int solve(int t)
{
    printf("Case #%d: ", t);
    bool res=false;
    FOR(k, 1, n) {
      FOR(i, 1, n) {
        FOR(j, 1, n) {
          d[i][j]=d[i][j]+d[i][k]*d[k][j];
          if (d[i][j]>=2) d[i][j]=2, res=true;
          if (res) break;
          } if (res) break;} if (res) break;}
    if (res) cout << "Yes" << endl; else cout << "No" << endl;
}

int main()
{
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    cin >> test;
    FOR(t, 1, test) {
           cin >> n;
           int m;
           memset(d, 0, sizeof(d));
           FOR(i, 1, n) {
                  cin >> m;
                  int k;
                  FOR(j, 1, m) cin >> k, d[i][k]=1;
                  }
           solve(t);
           }
    return 0;
}
