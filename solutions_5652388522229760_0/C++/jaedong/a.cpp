#include <bits/stdc++.h>
using namespace std;

int result(int i) {
    bool seen[10] = {false, false, false, false, false, false, false, false, false, false};
    for (int j = 1; j < 1000; j++) {
        int n = i * j;
        while (n) {
            seen[n % 10] = true;
            n /= 10;
        }
        bool ok = true;
        for (int k = 0; k < 10; k++) {
            if (!seen[k])
                ok = false;
        }
        if (ok)
            return j;
    }
    printf("%d\n", i);
    assert(0);
    return 0;
}

int main() {
    int cases;
    scanf("%d", &cases);
    for (int cs = 1; cs <= cases; cs++) {
        int i;
        scanf("%d", &i);
        if (i == 0)
            printf("Case #%d: INSOMNIA\n", cs);
        else
            printf("Case #%d: %d\n", cs, i * result(i));
    }
}
