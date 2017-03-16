#include <cstdlib>
#include <cstdio>
#include <cstring>

int mem[1000001];
int acc[1000001];
char name[1000001];

bool isVowel(char a) {
    return (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u');
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        int n;
        scanf("%s%d", name, &n);
        int len = strlen(name);
        int c = 0;
        for (int i = 0; i < len; ++i) {
            if (isVowel(name[i])) c = 0;
            else c += 1;
            mem[i] = c;
        }
        int firstOk = -1;
        for (int i = len - n; i >= 0; --i) {
            if (mem[i+n-1] >= n) {
                firstOk = i;
            }
            acc[i] = firstOk + n - 1;
        }
        int res = 0;
        for (int i = 0; i < len - n + 1; ++i) {
            if (acc[i] == -1) break;
            if (acc[i] - n + 1 >= i)
                res += len - acc[i];
        }
        printf("Case #%d: %d\n", t, res);
    }
}
