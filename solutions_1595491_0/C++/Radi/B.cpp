#include <stdio.h>
#include <algorithm>
using namespace std;
int arr[200];
inline int min(int a,int b){return a<b?a:b;}
int main(){
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    int t,n,s,p,i,j,lim,res;
    scanf("%d",&t);
    for(int cc=1;cc<=t;++cc){
        scanf("%d%d%d",&n,&s,&p);
        for(i=1;i<=n;++i) scanf("%d",&arr[i]);
        sort(arr+1,arr+1+n);
        if(p>1) lim=p+2*(p-1);
        else lim=p;
        for(i=1;i<=n;++i) if(arr[i]>=lim) break;
        if(p>1) lim=p+2*(p-2);
        else lim=p;
        for(j=1;j<=n;++j) if(arr[j]>=lim) break;
        res=n-i+1+min(i-j,s);
        printf("Case #%d: %d\n",cc,res);
    }
    return 0;
}
