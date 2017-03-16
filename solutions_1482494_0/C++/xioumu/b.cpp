/*
 * Author:  xioumu
 * Created Time:  2012-4-28 11:09:03
 * File Name: b.cpp
 * solve: b.cpp
 */
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<string>
#include<map>
#include<set>
using namespace std;
const double esp = 1e-8;
const int maxn = 1007;
typedef long long ll;
struct node{
    int x[2];
};
node a[maxn];
int v[maxn][2];
int n;
int main(){
    int t;
    int i,j;
    freopen("b.out","w",stdout);
    scanf("%d",&t);
    for(int ti = 1; ti <= t; ti++){
        memset(v, 0, sizeof(v));
        scanf("%d",&n);
        for(i=1; i<=n; i++)
            scanf("%d %d",&a[i].x[0], &a[i].x[1]);
        int num = 0, ans = 0, oknum = 0;
        for(i=1; i<=2 * n; i++){
            for(j=1; j<=n; j++){
                if(!v[j][1] && num >= a[j].x[1]){
                    ans++;
                    oknum++;
                    num += 2;
                    v[j][1] = 1;
                    break;
                }
            }
            if(oknum == n) break;
            if(j <= n) continue;
            int r = 0;
            for(j=1; j<=n; j++)
                if(!v[j][0] && !v[j][1] && num >= a[j].x[0]){
                    if(!r || a[j].x[1] > a[r].x[1])
                        r = j;
                }
            if(r == 0) break;
            v[r][0] = 1;
            ans++;
            num += 1;
        }
        printf("Case #%d: ",ti);
        if(oknum != n) printf("Too Bad\n");
        else printf("%d\n",ans);
    }
    return 0;
}
