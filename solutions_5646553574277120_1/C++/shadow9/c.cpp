#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
    int T, cnt = 0;
    int C, D, V;
    long long c[110];
    scanf("%d", &T);
    while(T--){
        int ans = 0;
        scanf("%d%d%d", &C, &D, &V);
        long long res = 0;
        c[0] = 1;
        for(int i = 1; i <= D; i++){
            scanf("%lld", &c[i]);
        }
        int idx = 1;
        if(c[1] != 1) ans++, idx = 0;
        c[D+1] = 1000000000000000LL;
        sort(c, c+D+1);
        while(res < V){
//            printf("res = %lld < %d\n", res, V);
            while(c[idx] > res+1 && res < V){
                ans++;
                //printf("add %d\n", res+1);
                res += (res+1)*C;
            }
            res += c[idx]*C;
            idx++;
            //printf("res = %lld\n", res);
        }
        printf("Case #%d: %d\n", ++cnt, ans);
    }
    return 0;
}
