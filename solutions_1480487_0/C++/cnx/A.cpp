#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int n,sum,a[203];

bool check(double v){
    double cnt=0;
    for(int i=0;i<n;++i)
        if(v>a[i])
            cnt+=v-a[i];
    //printf("%.2f %.2f\n",v,cnt);
    return cnt-1e-7>sum;
}

int main(){
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    int _,cas=0;
    for(scanf("%d",&_);_--;){
        scanf("%d",&n);
        for(int i=0;i<n;++i)
            scanf("%d",a+i);
        sum=0;
        for(int i=0;i<n;++i)
            sum+=a[i];
        printf("Case #%d: ",++cas);
        for(int i=0;i<n;++i){
            double l=0,r=double(sum-a[i])/sum;
            while(r-l>1e-8){
                double mid=(l+r)/2.0;
                if(check(mid*sum+a[i]))r=mid;
                else l=mid;
            }
            if(i)putchar(' ');
            printf("%.6f",l*100);
        }
        puts("");
    }
    return 0;
}
