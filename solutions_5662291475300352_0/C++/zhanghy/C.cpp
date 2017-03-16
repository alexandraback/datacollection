#include <bits/stdc++.h>

using namespace std;

int T,N,D,H,M;
int d[3];
double v[3];

int main() {
    freopen("C.in","r",stdin);
    freopen("output1.out","w",stdout);
    scanf("%d",&T);
    for (int kase = 1;kase <= T; kase++) {
           scanf("%d",&N);
           int cnt = 0,ans = 0;
           for (int i = 1;i <= N; i++) {
                scanf("%d%d%d",&D,&H,&M);
                for (int j = 1;j <= H; j++) {
                        cnt++; d[cnt] = D; v[cnt] = 360.0/M;
                        M++;
                }
            }
           // cout<<cnt<<endl;
            if (cnt == 1) {
                if (d[1] == 0) ans = 1;
                else ans = 0;
            }else {
                //cout<<"hello"<<endl;
                if (d[1] == d[2] && d[1] == 0) ans = 2;
                else if (d[1] == 0 || d[2] == 0) ans = 1;
                else {
                    if (d[1] < d[2] || (d[1] == d[2] && v[1] <= v[2])) swap(d[1],d[2]),swap(v[1],v[2]);
                        if (v[1] <= v[2]) ans = 0;
                        else {
                            int w = 360-d[1]+d[2];
                            if (w / (v[1]-v[2])*v[2]+d[2] > 360) ans = 0;
                            else ans = 1;
                        }
                }
            }
            printf("Case #%d: %d\n",kase,ans);
    }
    return 0;
}
