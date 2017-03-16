#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

template<class T>
inline T read() {
    T value;
    std::cin >> value;
    return value;
}

struct result_t {
    int j, p, s;
    result_t(int j, int p, int s)
      : j(j), p(p), s(s)
    { }
};

int main() {
    int T = read<int>();
    for (int caseNum = 1; caseNum <= T; ++caseNum) {
        int J = read<int>();
        int P = read<int>();
        int S = read<int>();
        int K = read<int>();
        std::vector<int> seen_jp(J * P, 0);
        std::vector<int> seen_js(J * S, 0);
        std::vector<int> seen_ps(P * S, 0);
        std::vector<result_t> results;
        for (int s = S-1; s >= 0; --s) {
            for (int p = P-1; p >= 0; --p) {
                for (int j = J-1; j >= 0; --j) {
                    auto jp = j * P + p;
                    auto js = j * S + s;
                    auto ps = p * S + s;
                    if (seen_jp[jp] == K)
                        continue;
                    if (seen_js[js] == K)
                        continue;
                    if (seen_ps[ps] == K)
                        continue;
                    seen_jp.at(jp) += 1;
                    seen_js.at(js) += 1;
                    seen_ps.at(ps) += 1;
                    results.push_back(result_t(j + 1, p + 1, s + 1));
                }
            }
        }
        //std::reverse(results.begin(), results.end());
        printf("Case #%d: %lu\n", caseNum, results.size());
        for (result_t r : results) {
            printf("%d %d %d\n", r.j, r.p, r.s);
        }
    }
    return 0;
}
