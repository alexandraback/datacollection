#include <stdio.h>

#define MAX 1000001

int ans[MAX];

void work(long long v, bool appear[]){
    while (v > 0){
        appear[v % 10] = true;
        v /= 10;
    }
}

void init(){
    for (int i = 1; i < MAX; i++){
        bool appear[10] = {};
        int cnt = 0;
        for (int j = 1; ; j++){
            long long v = (long long)i * j;
            bool tmp[10] = {};
            work(v, tmp);
            for (int k = 0; k < 10; k++)
                if (!appear[k] && tmp[k]){
                    cnt++;
                    appear[k] = true;
                }
            if (cnt == 10){
                ans[i] = j;
                break;
            }
        }
    }    
}

int main()
{
    init();
    int cases;
    scanf("%d", &cases);
    for (int t = 1; t <= cases; t++){
        int n;
        scanf("%d", &n);
        printf("Case #%d: ", t);
        if (n == 0)
            printf("INSOMNIA\n");
        else
            printf("%lld\n", (long long)n * ans[n]);
    }
}
