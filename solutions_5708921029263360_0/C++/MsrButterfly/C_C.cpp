#include <algorithm>
#include <bitset>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <limits>
#include <list>
#include <numeric>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

size_t j, p, s, k;
size_t jp[10][10], ps[10][10], js[10][10];

struct result {
    result(size_t j, size_t p, size_t s): j(j), p(p), s(s) {}
    size_t j, p, s;
};

int main(int argc, const char *argv[]) {
    freopen("C_C.in", "r", stdin);
    freopen("C_C.out", "w", stdout);
    size_t t = 0;
    scanf("%zd", &t);
    for (size_t i = 1; i <= t; ++i) {
        vector<result> results;
        printf("Case #%zd: ", i);
        scanf("%zd %zd %zd %zd", &j, &p, &s, &k);
        for (size_t a = 0; a < j; ++a) {
            for (size_t b = 0; b < p; ++b) {
                jp[a][b] = k;
            }
        }
        for (size_t a = 0; a < p; ++a) {
            for (size_t b = 0; b < s; ++b) {
                ps[a][b] = k;
            }
        }
        for (size_t a = 0; a < j; ++a) {
            for (size_t b = 0; b < s; ++b) {
                js[a][b] = k;
            }
        }
        for (size_t a = 0; a < j; ++a) {
            for (size_t b = 0; b < p; ++b) {
                for (size_t c = 0; c < s; ++c) {
                    if (jp[a][b] > 0 && ps[b][c] > 0 && js[a][c] > 0) {
                        results.emplace_back(a + 1, b + 1, c + 1);
                        --jp[a][b];
                        --ps[b][c];
                        --js[a][c];
                    }
                }
            }
        }
        printf("%zd\n", results.size());
        for (const auto &r : results) {
            printf("%zd %zd %zd\n", r.j, r.p, r.s);
        }
    }
    size_t result_count;
    return EXIT_SUCCESS;
}