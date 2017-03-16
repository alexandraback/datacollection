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

inline unsigned long long cal(int a,int b,int c,int d) {
    //cout << "##" << a << " " << b << " " << c << " " << d << endl;  
    unsigned long long res = 0;
    for (int i = 1; i <= 100; i++) {
        unsigned long long tmp = min(sum1[i][b] - sum1[i][a - 1], sum2[i][d] - sum2[i][c - 1]);
        //cout << i << " " << tmp << endl;
        if (tmp > res) res = tmp;
    }
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

int main(int argc, char *argv[]) {
    int T;
    scanf("%d",&T);

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
