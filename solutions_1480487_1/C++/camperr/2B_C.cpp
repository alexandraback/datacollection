#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const double eps=1e-9;
int n;
double pnt[207],res[207],sum;
int main(){
    int t,i,j,k;
    freopen("in.txt","r",stdin);
    freopen("A-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d",&t);
    for(j=1;j<=t;j++){
        scanf("%d",&n);
        sum=0;
        for(i=0;i<n;i++) {
            scanf("%lf",pnt+i);
            sum+=pnt[i];
        }
        double l,r,mid,x,y;
        for(i=0;i<n;i++){
            l=0,r=1.0;
            while(r-l>eps){
                mid=(l+r)/2;
                x=pnt[i]+sum*mid;
                bool yes=true;
                k=0,y=0;
                for(int a=0;a<n;a++){
                    //if(j==2 && a==0) printf("%.8lf %.8lf\n",pnt[a],x+1e-7);
                    if(a!=i && pnt[a]<x){
                        y+=pnt[a];
                        k++;
                    }
                }
                if(k){
                    if(x*k<(y+sum*(1-mid))+eps) yes=false;
                }else yes=false;
                if(yes) r=mid;
                else l=mid;
            }
            res[i]=mid;
        }
        printf("Case #%d: ",j);
        for(i=0;i<n;i++) {
            printf("%f",res[i]*100);
            if(i!=n-1) printf(" ");
            else printf("\n");
        }
    }
}
