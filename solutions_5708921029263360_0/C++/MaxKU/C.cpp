#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int T,n;
int A,B,C,M,k,u[12][12],v[12][12],num,ans[1010][3];
int main(){
    freopen("C.in","r",stdin);
    freopen("C.out","w",stdout);
    scanf("%d",&T);
    for (int cas=1;cas<=T;cas++){
        printf("Case #%d: ",cas);
        scanf("%d%d%d%d",&A,&B,&C,&M);
        memset(u,0,sizeof(u));
        memset(v,0,sizeof(v));
        num=0;
        k=1;
        int s=min(M,C);
        for (int i=1;i<=A;i++){
            for (int j=1;j<=B;j++){
                for (int l=1;l<=s;l++){
                    if (u[i][k]>=M || v[j][k]>=M) continue;
                    ++num;ans[num][0]=i;ans[num][1]=j;ans[num][2]=k;
                    u[i][k]++;v[j][k]++;
                    k++;if (k>C) k-=C;
                }
            }
        }
        cout<<num<<endl;
        for (int i=1;i<=num;i++) printf("%d %d %d\n",ans[i][0],ans[i][1],ans[i][2]);
    }
    return 0;
}
