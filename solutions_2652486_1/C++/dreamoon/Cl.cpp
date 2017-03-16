#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<set>
#include<iostream>
#include<map>
#include<queue>
#include<bitset>
#include<string>
#include<stdlib.h>
#include<sstream>
#define pb push_back
using namespace std;
int cs,p[8];
long long a[15];
int num[5][2]={{1,0},{0,1},{2,0},{1,1},{3,0}};
char digit[12]="23468";
long long ma,mi;
char s[24],ha[24];
void dfs(int x,int now,int N,int two,int three,long long v,long long v2){
    int i;
    if(now==4){
        for(i=x;i<N;i++)s[i]=digit[4],v/=(i-x+1),v2*=8;
        //printf("[%lld]\n",v);
        two-=(N-x)*num[4][0];
        three-=(N-x)*num[4][1];
        if(two<=0&&three<=0){
            if(v2<mi||(v2==mi&&v>ma)){
                mi=v2;
                ma=v;
                for(i=0;i<N;i++)ha[i]=s[i];
            }
        }
        return;
    }
    for(i=x;i<=N;i++){
        dfs(i,now+1,N,two,three,v,v2);
        if(i==N)break;
        s[i]=digit[now];
        v2*=digit[now]-'0';
        v/=(i-x+1);
        two-=num[now][0];
        three-=num[now][1]; 
    }
}
void go(int N,int two,int three){
    ma=0;
    mi=1ll<<60;
    long long v=1;
    int i;
    for(i=1;i<=N;i++)v*=i;
    s[N]=0;
    dfs(0,0,N,two,three,v,1);
    //if(v==(1ll<<60))fprintf(stderr,"error!\n");
    for(i=0;i<N;i++){
        printf("%c",ha[i]);
        //if(ha[i]<'2'||ha[i]>'8')fprintf(stderr,"error!:%d,%d\n",i,(int)ha[i]);
    }
    puts("");

}
int main(){
    int T,i,j,k,R,N,M,K;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d%d",&R,&N,&M,&K);
        printf("Case #%d:\n",++cs);
        while(R--){
            p[2]=p[3]=p[5]=p[7]=0;
            for(i=0;i<K;i++){
                scanf("%lld",&a[i]);
                int cnt=0;
                while(a[i]%2==0){
                    a[i]/=2;
                    cnt++;
                }
                p[2]=max(p[2],cnt);
                cnt=0;
                while(a[i]%3==0){
                    a[i]/=3;
                    cnt++;
                }
                p[3]=max(p[3],cnt);
                cnt=0;
                while(a[i]%5==0){
                    a[i]/=5;
                    cnt++;
                }
                p[5]=max(p[5],cnt);
                cnt=0;
                while(a[i]%7==0){
                    a[i]/=7;
                    cnt++;
                }
                p[7]=max(p[7],cnt);
            }
            for(i=0;i<p[5];i++)printf("5");
            for(i=0;i<p[7];i++)printf("7");
            go(N-p[5]-p[7],p[2],p[3]);
        }
    }
    return 0;
}

