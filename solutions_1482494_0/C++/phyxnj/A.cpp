/***
4
2
0 1
0 2
3
2 2
0 0
4 4
1
1 1
5
0 5
0 1
1 1
4 7
5 6	 Case #1: 3
Case #2: 3
Case #3: Too Bad
Case #4: 6

***/
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int a[200],b[200];
struct P
{
    int id;
    int v;
    int a;
    bool operator < (const P & b) const
    {
        if(v==b.v) return id<b.id;
        return v<b.v;
    }
}B[3000];
int f1[2000];
int f2[2000];
int main()
{
   freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    int T,ca=0;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        memset(f1,0,sizeof(f1));
        memset(f2,0,sizeof(f2));
        for(int i=0;i<n;i++){
            scanf("%d%d",&B[i].a,&B[i].v);
            B[i].id=i;
        }
        sort(B,B+n);
//
//        for(int i=0;i<n;i++) {
//            printf("%d %d %d \n",B[i].a,B[i].id,B[i].v);
//        }
        int id2=0;
        int cnt=0;
        while(1){
            while(id2<n&&B[id2].v<=cnt){
                if(f1[B[id2].id]) cnt++;
                else cnt+=2;
                f2[B[id2].id]=1;
                id2++;
            }
            int x=-1;
            for(int i=n-1;i>=0;i--){
                if(B[i].a<=cnt&&!f1[B[i].id]&&!f2[B[i].id]) {
                    x=i;
                    break;
                }
            }
          //  printf("%d\n",x);
            if(x==-1) break;
            f1[B[x].id]=1;
            cnt++;
        }
        //printf("%d\n",cnt);
        int t=0,ans=0;
        for(int i=0;i<n;i++){
            if(f2[i]==0) { t=1;break;}
            else if(f1[i]) ans++;
            ans++;
        }
        printf("Case #%d: ",++ca);
        if(t) puts("Too Bad");
        else printf("%d\n",ans);
    }
}
