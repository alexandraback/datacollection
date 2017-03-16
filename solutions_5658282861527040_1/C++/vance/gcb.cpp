#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long LL;
LL ls(int n, int p, int a){
    if(a){
        if((n>>p)&1)
            return n - (1<<p) + 1;
        else
            return 0;
    }else{
        if((n>>p)&1)
            return 1<<p;
        else
            return n + 1;
    }
}
LL ask(int a,int b, int z, int p){
    if(p < 0)
        return 0;
    LL ret = 0;
    if((z>>p)&1){
        ret += ls(a, p, 1)*ls(b, p, 0) + ls(a, p, 0)*ls(b, p, 1) + ls(a, p, 0)*ls(b, p, 0);
        if((a>>p)&1 && (b>>p)&1)
            ret += ask(a - (1<<p), b -(1<<p), z - (1<<p), p-1);
    }else{
        if((a>>p)&1){
            ret += ask(a - (1<<p),min((1<<p) - 1, b), z, p-1);
        }
        if((b>>p)&1){
            ret += ask(min((1<<p) - 1, a),b - (1<<p), z, p-1);
        }
        ret += ask(min((1<<p) - 1, a),min((1<<p) - 1, b), z, p-1);
    }
    //printf("%d %d %d %d %lld\n",a,b,z,p,ret);
    return ret;
}
int main()
{
    int t, a, b, z, i, j, k;
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    scanf("%d",&t);
    for(int cnt = 1;cnt <= t;cnt++){
        scanf("%d %d %d",&a,&b,&z);
        LL ret = 0;
        ret = ask(a - 1,b - 1,z,30);
        printf("Case #%d: %lld\n",cnt,ret);
    }
    return 0;
}
