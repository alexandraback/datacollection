#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

double solve(int x,int y){
    int i;
    double tem=1.0;
    for(i=1;i<=x;i++){
        tem*=(1+y-i);
        tem/=i;
        tem/=2;
    }
    for(;i<=y;i++) tem/=2;
    return tem;
}

int main(){
    int t,T,i,j,tot,nowx,nowy;
    int n,x,y;
    freopen("B-small-attempt1.in","r",stdin);
    freopen("e.txt","w",stdout);
    scanf("%d",&T);
    for(t=1;t<=T;t++){
        scanf("%d %d %d",&n,&x,&y);
        for(i=1;;i++){
            if((2*i*i-i)>=n) break;
        }
        nowx=1+(abs(x)+y)/2;
        nowy=y+1;
        if(nowx>i){
            printf("Case #%d: 0.0\n",t);
            continue;
        }
        else if(nowx<i){
            printf("Case #%d: 1.0\n",t);
            continue;
        }
        else if((2*i*i-i)==n){
            printf("Case #%d: 1.0\n",t);
            continue;
        }
        else{
            int have=n-2*(i-1)*(i-1)+(i-1);
            double ans=0,all=0;
            for(j=0;j<=have && j<=2*(i-1);j++){
                if(have-j>2*(i-1))continue;
                all+=solve(j,have);
                if(j>=nowy)
                    ans+=solve(j,have);
                //printf("***%.6Lf  %.6Lf\n",ans,all);
            }
            //printf("%.6Lf\n",ans/all);
            printf("Case #%d: %.6f\n",t,ans/all);
            //cout << ans/all <<endl;
        }
    }
    return 0;
}
