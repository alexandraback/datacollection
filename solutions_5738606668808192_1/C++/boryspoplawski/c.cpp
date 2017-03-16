#include <iostream>
#include <vector>

// 0 even      1 odd
void genNext(std::vector<bool>& v, int even) {
    int i;
    bool set;
    
    if (v[v.size() - 2 - even] && v[v.size() - 4 - even]) {
        v[v.size() - 2 - even] = false;
        v[v.size() - 4 - even] = false;
        v[2 - even] = true;
        v[4 - even] = true;
        genNext(v, 1 - even);
        return;
    }
    set = false;
    if (v[v.size() - 2 - even]) {
        v[v.size() - 2 - even] = false;
        set = true;
    }
    for (i = v.size() - 2 - even; i > 0; i-=2) {
        if (v[i]) {
            v[i] = false;
            v[i + 2] = true;
            if (set) {
                v[i + 4] = true;
            }
            break;
        }
    }
}

void prepare(std::vector<bool>& v) {
    int i;
    
    for (i = 0; i < v.size(); ++i) {
        v[i] = (i < 5);
    }
    v[v.size() - 1] = true;
}

int main() {
    int T, i, N, J;
    std::vector<bool> v;
    std::vector<bool>::iterator it;
    
    std::cin >> T;
    for (i = 1; i <= T; ++i) {
        std::cin >> N >> J;
        std::cout << "Case #" << i << ":" << std::endl;
        v.resize(N);
        prepare(v);
        while (--J >= 0) {
            genNext(v, 0);
            for (it = v.begin(); it != v.end(); ++it) {
                std::cout << *it;
            }
            std::cout << " 3 2 3 2 7 2 3 2 3" << std::endl;
        }
    }
    return 0;
}
