#include<stdio.h>
#define sc(b,c) fscanf(in,b,c)
#define pr(b,c) fprintf(out,b,c)
#define eps 1e-9
FILE *in,*out;
int i,j;
int s,n;
int ar[1000];
double ans[1000];
int solve(double x){
    double y=ar[i]+(s*x/100);
    int k=0,midx;
    double tsum=100-x;
    double max=-1.0;
    for(midx=0;midx<n;midx++){
        if(midx!=i){
            double low=0.0,mid,high=100.0;
            while((high-low)>1e-9){
                mid=(high+low)/2;
                int d=0;
                double ss=mid,val=ar[midx]+(mid*s/100);
                int ans=1;
                for(d=0;d<n;d++){
                    if(d!=i && d!=midx){
                        ss+=((val-ar[d])*100/s);
                    }
                }
                if(ss+eps>tsum) ans=0;
                if(ans) low=mid;
                else high=mid;
            }
            if(max<(low*s/100+ar[midx])) max=(low*s/100+ar[midx]);
        }
    }
    return max<=y;
}
int main(){
    in = fopen("input.txt","r");
    out = fopen("output.txt","w");
    int T,N,P,S,cases=1;
    sc("%d",&T);
    int st=T;
    while(T--){
        s=0;
        sc("%d",&n);
        for(i=0;i<n;i++) sc("%d",&ar[i]),s+=ar[i];
        pr("Case #%d: ",cases);
        for(i=0;i<n;i++){
            double low=0.0,high=100.0,mid;
            while((high-low)>1e-9){
                mid=(low+high)/2.0;
                if(solve(mid)) high=mid;
                else low=mid;
            }
            fprintf(out,"%.8lf ",low);
        }
        fprintf(out,"\n");
        cases++;
    }
    return 0;
}
