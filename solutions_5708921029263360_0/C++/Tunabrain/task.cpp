#include <iostream>
#include <vector>

void solveTestCase()
{
    int J, P, S, K;
    std::cin >> J >> P >> S >> K;
    
    struct Result { int j, p, s; };
    std::vector<Result> results;
    
    int mapJP[100] = {0};
    int mapJS[100] = {0};
    int mapPS[100] = {0};
    for (int j = 0; j < J; ++j) {
        for (int p = 0; p < P; ++p) {
            for (int s = 0; s < S; ++s) {
                if (mapJP[j*10 + p] < K && mapJS[j*10 + s] < K && mapPS[p*10 + s] < K) {
                    results.emplace_back(Result{j, p, s});
                    mapJP[j*10 + p]++;
                    mapJS[j*10 + s]++;
                    mapPS[p*10 + s]++;
                }
            }
        }
    }
    
    std::cout << results.size() << std::endl;
    for (Result result : results)
        std::cout << result.j + 1 << " " << result.p + 1 << " " << result.s + 1 << std::endl;
}

int main() {
    int t;
    std::cin >> t;

    for (int i = 0; i < t; ++i) {
        std::cout << "Case #" << (i + 1) << ": ";
        solveTestCase();
    }
    return 0;
}
