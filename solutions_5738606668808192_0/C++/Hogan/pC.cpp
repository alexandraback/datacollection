#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);

    for (int times = 0; times < T; times++) {
        int n, m;
        scanf("%d%d", &n, &m);

        vector<vector<__int128_t>> vct(10+1, vector<__int128_t>(n, 0));
        for (int j = 2; j <= 10; j++) {
            vct[j][0] = 1;
            for (int k = 1; k < n; k++) {
                vct[j][k] = vct[j][k-1] * j;
            }
        }

        printf("Case #%d:\n", times+1);
        
        char out[35] = {0};
        for (long long i = (1LL<<(n-1))+1; i < (1LL<<n) and m; i+=2) {
            long long cur = i;
            for (int k = 0; k < n; k++) { // store reversely
                out[n-1-k] = cur % 2 + '0';
                cur /= 2;
            }
            
            vector<int> res;
            for (int j = 2; j <= 10; j++) {
                __int128_t v = 0;
                for (int k = 0; k < n; k++) {
                    if (out[n-1-k] == '1') {
                        v += vct[j][k];
                    }
                }

                if (n >= 13) {
                    for (__int128_t k = 2; k <= 100; k++) { // efficient cut
                        if (v % k == 0) {
                            res.emplace_back(k);
                            break;
                        }
                    }
                } else {
                    for (__int128_t k = 2; k <= sqrt(v); k++) {
                        if (v % k == 0) {
                            res.emplace_back(k);
                            break;
                        }
                    }
                }
            }
            
            if (int(res.size()) == 9) {
                printf("%s", out);
                for (auto &v : res) {
                    printf(" %d", v);
                }
                puts("");
                m--;
            }
        }
        fprintf(stderr, "%d\n", m);
    }
}
