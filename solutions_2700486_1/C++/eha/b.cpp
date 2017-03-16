#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <complex>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define pb push_back
#define mp make_pair
using namespace std;

double comb(int n,int k){
    double ret = 1;
    for(; k > 0 ; k--,n--){
        ret *= n;
        ret /= k;
    }
    return ret;
}

double solve(){
    int n,x,y,d,lv;
    scanf("%d%d%d",&n,&x,&y);
    x = abs(x);
    d = x + y;
    d /= 2;

    lv = (sqrt(8*n+1)-3)/4;
    if(d <= lv) return 1.0;
    if(d >= lv+2) return 0.0;
    int k = n - ((lv+1)*(2*lv+1));
    int h = lv*2+2;
    x--;

    if(x<0) return 0;

    int z = k - h;

    //printf("level:%d left:%d height:%d / %d, z : %d\n",lv,k,x,h,z);
    if(z<=0){
        double ans = 0;
        //printf("[%d %d %d]",h,h-k,x-h+k);
        rep(i,x-h+k+1) ans += comb(k,i);
        ans /= pow(2,k);
        return ans;
    } else {
        if(h-z <= x) return 1;
        double ans = 0;
        rep(i,x+z+1) ans += comb(k,i);
        ans /= pow(2,k);
        return ans;
    }
    return -1.0;
}

int main(){
    int t;
    scanf("%d",&t);
    rep(tc,t) printf("Case #%d: %.9f\n",tc+1,solve());
    return 0;
}
