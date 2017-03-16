/*

*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
int Case;
int n,m, type[2][102];
long long num[2][102];
bool h[102];
void solve()
{
    long long f[102][102];
    memset(f,0,sizeof(f));
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            for (int i2=0;i2<i;i2++) 
                for (int j2=0;j2<j;j2++) {
                    long long sum = 0;
                    for (int k=1;k<=100;k++) { 
                        long long a=0, b=0;
                        for (int it=i2;it<i;it++)
                            a += type[0][it]==k?num[0][it]:0; 
                        for (int it=j2;it<j;it++)
                            b += type[1][it]==k?num[1][it]:0; 
                        sum = max(sum, min(a, b));
                    }
                    f[i][j] = max(f[i][j], f[i2][j2] + sum);
                }
    cout << f[n][m] << endl;
}
void display()
{
    scanf("%d",&Case);
    for (int ca=1;ca<=Case;ca++) {
        cout << "Case #" << ca << ": ";
        cin >> n >> m;
        for (int i=0;i<n;i++)
            cin >> num[0][i] >> type[0][i];
        for (int i=0;i<m;i++)
            cin >> num[1][i] >> type[1][i];
        memset(h,0,sizeof(h));
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                if (type[0][i] == type[1][j])
                    h[type[0][i]] = true;
        for (int i=0;i<n;i++)
            if (!h[type[0][i]]) {
                for (int j=i+1;j<n;j++) {
                    num[0][j-1] = num[0][j];
                    type[0][j-1] = type[0][j];
                }
                n--;
            }
        for (int i=0;i<m;i++)
            if (!h[type[1][i]]) {
                for (int j=i+1;j<m;j++) {
                    num[1][j-1] = num[1][j];
                    type[1][j-1] = type[1][j];
                }
                m--;
            }
        solve();
    }
}
int main()
{
    freopen("C-small-attempt2.in","r",stdin);
    //freopen("c-test.in","r",stdin);
    freopen("C.out","w",stdout);
    display();
    return 0;
}

