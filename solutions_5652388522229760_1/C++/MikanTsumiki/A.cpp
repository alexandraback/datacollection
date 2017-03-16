#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int main() {
    int cas;
    scanf("%d", &cas);
    for (int _ = 1; _ <= cas; _++) {
        int n;
        printf("Case #%d: ", _);
        scanf("%d", &n);
        if (n == 0) {
            puts("INSOMNIA");
        } else {
            bool show[10];
            int cnt = 0;
            fill(show, show + 10, 0);
            for (int i = 1;; i++) {
                int _n = i * n;
                while (_n) {
                    int dig = _n % 10;
                    if (!show[dig]) cnt++, show[dig] = 1;
                    _n /= 10;
                }
                if (cnt == 10) {
                    printf("%d\n", i * n);
                    break;
                }
            }
        }
    }
}
