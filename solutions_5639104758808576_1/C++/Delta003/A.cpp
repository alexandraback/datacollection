#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1e3 + 5;

int n, cases;
char stringCount[maxn];

int toInt(char x) {
    return x - '0';
}

int main() {
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);

    scanf("%d", &cases);
    int counter = 0;
    while (cases--) {
        counter++;

        scanf("%d %s", &n, &stringCount);

        int sol = 0, current = 0;
        for (int i = 0; i <= n; i++) {
            if (toInt(stringCount[i]) == 0) continue;
            if (current < i) {
                sol += i - current;
                current = i;
            }
            current += toInt(stringCount[i]);
        }

        printf("Case #%d: %d\n", counter, sol);
    }

    return 0;
}
