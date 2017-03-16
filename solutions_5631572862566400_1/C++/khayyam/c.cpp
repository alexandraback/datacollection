#include <stdio.h>
#include <string.h>

int F[1001];
int nRF[1001];
int RF[1001][1001];
int n;

int max_branch(int x){
    int best = 1;
    for(int i=0;i<nRF[x];++i){
        if(RF[x][i] == F[x]){
            continue;
        }
        int opt = 1 + max_branch(RF[x][i]);
        if(opt>best){
            best = opt;
        }
    }
    return best;
}

int cycle_len(int x){
    bool seen[1001];
    memset(seen, 0, sizeof(seen));
    while(!seen[x]){
        seen[x] = true;
        x = F[x];
    }
    int y = F[x];
    int len = 1;
    while(y!=x){
        ++len;
        y = F[y];
    }
    return len;
}

int solve(void){
    int flag[1001];
    memset(flag, -1, sizeof(flag));
    int total = 0;
    int max_cycle = 0;
    for(int i=0;i<n;++i){
        if(flag[i]!=-1){
            continue;
        }
        if(F[F[i]] == i){
            flag[i] = 1;
            flag[F[i]] = 1;
            
            total += max_branch(i);
            total += max_branch(F[i]);
        }else{
            int opt = cycle_len(i);
            if(opt>max_cycle){
                max_cycle = opt;
            }
        }
    }
    
    int sol=total;
    if(max_cycle>sol){
        sol = max_cycle;
    }
    return sol;
}

int main(){
    int T;
    scanf("%d", &T);
    
    for(int t=1;t<=T;++t){
        scanf("%d", &n);
        for(int i=0;i<n;++i){
            nRF[i]=0;
        }
            
        for(int i=0;i<n;++i){
            scanf("%d", &F[i]);
            F[i] -=1;
            RF[F[i]][nRF[F[i]]]=i;
            nRF[F[i]] += 1;
        }
       
        int sol = solve();
        printf("Case #%d: %d\n", t, sol);
        

    }
    return 0;
}

