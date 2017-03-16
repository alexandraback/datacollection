#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t, ct, n;
double a[1000], b[1000];
bool f[1000];
bool check(int x){
    int i, j;
    for(i=n-x,j=0; j<x; i++,j++){
        if(a[i]<b[j])   return 0;
    }
    return 1;
}
int main(){
    int i, j, x, y, low, top, mid;
    freopen("D-large.in", "r", stdin);
    freopen("D-large.out", "w", stdout);
    scanf("%d", &t);
    for(ct=1; ct<=t; ct++){
        scanf("%d", &n);
        for(i=0; i<n; i++)  scanf("%lf", a+i);
        for(i=0; i<n; i++)  scanf("%lf", b+i);
        sort(a,a+n);
        sort(b,b+n);
        x=y=0;
        low=0; top=n;
        while(low<top){
            mid = (low+top+1)/2;
            if(check(mid))  low=mid;
            else    top=mid-1;
        }
        x = low;
        y = 0;
        memset(f,0,sizeof(f));
        for(i=n-1; i>=0; i--){
            for(j=0; j<n; j++){
                if(!f[j] && b[j]>a[i]){
                    f[j]=1;
                    break;
                }
            }
            if(j>=n)    y++;
        }
        printf("Case #%d: %d %d\n",ct,x, y);
    }
    return 0;
}
