#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

// (1,i,j,k,-1,-i,-j,-k)

int a[4][4] =  {{0,1,2,3},{1,4,3,6},{2,7,4,1},{3,2,5,4}};

int mul(int x, int y){
    int p = (x/4) ^ (y/4);
    
    return (4 * p) ^ a[x%4][y%4];
}

int n;
long long t;
char str[10005];

int fast_mul(int x, long long time){
    if(time == 1) return x;
    int t = fast_mul(x,time/2);
    t = mul(t,t);
    if(time&1) t = mul(t,x);
    return t;
}

bool solve(){
    int low_pos = 1e9;
    long long high_pos = -1;
    
    scanf("%d %lld %s",&n,&t,str);
    int p = 0;
    for (int i=0; i<n; i++) {
        p = mul(p,str[i] - 'i' + 1);
    }
    if(fast_mul(p,t) != 4) return 0;
    
    p = 0;
    for (int i=0; i<8 && i<t; i++) {
        for (int j=0; j<n; j++) {
            if(p == 1){
                low_pos = i * n + j;
                break;
            }
            p = mul(p,str[j] - 'i' + 1);
        }
        if(low_pos < 1e9) break;
    }
    
    p = 0;
    for (long long i = t-1; i>=0 && i >= t-8; i--) {
        for (int j=n-1; j>=0; j--) {
            p = mul(str[j] - 'i' + 1,p);
            if(p == 3){
                high_pos = i * n + j;
                break;
            }
        }
        if(high_pos >= 0) break;
    }
    return low_pos < high_pos;
}

int main(){
    freopen("C-small-attempt0.in","r",stdin);
    freopen("output","w",stdout);
    int t;
    scanf("%d",&t);
    for (int i=1; i<=t; i++) {
        printf("Case #%d: ",i);
        puts(solve()?"YES":"NO");
    }
}