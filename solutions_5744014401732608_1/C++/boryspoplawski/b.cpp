#include <iostream>
#include <vector>

int myn(int a, int b) {
    if (a > b) {
        return b;
    }
    return a;
}

int main() {
    int T, Ti, B, i, j;
    long long int M;
    std::vector<long long int> powers;
    std::vector<std::vector<short int> > pat;
    
    powers.push_back(1);
    for (i = 1; i < 52; ++i) {
        powers.push_back(powers[i - 1] * 2);
    }
    std::cin >> T;
    for (Ti = 1; Ti <= T; ++Ti) {
        std::cin >> B;
        std::cin >> M;
        pat.clear();
        pat.resize(B);
        for (i = 0; i < B; ++i) {
            pat[i] = std::vector<short int>();
            pat[i].resize(B, 0);
        }
        for (i = myn(B-3, powers.size() - 1); i >= 0; --i) {
            if (M >= powers[i]) {
                M -= powers[i];
                pat[B-1][i+1] = 1;
            }
        }
        if (M > 0) {
            --M;
            pat[B-1][0] = 1;
        }
        for (i = B - 2; i >= 0; --i) {
            for (j = i - 1; j >= 0; --j) {
                pat[i][j] = 1;
            }
        }
        std::cout << "Case #" << Ti << ": ";
        if (M == 0) {
            std::cout << "POSSIBLE";
            for (i = 0; i < B; ++i) {
                std::cout << std::endl;
                for (j = 0; j < B; ++j) {
                    std::cout << pat[B-1 - i][B-1 - j];
                }
            }
        } else {
            std::cout << "IMPOSSIBLE";
        }
        std::cout << std::endl;
    }
    return 0;
}
