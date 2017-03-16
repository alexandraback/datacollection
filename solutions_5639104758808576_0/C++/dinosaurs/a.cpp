#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int T, Smax;
char inp[1111];

int main() {
    scanf("%d", &T);

    for (int t = 1; t <= T; ++t) {
        scanf("%d %s", &Smax, inp);
        int answer = 0, cur = 0;
        for (int j = 0; j <= Smax; ++j) {
            while (cur < j) {
                answer++;
                cur++;
            }
            cur += (inp[j] - '0');
        }
        printf("Case #%d: %d\n", t, answer);
    }

    return 0;
}
