#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char *argv[]) {
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);
    size_t t = 0;
    scanf("%zd", &t);
    for (size_t i = 0; i < t; ++i) {
        char s[101] = "";
        scanf("%s", s);
        size_t len = strlen(s);
        size_t times = 0;
        for (; len; --len) {
            if (s[len - 1] == '-') {
                ++times;
                for (size_t j = 0; j < len / 2; ++j) {
                    size_t a = j;
                    size_t b = len / 2 - a - 1;
                    swap(s[a], s[b]);
                }
                for (size_t j = 0; j < len; ++j) {
                    s[j] = s[j] == '-' ? '+' : '-';
                }
            }
        }
        printf("Case #%zd: %zd\n", i + 1, times);
    }
    return EXIT_SUCCESS;
}
