#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#include <cstring>
using namespace std;
//bool mark[10001];
char key[10], target[10], now[10];
int s, cnt=0, l, k, x, m;
void dfs(int d) {
    if(d==s) {
        int c=0;
        for(int i=l-1, j; i<s; i++) {
            for(j=i-l+1; j<=i; j++)
                if(now[j]!=target[j-(i-l+1)]) break;
            if (j>i) cnt++, c++;

            if(c>m) m=c;
        }
        return;
    }
    for(int i=0; i<k; i++) {
        now[d]=key[i];
        dfs(d+1);
    }
}
int main() {
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    int i, j, T, t, c, d, v, a[8], now, cnt, b[10], k, m, all[2000], ans;
    int p[] = {1,2,4,8,16};
    for(scanf("%d", &T), t=1; t<=T; t++) {
        scanf("%d%d%d", &c,&d,&v);
        for(i=0; i<d; i++) scanf("%d", a+i), b[i]=a[i];
        ans=10000;
        for(i=0; i<1<<5; i++) {
            k=d;
            for(j=0; j<5; j++)
                if(i&(1<<j)) b[k++]=p[j];
            //if((1<<k)<v)
            all[1<<k]=-1;
            for(j=0; j<1<<k; j++) {
                for(m=cnt=0; m<k; m++)
                    if(j&(1<<m)) cnt+=b[m];
                all[j]=cnt;
            }
            sort(all, all+(1<<k));
            for(j=1; j<=v; j++) {
                for(m=0; m<1<<k; m++){
                    if(all[m]>=j) break;
                }
                if(m>=1<<k || all[m]>j) break;
            }
            if(j>v) ans=min(ans,k-d);

        }
        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}
