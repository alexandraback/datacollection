#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
using namespace std;

int a[300];
double b[300],ans[300],sum;
int n;

bool check(double kk,double k,int now){
//    cout << k << endl;
    double left=1-kk;
    for (int i=1;i<=n;++i){
        if (i==now) continue;
        if (b[i]>=k) continue;
        double tmp=(k-b[i])/sum;
        left-=tmp;
        if (left<0) return true;
    }
    return false;
}

int main(){
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    
    int _,cas=0;
    scanf("%d",&_);
    while (_--){
        sum=0;
        scanf("%d",&n);
        for (int i=1;i<=n;++i){ 
            scanf("%d",&a[i]);
            b[i]=a[i];
            sum+=a[i];
        }
        printf("Case #%d: ",++cas);
        for (int i=1;i<=n;++i){
            double l=0,r=1,mid;
            while (fabs(l-r)>1e-8){
                mid=(l+r)/2;
                if (check(mid,b[i]+sum*mid,i)) r=mid;
                else l=mid;
            }
            if (i==1) printf("%.6f",mid*100);
            else printf(" %.6f",mid*100);
        }
        puts("");
    }
    return 0;
}
            
