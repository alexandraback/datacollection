#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;
char s[20000];

const int d[5][5] = {{1, 2, 3, 4},
        {2,-1, 4,-3},
        {3,-4,-1, 2},
        {4, 3,-2,-1}
};

int vis[10][10100];

int main(){
        int tt, ca = 0;
        scanf("%d",&tt);
        while (tt--){
                LL n,k;
                scanf("%lld%lld",&n,&k);
                scanf("%s",s);

                int m = k % 4;
                int t = 1;
                while (m --){
                        for (int i = 0;i < n;i ++){
                                int p = s[i] - 'i' + 2;
                                if (t > 0) t = d[t - 1][p - 1];
                                else t = -1 * d[-t - 1][p - 1];
                        }
                }
                bool flag;
                if (t == -1){
                        flag = true;
                        int t = 1;
                        memset(vis,0,sizeof(vis));
                        bool flagi = false, flagj = false;
                        while (k --){
                                for (int i = 0;i < n;i ++){
                                        int p = s[i] - 'i' + 2;
                                        if (vis[t + 4][i]) {
                                                flag = false;
                                                break;
                                        }
                                        vis[t + 4][i] = 1;
                                        
                                        //cout << i << " before: " << t << ' ' << p << endl;
                                        if (t > 0) t = d[t - 1][p - 1];
                                        else t = -1 * d[-t - 1][p - 1];
                                        //cout << i << " after: " << t << endl;
                                        
                                        if (!flagi && t == 2){
                                                flagi = true;
                                                t = 1;
                                                memset(vis,0,sizeof(vis));
                                        }

                                        if (flagi && t == 3){
                                                flagj = true;
                                                break;
                                        }
                                }
                                if (!flag) break;
                                if (flagi && flagj) break;
                        }    
                        if (flagi && flagj) flag = true;
                        else flag = false;
                }
                else flag = false;

                printf("Case #%d: ", ++ca);
                if (flag) printf("YES\n");
                else printf("NO\n");
        }
}
