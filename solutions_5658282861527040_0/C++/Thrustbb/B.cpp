#include <bits/stdc++.h>
using namespace std;

int T;

int main() {
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        int a, b, k;
        scanf("%d%d%d", &a, &b, &k);
        int res = 0;
        for (int i = 0; i < a; i++)
            for (int j = 0; j < b; j++)
                if ((i&j) < k)
                    res++;
        printf("Case #%d: %d\n", t, res); 
    }
    return 0;
}
