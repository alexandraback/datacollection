#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <queue>
using std::priority_queue;
typedef long long LL;

int main(){
    int T;
    scanf("%d", &T);
    for(int case_t=1 ; case_t<=T ; case_t++){
        priority_queue<LL> PQ;
        LL C, N, V;
        scanf("%lld %lld %lld", &C, &N, &V);
        while(N--){
            LL v;
            scanf("%lld", &v);
            PQ.push(-v);
        }
        int res = 0;
        LL range = 0;
        while(range < V){
            if(!PQ.empty() && -PQ.top() <= range+1){
                int k = -PQ.top(); PQ.pop();
                range += (LL)C * k;
            }else{
                res++;
                range += (LL)C * (range+1);
            }
        }
        printf("Case #%d: %d\n", case_t, res);
    }
    return 0;
}