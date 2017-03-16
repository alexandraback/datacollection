#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int main() {
    int cas;
    scanf("%d", &cas);
    for (int _ = 1; _ <= cas; _++) {
        int n;
        char s[200];
        printf("Case #%d: ", _);
        scanf("%s", s);
        n = strlen(s);
        int cnt = 0;
        for (int i = n - 1; i >= 0; i--)
            if (s[i] == '-') {
                for (int j = 0; j < i; j++) s[j] = (s[j] == '+' ? '-' : '+');
                cnt++;
            }
        printf("%d\n", cnt);
    }
}
