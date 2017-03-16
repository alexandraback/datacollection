#include<fstream>
using namespace std;
long long start[20],dv[20];


long long solve()
{
    long long tp;

    if(start[0]>start[1]){
        tp=start[0];
        start[0]=start[1];
        start[1]=tp;

        tp=dv[0];
        dv[0]=dv[1];
        dv[1]=tp;
    }

    if((360-start[0])*dv[0]<=(360-start[1])*dv[1]){
        if((720-start[0])*dv[0]<=(360-start[1])*dv[1]){
            return 1;
        }else{
            return 0;
        }
    }else{
        if((360-start[0])*dv[0]>=(720-start[1])*dv[1]){
            return 1;
        }else{
            return 0;
        }
    }
    return 0;
}


int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    long long i,T,j,k,p,w;
    scanf("%lld",&T);
    for(i=1;i<=T;i++){
        scanf("%lld",&k); w=0;
        for(j=0;j<k;j++){
            scanf("%lld %lld %lld",&start[j],&p,&dv[j]);
            if(p==2){
                start[k+w]=start[j]; dv[k+w]=dv[j];
                w++;
            }
        }
        w=solve();
        printf("Case #%lld: %lld\n",i,w);
    }
    return 0;
}
