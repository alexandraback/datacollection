#include <iostream>
#include <vector>

int best(int total, bool surprising) {
    if (!surprising) {
        return (total + 2) / 3;
    } else {
        if (total == 0) return 0;
        if (total >= 29) return 10;
        return (total + 4) / 3;
    }
}

int main() {
    int T;
    std::cin >> T;
    for (int x = 1; x <= T; ++x) {
        int N, S, p;
        std::cin >> N >> S >> p;
        std::vector<int> v;
        for (int i = 0; i < N; ++i) {
            int t;
            std::cin >> t;
            v.push_back(t);
        }
        int y = 0;
        for (std::vector<int>::iterator i = v.begin(); i != v.end(); ++i) {
            if (best(*i, false) >= p) {
                ++y;
            } else if (best(*i, true) >= p && S > 0) {
                ++y;
                --S;
            }
        }
        std::cout << "Case #" << x << ": " << y << '\n';
    }
    return 0;
}
