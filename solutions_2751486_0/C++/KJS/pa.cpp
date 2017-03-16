#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int L = 1000000;

long long int pre[L +1];
long long int suf[L +1];
long long int sum;

char str[L +1];
int main()
{   freopen("A-small-attempt0.in", "r", stdin);
    freopen("pa.out", "w", stdout);
    int T;
    scanf("%d", &T);

    int n;
    for (int t = 1; t <= T; ++t) {
        scanf("%s %d", str, &n);

        int len = strlen(str);

        int index = -1;
        long long int sum = 0;

        pre[0] = 0;
        for (int i = 0; i < len; ++i) {
            if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
                pre[i +1] = 0;
            else
                pre[i +1] = pre[i] +1;

            if (pre[i +1] >= n) {
                index = i - n +1;
            }
            sum += index +1;
        }

        printf("Case #%d: %lld\n", t, sum);
    }
    return 0;
}
