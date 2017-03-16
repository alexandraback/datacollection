#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

char str[1000010];
int acc[1000010];
int alphabet[256] = {0};

int main()
{
    int T = 0, N = 0;
    int cas = 0, res = 0, len = 0;

    alphabet['a'] = 1;
    alphabet['e'] = 1;
    alphabet['i'] = 1;
    alphabet['o'] = 1;
    alphabet['u'] = 1;

    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++){
        scanf("%s %d", str, &N);

        memset(acc, 0, sizeof(acc));

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

        for (int i = 0; i<len - N + 1; i++){
            for (int j = i; j < len; j++){
                if (j - i + 1 >= N && acc[j] >= N){
                    res += len - j;
                    break;
                }
            }
        }

        printf("Case #%d: %d\n", cas, res);
    }
    return 0;
}

