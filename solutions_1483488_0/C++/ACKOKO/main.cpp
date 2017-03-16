#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;


int tt[8] = {1, 10, 100, 1000, 10000, 100000, 1000000, 1000000};
int len, ans, N, A, B, t, cur, num;
int flag[2000010];

int main()
{
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small.out", "w", stdout);
    scanf("%d", &N);
    for(int T = 1;T <= N;T++){
        scanf("%d %d", &A, &B);
        ans = 0;
        for(int i = A;i <= B;i++){
            if(flag[i] == T){
                continue;
            }
            len = 0;
            num = 1;
            flag[i] = T;
            t = i;
            while(t){
                t /= 10;
                len++;
            }
            cur = i;
            for(int j = 2;j <= len;j++){
                if((cur/tt[len-j]) % 10 != 0){
                    t = cur%tt[len-j+1]*tt[j-1] + cur/tt[len-j+1];
                    if(t >= A&&t <= B&&flag[t]!=T){
                        flag[t] = T;
                        num++;
                    }
                }
            }
            ans += num*(num-1)/2;
        }
        printf("Case #%d: %d\n",T, ans);
    }
    return 0;
}
