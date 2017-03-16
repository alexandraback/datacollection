#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int T, N, L;
char str[120];

int check(int s, int e) {
    int cnt = 0, ret = 0;
    for (int i = s; i <= e; i++) {
        if (str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u') {
            cnt++;
        } else {
            ret = max(ret, cnt);
            cnt = 0;
        }
    }
    ret = max(ret, cnt);
    return ret;
}


int main()
{
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        scanf("%s %d", str, &N);
        int len = strlen(str), ret = 0;
        for (int i = 0; i < len; i++) {
            for (int j = i; j< len; j++) {
                if (check(i, j) >= N) {
                    ret++;
                }
            }
        }
        printf("Case #%d: %d\n", cas, ret);
    }

    return 0;
}
