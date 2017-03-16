#include<cstdio>
#include<algorithm>
using namespace std;
int T,n;
long long x[300],a,b;
bool chk(long long k){
    long long x = 0,y=0;
    y = k;
    while(k){
        x *= 10LL;
        x += k%10;
        k /= 10LL;
    }
    if(x == y) return true;
    return false;
}
int B(int i,int j,long long k){
    if(i>j) return j;
    int m = (i+j)/2;
    if(x[m]>k) return B(i,m-1,k);
    else return B(m+1,j,k);
}
int main(){
    freopen("C-large-1.in","r",stdin);
    freopen("out.txt","w",stdout);
    for(long long i = 1LL;i<=4069307LL;i++){
        if(chk(i)&&chk(i*i))
            x[n++] = i*i;
    }
    scanf("%d",&T);
    for(int r=1;r<=T;r++){
        scanf("%lld%lld",&a,&b);
        printf("Case #%d: %d\n",r,B(0,n-1,b)-B(0,n-1,a-1));
    }
    return 0;
}
