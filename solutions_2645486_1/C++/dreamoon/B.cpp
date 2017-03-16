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
#define SIZE 10001
int cs,a[SIZE],ll[SIZE],rr[SIZE],used[SIZE],tt,R;
struct data{
    int id,v;
    bool operator<(const data& b)const{return v>b.v;}
}d[SIZE];
void go(int x,int n){
    int i;
    rr[x]=ll[x];
    for(i=x+1;i<n;i++){
        //printf("[%d,%lld]\n",rr[i],(long long)R*(i-x)+ll[x]);
        if(rr[i]>(long long)R*(i-x)+ll[x]){
            rr[i]=(long long)R*(i-x)+ll[x];
        }
        else break;
    }
    if(x){
        ll[x-1]=rr[x-1];
        for(i=x-2;i>=0;i--){
            if(ll[i]<ll[i+1]-R)
                ll[i]=ll[i+1]-R;
            else break;
        }
    }
}
int main(){
    int T,i,j,k,n,E;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&E,&R,&n);
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
            d[i]=(data){i,a[i]};
        }
        sort(d,d+n);
        for(i=0;i<n;i++)ll[i]=0,rr[i]=E-R;
        rr[n-1]=E;
        for(i=0;i<n;i++){
            //printf("[%d]\n",d[i].id);
            //for(j=0;j<n;j++)printf("(%d,%d)\n",ll[j],rr[j]);
            go(d[i].id,n);
        }
        long long an=(long long)(E-ll[0])*a[0];
        for(i=1;i<n;i++)an+=(long long)a[i]*(min(E,ll[i-1]+R)-ll[i]);
        printf("Case #%d: %lld\n",++cs,an);
    }
    return 0;
}

