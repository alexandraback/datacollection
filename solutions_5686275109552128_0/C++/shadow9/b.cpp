#include<cstdio>
#include<cstring>

int split(int ori, int unit){
    if(ori % unit == 0) return ori/unit - 1;
    return ori/unit;
}

int main(){
    int T, D, cnt = 0;
    int P[1010];
//    int cnt[1010];
    scanf("%d", &T);
    while(T--){
//        memset(cnt, 0, sizeof(cnt));
        scanf("%d", &D);
        int maxP = 0;
        for(int i = 0; i < D; i++){
            scanf("%d", &P[i]);
//            cnt[P[i]]++;
            if(maxP < P[i]) maxP = P[i];
        }
        int ans = 10000000;
        for(int i = maxP; i > 0; i--){
            int penalty = i;
            for(int j = 0; j < D; j++){
                penalty += split(P[j], i);
            }
            if(penalty < ans) ans = penalty;
        }
        printf("Case #%d: %d\n", ++cnt, ans);
    }
    return 0;
}
