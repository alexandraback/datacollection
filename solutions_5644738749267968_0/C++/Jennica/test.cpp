#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int main(){
    //freopen("B-large.in","r",stdin);
    freopen("D-small-attempt0.in","r",stdin);
    freopen("D.out","w",stdout);
    int T,tc=0,n,i,j,sa,sb;
    double a[1010],b[1010];
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(i=0;i<n;++i) scanf("%lf",&a[i]);
        for(i=0;i<n;++i) scanf("%lf",&b[i]);
        sa=sb=0;
        sort(a,a+n);
        sort(b,b+n);
        j=0;
        for(i=0;i<n;++i){
            if(a[i]>b[j]){
                ++sa;
                ++j;
            }
        }
        j=0;
        for(i=0;i<n;++i){
            if(b[i]<a[j]){
                ++sb;
            }else{
                ++j;
            }
        }
        printf("Case #%d: %d %d\n",++tc,sa,sb);
    }
    return 0;
}
