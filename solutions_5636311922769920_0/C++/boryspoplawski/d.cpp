#include <iostream>
#include <vector>


void calc(std::vector<long long int>& v, long long int K, int C) {
    std::vector<long long int> powers;
    int i, j;
    long long int p;
    int ma;
    
    ma = (K>C)?C:K;
    
    p = 1;
    for (i = 0; i < ma; ++i) {
        powers.push_back(p);
        p *= K;
    }
    
    j = 0;
    while (j < K) {
        p = 0;
        for (i = 0; i < ma; ++i) {
            p += j * powers[i];
            ++j;
            if (j >= K) {
                break;
            }
        }
        v.push_back(p);
    }
}

int main() {
    int T, K, C, S, i, j;
    std::vector<long long int> v;
    
    std::cin >> T;
    for (i = 1; i <= T; ++i) {
        v.resize(0);
        std::cin >> K >> C >> S;
        std::cout << "Case #" << i << ":";
        if ((K/C) + (K%C > 0) <= S) {
            calc(v, K, C);
            if (v.size() > S) {
                std::cout << " IMPOSSIBLE";
            } else {
                for (j = 0; j < v.size(); ++j) {
                    std::cout << " " << v[j] + 1;
                }
            }
        } else {
            std::cout << " IMPOSSIBLE";
        }
        std::cout << std::endl;
    }
}
