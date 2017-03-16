#include <iostream>
#include <cstdio>

using namespace std;

int main () {
        int t, a, b, k = 0;
        scanf("%d", &t);
        int ll[] = {1, 4, 9, 121,484};

        while (t--) {
            k++;
            cin >> a >> b;
            int count = 0;
            for (int i = 0; i <= 4; i++) {
                if (ll[i] >= a) {
                    while (ll[i] <= b && i <= 4) {
                        i++;
                        count++;
                    }
                }
            }

        printf("Case #%d: %d\n",k,count);
        }

        return 0;
}

