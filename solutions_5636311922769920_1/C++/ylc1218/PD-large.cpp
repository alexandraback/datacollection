#include <cstdio>
#include <cstdlib>
#include <cmath>
#define min(a,b) (a<b?a:b)
int T, K, C, S;

int main(){
    scanf("%d", &T);
    for(int t=1;t<=T;t++){
        printf("Case #%d:", t);
        scanf("%d%d%d", &K, &C, &S);

        int round = ceil((double)K/C);
        if(round>S){
            printf(" IMPOSSIBLE\n");
            continue;
        }

        int s = 0;
        for(int r=0;r<round;r++){
            long long x = 0;
            for(int i=s;i<s+C;i++){
                x *= K;
                if(i<K) x+=i;
            }
            printf(" %lld", x+1);
            s += C;
        }
        printf("\n");
    }
    return 0;
}
