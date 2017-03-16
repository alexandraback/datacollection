#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

char str[1000010];
int acc[1000010];
int alphabet[256] = {0};
int sum[1000010];

int getv(int start, int end){
    if (start < 0)
        return sum[end];
    else
        return sum[end] - sum[start];
}
int main()
{
    int T = 0, N = 0;
    int cas = 0, len = 0;
    long long res = 0;

    alphabet['a'] = 1;
    alphabet['e'] = 1;
    alphabet['i'] = 1;
    alphabet['o'] = 1;
    alphabet['u'] = 1;

    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++){
        scanf("%s %d", str, &N);

        memset(acc, 0, sizeof(acc));
        memset(sum, 0, sizeof(sum));

        len = strlen(str);
        res = 0;

        if (alphabet[str[0]] == 0){
            acc[0] = 1;
        }else{
            acc[0] = 0;
        }

        for (int i = 1; i<len; i++){
            if (alphabet[str[i]] == 0){
                acc[i] = acc[i-1] + 1;
            }else{
                acc[i] = 0;
            }
        }

        if (N == 1){
            sum[0] = acc[0];
        }else{
            sum[0] = 0;
        }

        for (int i = 1; i<len; i++){
            if (acc[i] >= N){
                sum[i] = sum[i-1] + 1;
            }else{
                sum[i] = sum[i-1];
            }
        }

        for (int i = 0; i<len - N + 1; i++){
            int upper = len - 1;
            int lower = i + N - 1;
            int mid = 0;
            while (lower < upper){
                mid = (upper + lower) / 2;
                int num = getv(i+N-2, mid);
                if (num <= 0){
                    lower = mid + 1;
                }else{
                    upper = mid;
                }
            }

             mid = (upper + lower) / 2;
            if (getv(i + N - 2, mid) > 0){
                res += len - mid;
            }
        }

        printf("Case #%d: %I64d\n", cas, res);
    }
    return 0;
}

