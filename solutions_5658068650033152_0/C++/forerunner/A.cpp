#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
    int T, n, m, k, Case = 1;
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    scanf("%d", &T);
    while(T--){
        scanf("%d%d%d", &n, &m, &k);//printf("%d %d %d\n", n, m, k);
        int ans = ~0U>>1;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(i*j-4 >= k)
                ans = min(ans, 2*(i+j)-4);
                else if(i*j-3 >= k)
                ans = min(ans, 2*(i+j)-3);
                else if(i*j-2 >= k)
                ans = min(ans, 2*(i+j)-2);
                else if(i*j-1 >= k)
                ans = min(ans, 2*(i+j)-1);
                else if(i*j >= k)
                ans = min(ans, 2*(i+j));
            }
        }
        //if(ans == (~0U>>1)) printf("Case #%d: %d\n", Case++, n*m-k+);
        printf("Case #%d: %d\n", Case++, ans);
    }
    return 0;
}

