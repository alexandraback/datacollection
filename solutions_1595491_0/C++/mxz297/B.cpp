#include<cstdio>
#include<cstring>
int N,T,S,p, total;
int main(){
    freopen("input.txt" , "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    for (int cases = 1; cases <= T; ++cases){
        scanf("%d%d%d", &N,&S,&p);
        int ans = 0;
        for (int i = 0; i < N; ++i){
            scanf("%d", &total);
            if (3 * p - 2 <= total) ++ans;
            else if (p > 1 && S && 3 * p - 4 <= total){
                 --S;
                 ++ans;
            }
        }
        printf("Case #%d: %d\n", cases, ans);
    }
}
