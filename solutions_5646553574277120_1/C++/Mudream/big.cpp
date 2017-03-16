#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <cmath>

using namespace std;

typedef long long int int64;

int main(){
    int T; scanf("%d", &T);
    for(int lt = 1;lt <= T;lt++){
        int64 C; int D; int64 V; scanf("%lld %d %lld", &C, &D, &V);
        int64 ds[100];
        for(int lx = 0;lx < D;lx++) scanf("%lld", ds+lx);
        sort(ds, ds+D);
        int64 rg = 0;
        int cnt = 0, ptr = 0;
        while(rg < V){
            int64 inp;
            if(ptr < D and ds[ptr] <= rg+1)
                inp = ds[ptr++];
            else{
                inp = rg+1, cnt++;
            }
            rg += inp*C;
        }
        printf("Case #%d: %d\n", lt, cnt);
    }
    return 0;
}
