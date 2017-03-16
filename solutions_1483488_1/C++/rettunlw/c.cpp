#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
int aa[2222222],t,a,b;
long long ans;

int check(int x,int id){
    int i,j,k,y=x,l=1;
    k=0;
    while (y){
     k++;   
     y/=10;   
     l*=10;
    }
    l/=10;
    j=0;
    for (i=0;i<k;i++){
        x=(x%10)*l+(x/10);
        if (x>=l&&x>=a&&x<=b&&aa[x]<id){
           aa[x]=id;
           j++;                               
        }
    }
    return j*(j-1)/2;
}

int main(){
    freopen("c.in","r",stdin);
    freopen("c.out","w",stdout);
    scanf("%d",&t);
    memset(aa,0,sizeof(aa));
    for (int i=1;i<=t;i++){
        scanf("%d%d",&a,&b);
        ans=0;
        for (int j=a;j<=b;j++)
            if (aa[j]!=i){
               ans+=check(j,i);           
            }    
        printf("Case #%d: %lld\n",i,ans);
    }
    return 0;   
}
