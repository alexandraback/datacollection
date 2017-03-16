#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <string>
#include <cstring>
#include <iostream>
#include <ctime>

using namespace std;

#define TASKNAME "B"

long long a,b,k;
long long f[99][4][4][4];
long long bita[99],bitb[99],bitk[99];
int read(){
    scanf("%lld%lld%lld",&a,&b,&k);
    a--;
    b--;
    k--;
    for (int i=0;i<32;i++) bita[i]=((a>>i)&1);
    for (int i=0;i<32;i++) bitb[i]=((b>>i)&1);
    for (int i=0;i<32;i++) bitk[i]=((k>>i)&1);
    return 0;
}
long long dq(int i,int oka,int okb,int okk){
    // printf("",i,oka,okb );
    if (i<0) return 1;
    if (f[i][oka][okb][okk]>-1) return f[i][oka][okb][okk];
    int ma,mb,mk;
    ma=bita[i];
    mb=bitb[i];
    mk=bitk[i];
    if (oka) ma=1;
    if (okb) mb=1;
    if (okk) mk=1;
    long long sum=0;
    for (int c1=0;c1<=ma;c1++){
        for (int c2=0;c2<=mb;c2++){
            for (int c3=0;c3<=mk;c3++){
                if ((c1&c2)==c3) 
                    sum+=dq(i-1,oka|(c1<bita[i]),okb|(c2<bitb[i]),okk|(c3<bitk[i]));
            }
        }
    }
    f[i][oka][okb][okk]=sum;
    return sum;
}
int process(){
    for (int i=0;i<=32;i++){
        for (int j=0;j<2;j++){
            for (int k=0;k<2;k++) 
                for (int l=0;l<2;l++) f[i][j][k][l]=-1;
        }
    }
    printf("%lld",dq(31,0,0,0) );
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen(TASKNAME".inp","r",stdin);
    freopen(TASKNAME".out","w",stdout);
    #endif // ONLINE_JUDGE
    int sotest;
    scanf("%d",&sotest);
    // sotest=1;
    for (int test=1;test<=sotest;test++){
        printf("Case #%d: ",test);
        read();
        process();
        printf("\n");
    }

    return 0;
}
