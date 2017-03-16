#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int rev(int p){
    int ret = 0;
    while(p){
        ret = ret*10 + p%10;
        p/=10;
    }
    return ret;
}

int dis[1000001] = {0};
int que[1000001];
int main(){
    dis[1] = 1;
    int qs = 0, qe = 0;
    que[qe++] = 1;
    while(qe > qs){
        int prc = que[qs++];
        if(prc+1 <= 1000000 and dis[prc+1] == 0){
            dis[prc+1] = dis[prc] + 1;
            que[qe++] = prc+1;
        }
        int revprc = rev(prc);
        if(dis[revprc] == 0){
            dis[revprc] = dis[prc]+1;
            que[qe++] = revprc;
        }
    }
    int T; scanf("%d", &T);
    for(int lt = 1;lt <= T;lt++){
        int inp; scanf("%d", &inp);
        printf("Case #%d: %d\n", lt, dis[inp]);
    }
    return 0;
}
