#include<cstdio>
#include<cstring>
int main(){
    freopen("B-large.in","r",stdin);
    //freopen("B-small-attempt0.in","r",stdin);
    freopen("B.out","w",stdout);
    int T,tc=0;
    double t,speed,c,f,x;
    scanf("%d",&T);
    while(T--){
        scanf("%lf%lf%lf",&c,&f,&x);
        t=0,speed=2;
        if(c>x){
            t=x/speed;
            goto L;
        }
        t=c/speed;
        //printf("tadd=%f\n",c/speed);
        while(1){
            if(c*speed<(x-c)*f){
                speed+=f;
                t+=c/speed;
          //      printf("tadd=%f\n",c/speed);
            }else{
                t+=(x-c)/speed;
                break;
            }
        }
        L:
        printf("Case #%d: %.8f\n",++tc,t);
    }
    return 0;
}
