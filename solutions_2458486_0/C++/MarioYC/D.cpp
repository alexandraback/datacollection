#include <cstdio>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

int K,N;
int memo[(1 << 20)],choose[(1 << 20)];
int init[201];
int want[20];
vector<int> give[20];

int solve(int mask){
    if(mask == 0) return 1;
    int &ret = memo[mask];
    
    if(ret == -1){
        ret = -2;
        map<int, int> cont;
        
        for(int i = 0;i < K;++i)
            cont[ init[i] ] += 1;
        
        for(int i = 0;i < N;++i)
            if((mask >> i & 1) == 0){
                for(int j = give[i].size() - 1;j >= 0;--j)
                    cont[ give[i][j] ] += 1;
                cont[ want[i] ] -= 1;
            }
        
        for(int i = 0;i < N;++i){
            if(mask >> i & 1){
                if(cont.find(want[i]) != cont.end() && cont[ want[i] ] > 0){
                    int aux = solve(mask ^ (1 << i));
                    if(aux != -2){
                        ret = 1;
                        choose[mask] = i;
                        break;
                    }
                }
            }
        }
    }
    
    return ret;
}

int main(){
    int T;
    
    scanf("%d",&T);
    
    for(int tc = 1;tc <= T;++tc){
        scanf("%d %d",&K,&N);
        
        for(int i = 0;i < K;++i)
            scanf("%d",&init[i]);
        
        for(int i = 0,sz;i < N;++i){
            give[i].clear();
            scanf("%d %d",&want[i],&sz);
            for(int j = 0,key;j < sz;++j){
                scanf("%d",&key);
                give[i].push_back(key);
            }
        }
        
        memset(memo,-1,sizeof memo);
        
        int mask = (1 << N) - 1;
        int ans = solve(mask);
        
        printf("Case #%d:",tc);
        if(ans == -2) puts(" IMPOSSIBLE");
        else{
            while(mask){
                int cur = choose[mask];
                mask ^= (1 << cur);
                printf(" %d",cur + 1);
            }
            printf("\n");
        }
    }
    
    return 0;
}
