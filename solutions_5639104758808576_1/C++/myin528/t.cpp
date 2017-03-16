#include <iostream>
using namespace std;

int main() {
    string s;
    int T;
    scanf("%d", &T);
    for (int test = 0; test < T; test++) {
        int smax;
        char s[1005];
        scanf("%d %s", &smax, s);

        int needed = 0;
        int sum = 0;
        for (int i = 0; i <= smax; i++) {
            if (s[i] == '0') {
                continue;
            }
            if (sum < i) {
                needed += i - sum;
                sum = i;
            }
            sum += s[i] - '0';
        }
        printf("Case #%d: %d\n", test + 1, needed);
    }
    return 0;
}