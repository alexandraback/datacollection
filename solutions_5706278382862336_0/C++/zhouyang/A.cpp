#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#define maxn 1010
using namespace std;
int a,b;
int gcd(int x,int y){
    return y==0?x:gcd(y,x%y);
}
int main (){
    //freopen("A-small-attempt3.in","r",stdin);
   // freopen("A-small-attempt3.out","w",stdout);
    int t;
    scanf("%d",&t);
    for(int Case=1;Case<=t;++Case){
        scanf("%d/%d",&a,&b);
        printf("Case #%d: ",Case);
        if(a>b){printf("impossible\n");continue;}
        int g = gcd(a,b);
        a/=g;
        b/=g;
        if(a==b){printf("0\n");continue;}
        int ans=0;
        while(b%2==0){
            if(a>=b)break;
            b/=2;
            ans++;
        }
        if(a==b){printf("%d\n",ans);continue;}
        a-=b;
        int f=0;
        for(int i=0;i<40;++i){
            if((1<<i)==b){
                f=1;
                break;
            }
        }
        if(!f)printf("impossible\n");
        else printf("%d\n",ans);
    }
}
