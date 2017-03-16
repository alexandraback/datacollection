#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int T;
char str[1010];

int main() {

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        scanf("%s", str);
        int n = strlen(str);
        char c = 'A' - 1;
        vector <bool> v(n, false);
        printf("Case #%d: ", t);
        for (int i = 0; i < n; i++) {
            if (str[i] >= c) {
                c = str[i];
                v[i] = true;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (v[i]) {
                printf("%c", str[i]);
            }
        }
        for (int i = 0; i < n; i++) {
            if (!v[i]) {
                printf("%c", str[i]);
            }
        }
        puts("");
    }

    return 0;

}
