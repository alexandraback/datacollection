#include "iostream"
#include "cstring"
#include "cstdio"
#include "algorithm"
using namespace std;
const int N = 1010;
int a[N];
int val[15];
int check(int * v, int num)
{
    for(int i = 0; i < num; ++ i){
        int pre = v[(i - 1 + num) % num];
        int now = v[i];
        int nex = v[(i + 1) % num];
        if (a[now] != pre && a[now] != nex) return false;
    }
    return true;
}
int main(void)
{
    int T;
    scanf("%d", &T);
    int g = 0, n;
    while(T--){
        printf("Case #%d: ", ++g);
        scanf("%d", &n);
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &a[i]);
        }
        int ans = 0;
        for(int i = 0; i < (1 << n); ++ i){
            int num = 0;
            for(int j = 0; j < n; ++ j){
                if (i & (1 << j)) {
                    val[num++] = j + 1;
                }
            }
            if(num <= ans) continue;
            do{
                if (check(val, num)){
                    ans = max(ans, num);
                }
            }while(next_permutation(val, val + num));
        }
        printf("%d\n", ans);
    }
    return 0;
}