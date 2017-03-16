#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int cases;
    char shyness[1024];
    scanf("%d", &cases);
    for (int cs = 1; cs <= cases; cs++) {
        int smax;
        int ans = 0, sum = 0;
        scanf("%d", &smax);
        scanf("%s", shyness);
        for (int i = 0; i <= smax; i++) {
            if (sum < i) {
                ans += i - sum;
                sum = i;
            }
            sum += shyness[i] - '0';
        }
        printf("Case #%d: %d\n", cs, ans);
    }
}
