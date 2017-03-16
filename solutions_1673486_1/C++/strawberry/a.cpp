#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
double pro[100005];

int main(){
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int cas,c=0,i,a,b,ta,tb;
    double in,ans,tans;
    scanf("%d",&cas);
    while(cas--){
        scanf("%d%d",&a,&b);
        pro[0]=1;
        for(i=1;i<=a;i++){
            scanf("%lf",&in);
            pro[i]=pro[i-1]*in;
            
        }
        ans=2*(a+b)<b+2?2*(a+b):b+2;
        for(i=0;i<=a;i++){
            ta=b-a+i*2+1;
            tb=ta+b+1;
            tans=pro[a-i]*ta+(1-pro[a-i])*tb;
            ans=ans<tans?ans:tans;
        }
        printf("Case #%d: %lf\n",++c,ans);
    }
    return 0;
}
