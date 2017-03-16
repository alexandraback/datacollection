#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int n,m;
unsigned long long ans;
int x2[101],y2[101];
long long x1[101],y1[101];
unsigned long long sum1[101][101],sum2[101][101],f[101][101];
char u[101][101][101][101];

inline unsigned long long cal(int a,int b,int c,int d) {
    //cout << "##" << a << " " << b << " " << c << " " << d << endl;  
    int i = u[a][b][c][d];
    unsigned long long res = min(sum1[i][b] - sum1[i][a - 1], sum2[i][d] - sum2[i][c - 1]);
        //cout << i << " " << tmp << endl;
    return res; 
}

void solve() {
    //cout << sum1[1][3] << " " << sum1[1][0] << " " << sum2[1][5] << " " << sum2[1][0] << endl;
    //cout << cal(1,1,1,3) << endl;
    ans = 0;
    f[0][0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            f[i][j] = 0;
            for (int p = 0; p < i; p++)
                for (int q = 0; q < j; q++) {
                    unsigned long long tmp = f[p][q] + cal(p + 1, i, q + 1,j);
                    if (tmp > f[i][j]) f[i][j] = tmp;
                }
            //cout << i << " "<< j << ": " << f[i][j] << endl;
            if (f[i][j] > ans) ans = f[i][j];
        }
}

inline unsigned long long wo(char p,int a,int b,int c,int d) {
    if (p == 0) return 0;
    //cout << "##" << (int)p << endl;
    return min(sum1[p][b] - sum1[p][a-1], sum2[p][d] - sum2[p][c-1]);
}

void work() {
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            for (int p = 1; p <= m; p++)
                for (int q = p; q<= m; q++) {
                    unsigned long long t1 = wo(u[i][j-1][p][q], i,j,p,q);
                    unsigned long long t2 = wo(x2[i], i,j,p,q);
                    unsigned long long t3 = wo(u[i][j][p][q-1], i,j,p,q);
                    unsigned long long t4 = wo(y2[p], i,j,p,q);
                    unsigned long long t = max(max(t1,t2), max(t3,t4));
                    if (t1 == t) u[i][j][p][q] = u[i][j-1][p][q];
                    if (t2 == t) u[i][j][p][q] = x2[i];
                    if (t3 == t) u[i][j][p][q] = u[i][j][p][q-1];
                    if (t4 == t) u[i][j][p][q] = y2[p];
                    //cout << t << endl;
                    //cout << i << " " << j << " "<< p << " " << q << ":"<<(int)u[i][j][p][q] << endl;
                }

}

int main(int argc, char *argv[]) {
    int T;
    scanf("%d",&T);
    memset(u,0,sizeof(u));
    for (int i = 1; i <= T ; i++) {
        memset(sum1, 0,sizeof(sum1));
        memset(sum2, 0,sizeof(sum2));
        scanf("%d%d",&n,&m);
        for (int j = 1; j <= n; j++) {
            scanf("%lld%d",&x1[j],&x2[j]);
            sum1[x2[j]][j] = x1[j]; 
        }
        for (int j = 1; j <= m; j++) {
            scanf("%lld%d",&y1[j],&y2[j]);
            sum2[y2[j]][j] = y1[j];
        }
        for (int j = 1; j <= 100; j++) {
            for (int k = 1; k<= 100; k++) {
                sum1[j][k] += sum1[j][k-1];
                sum2[j][k] += sum2[j][k-1];
            }
        }
        work();
        /*
        for (int j = 1; j <= 3; j++) {
            for (int k = 1; k <= 5; k++) 
                cout << sum2[j][k] << " ";
            cout<< endl;
        }
        */
        solve();
        printf("Case #%d: ",i);
        cout << ans << endl;
    }
    return 0;
}
