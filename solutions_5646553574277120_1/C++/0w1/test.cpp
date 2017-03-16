#include <cstdio>
#include <queue>
#include <functional>
#include <vector>
typedef long long LL;
LL ans;
std::priority_queue<LL, std::vector<LL>, std::greater<LL> > pq;
int main(){
    int T;
    scanf("%d", &T);
    for(int kase = 1; kase <= T; ++kase){
        while(!pq.empty()) pq.pop();
        LL range = 0;
        ans = 0;
        LL C, D, V;
        scanf("%lld %lld %lld", &C, &D, &V);
        while(D--){
            LL val;
            scanf("%lld", &val);
            pq.push(val);
        }
        while(range < V){
            if(!pq.empty() && pq.top() <= range+1){
                range += pq.top() * C;
                pq.pop();
            }else{
                ++ans;
                pq.push(range+1);
            }
        }
        printf("Case #%d: %lld\n", kase, ans);
    }
    return 0;
}