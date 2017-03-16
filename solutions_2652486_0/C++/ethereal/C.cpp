#include <iostream>
#include <vector>
#include <algorithm>
#include <stdint.h>

std::vector<std::vector<int> > possibles;
std::vector<std::vector<int> > digits;

std::vector<int> current;

void find_most_likely() {
    uint64_t m = -1;
    for(int i = 0; i < current.size(); i ++) {
        int v = current[i];
        for(int j = 0; j < possibles.size(); j ++) {
            bool found = false;
            for(int k = 0; k < possibles[j].size(); k ++) {
                if(possibles[j][k] == v) {found = true; break;}
            }

            if(!found) m &= ~(1ULL<<j);
        }
    }

    if(m == 0) std::cout << "222" << std::endl;
    else {
        for(int i = 0; i < 64; i ++) {
            if(m & (1ULL << i)) {
                for(int j = 0; j < digits[i].size(); j ++) {
                    std::cout << digits[i][j];
                }
                std::cout << std::endl;
                return;
            }
        }
    }
}

int main() {
    for(int a = 2; a <= 5; a ++) {
        for(int b = a; b <= 5; b ++) {
            for(int c = b; c <= 5; c ++) {
                possibles.push_back(std::vector<int>());
                digits.push_back(std::vector<int>());
                digits.back().push_back(a);
                digits.back().push_back(b);
                digits.back().push_back(c);

                for(int i = 0; i < 8; i ++) {
                    int p = 1;
                    if(i & 1) p *= a;
                    if(i & 2) p *= b;
                    if(i & 4) p *= c;

                    possibles.back().push_back(p);
                }
                std::sort(possibles.back().begin(), possibles.back().end());
            }
        }
    }
    
    int T;
    std::cin >> T;

    int R, N, M, K;
    std::cin >> R >> N >> M >> K;

    current.assign(N, 0);
    std::cout << "Case #1:" << std::endl;
    for(int i = 0; i < R; i ++) {
        for(int j = 0; j < K; j ++) std::cin >> current[j];

        find_most_likely();
    }

    return 0;
}
