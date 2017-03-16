#include <cstdio>
#include <cstdlib>

using namespace std;

typedef long long int int64;

int64 p10[100];

int64 high(int64 val){
    int64 ret = 0;
    while(val >= 10)
        ret++, val/=10;
    return ret;
}

int64 dump(int64 val){
    int64 hh = high(val);
    if(hh == 0) return val;
    int64 hd = val/p10[hh];
    int64 mn = (hd-1)*(p10[hh]-2); 
    return dump(p10[hh]-1) + 1 + val%p10[hh] + (hd-1)*(p10[hh]) - mn;
}

int main(){
    p10[0] = 1;
    for(int lx = 1;lx <= 14;lx++)
        p10[lx] = p10[lx-1]*10;
    int T; scanf("%d", &T);
    for(int lt = 1;lt <= T;lt++){
        int64 inp; scanf("%lld", &inp);
        printf("Case #%d: %lld\n", lt, dump(inp));
    }
    return 0;
}
