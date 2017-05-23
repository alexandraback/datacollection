#include<stdio.h>
#include<algorithm>
#define siz 1010
using namespace std;
double a[siz],b[siz];
int main(){
//    freopen("D-large.in","r",stdin);
//    freopen("out.txt","w",stdout);
    int t;
    scanf("%d", &t);
    for(int tt=1; tt<=t; tt++){
        int i, j, n, k, cc=0, c=0;
        scanf("%d", &n);
        for(i=0; i<n; i++){
            scanf("%lf", &a[i]);
        }
        for(i=0; i<n; i++){
            scanf("%lf", &b[i]);
        }
        sort(a,a+n);
        sort(b,b+n);
//        for(i=0; i<n; i++){
//            printf("--%lf %lf\n", a[i], b[i]);
//        }
        i=0;j=0;k=n-1;
        while(i<n&&j<=k){
            if(a[i]>b[j]){
                i++;j++;
                cc++;
                continue;
            }
            else{
                i++;k--;
            }
        }
        i=0;j=0;
        while(i<n&&j<n){
            while(j<n&&b[j]<a[i]){j++;}
            if(j==n)break;
            i++;j++;
        }
        printf("Case #%d: %d %d\n",tt, cc,n-i);
    }
    return 0;
}
