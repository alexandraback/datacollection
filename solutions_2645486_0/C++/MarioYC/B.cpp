#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int N;
long long E,R;
int v[10000],best[10000];
long long memo[10000];

long long solve(int pos){
    if(pos == N) return 0;
    long long &ret = memo[pos];
    
    if(ret == -1){
        ret = 0;
        
        long long e = (pos == 0? E : R);
        long long aux = 0;
        
        for(int i = pos;i < N;++i){
            ret = max(ret,aux + e * v[i] + solve(i + 1));
            long long spend = max(0LL,e + R - E);
            e = e + R - spend;
            aux += spend * v[i];
        }
    }
    
    return ret;
}

int main(){
    int T;
    
    scanf("%d",&T);
    
    for(int tc = 1;tc <= T;++tc){
        scanf("%lld %lld %d",&E,&R,&N);
        R = min(R,E);
        
        for(int i = 0;i < N;++i)
            scanf("%d",&v[i]);
        
        memset(memo,-1,sizeof memo);
        
        printf("Case #%d: %lld\n",tc,solve(0));
    }
    
    return 0;
}
