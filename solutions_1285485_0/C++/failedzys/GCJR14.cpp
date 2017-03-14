#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
using namespace std;
#define maxn 100
int n,m,Len,x,y,TT,aa[maxn],bb[maxn],Ans;
char Dat[100];
int Gcdit(int x,int y) {
    if (x < y)
        return Gcdit(y,x);
    if (y == 0)
        return x;
    else return Gcdit(y,x % y);
}
void GoForit(int sx,int x,int sy,int y) {
    for (int i = 0; i <= Len; i+=x)
        aa[i]++,aa[i+sx]++;
    for (int i = 0; i <= Len; i+=y)
        bb[i]++,bb[i+sy]++;
    for (int i = 1; i <= Len; i++) for (int j = 1; j <= Len; j++) if (aa[i] != 0 && bb[j] != 0 && i*i+j*j <= Len*Len) {
        int tmp = Gcdit(i,j);
        int tx = i / tmp,ty = j / tmp;
        int qx = tx,qy = ty;
        int FF = 0;
        while (qx != i) {
            if (aa[qx] != 0 && bb[qy] != 0)
                FF = 1;
            qx += tx;
            qy += ty;
        }
        if (FF == 0) {
            Ans++;
        }
    }
}
int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&TT);
    for (int tt = 1; tt <= TT; tt++) {
        scanf("%d%d%d",&n,&m,&Len);
        for (int i = 1; i <= n; i++) {
            scanf("%s",&Dat);
            for (int j = 0; j < m; j++)
                if (Dat[j] == 'X')
                    x = i,y = j+1;
        }
        Ans = 0;
        memset(aa,0,sizeof(aa));
        memset(bb,0,sizeof(bb));
        GoForit(x*2-3,n*2-4,y*2-3,m*2-4);
        memset(aa,0,sizeof(aa));
        memset(bb,0,sizeof(bb));
        GoForit((n-x)*2-1,n*2-4,y*2-3,m*2-4);
        memset(aa,0,sizeof(aa));
        memset(bb,0,sizeof(bb));
        GoForit(x*2-3,n*2-4,(m-y)*2-1,m*2-4);
        memset(aa,0,sizeof(aa));
        memset(bb,0,sizeof(bb));
        GoForit((n-x)*2-1,n*2-4,(m-y)*2-1,m*2-4);
        if (x*2-3 <= Len) Ans++;
        if ((n-x)*2-1 <= Len) Ans++;
        if (y*2-3 <= Len) Ans++;
        if ((m-y)*2-1 <= Len) Ans++;
        printf("Case #%d: %d\n",tt,Ans);
    }
}
