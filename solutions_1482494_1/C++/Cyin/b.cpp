#include<stdio.h>
#include<string.h>
int n,a[1010],b[1010];
int va[1010],vb[1010];
int main(){
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    int i;
    int ca,cc=0;
    scanf("%d",&ca);
    while (ca--){
        scanf("%d",&n);
        for (i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
        memset(va,0,sizeof(va));
        memset(vb,0,sizeof(vb));
        int s=0,ans=0,sb=0,flag=0;
        while (1){
            int w=-1,w1=-1;
            for (i=1;i<=n;i++){
                if (vb[i]) continue;
                if (s>=b[i]) {
                    w=i;
                    if (!va[i]) {w1=i;break;}
                }
            }
            if (w1>0){
                sb++;
                ans++;
                s+=2;
                va[w1]=1;vb[w1]=1;
                if (sb==n) {flag=1;break;}
                continue;
            }else if (w>0){
                sb++;
                ans++;
                s++;
                vb[w]=1;
                if (sb==n) {flag=1;break;}
                continue;
            }
            w=-1;
            for (i=1;i<=n;i++){
                if (va[i]||vb[i]) continue;
                if (s>=a[i]){
                    if (w==-1||b[w]<b[i]) w=i;
                }
            }
            if (w<0) break;
            ans++;
            s++;
            va[w]=1;
        }
        cc++;
        if (flag) printf("Case #%d: %d\n",cc,ans);
        else printf("Case #%d: Too Bad\n",cc);
    }
    return 0;
}
            
