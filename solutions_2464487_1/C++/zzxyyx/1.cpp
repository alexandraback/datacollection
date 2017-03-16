#include<stdio.h>
bool bi(double n,double r,double sum){
    return sum>(n*(n*2-1)+2*n*r)-1e-8;
}
int main(){
    freopen("in.in","r",stdin);
    freopen("out.txt","w",stdout);
    int l,r,mid;
    double sum,rad;
    int cs,csi;
    scanf("%d",&cs);
    for(csi=1;csi<=cs;csi++){
        printf("Case #%d: ",csi);
        l=0;r=1000000000;
        scanf("%lf%lf",&rad,&sum);
        while(l<r){
            mid=l+r>>1;
            if(bi(mid,rad,sum))l=mid+1;
            else r=mid;
        }
        printf("%d\n",r-1);
    }
    return 0;
}
