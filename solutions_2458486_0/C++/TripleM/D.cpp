#include <iostream>
using namespace std;
int init[201];
int chestneed[20];
int chestK[20];
int chestkeys[20][1000];
int have[201];
int next[1<<20];
int main() {
    int T; scanf("%d",&T); for (int t=1; t<=T; t++) {
        int N,K; scanf("%d %d",&K,&N); assert(K<1000);
        memset(init,0,201*sizeof(int));
        for (int i=0; i<K; i++) {
            int key; scanf("%d",&key); init[key]++;
        }
        for (int i=0; i<N; i++) {
            scanf("%d %d",&chestneed[i],&chestK[i]);
            assert(chestK[i]<1000);
            for (int j=0; j<chestK[i]; j++) scanf("%d",&chestkeys[i][j]);
        }
        
        next[(1<<N)-1]=0;
        
        for (int i=(1<<N)-2; i>=0; i--) {
            for (int j=0; j<=200; j++) have[j] = init[j];
            for (int j=0; j<N; j++) if (i&(1<<j)) {
                have[chestneed[j]]--;
                for (int k=0; k<chestK[j]; k++) have[chestkeys[j][k]]++;
            }
            
            next[i] = -1;
            
            for (int j=0; j<N && next[i]==-1; j++) {
                if (i&(1<<j)) continue;
                if (have[chestneed[j]] && next[i|(1<<j)]!=-1) {
                    next[i] = j;
                    break;
                }
            }
        }
        
        printf("Case #%d:",t);
        if (next[0]==-1) printf(" IMPOSSIBLE\n");
        else {
            int state = 0;
            while (state!=(1<<N)-1) {
                printf(" %d",next[state]+1);
                state |= 1<<next[state];
            }
            printf("\n");
        }
    }
}
