#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

template<class T>
inline T read() {
    T value;
    std::cin >> value;
    return value;
}

int main() {
    int T = read<int>();
    for (int caseNum = 1; caseNum <= T; ++caseNum) {
        // TODO: other stuff
        std::string S = read<std::string>();
        std::string R;
        for (char c : S) {
            std::string R1 = R;
            R1.insert(R1.begin(), c);
            std::string R2 = R;
            R2.push_back(c);
            if (R1 > R2) {
                R = R1;
            } else {
                R = R2;
            }
        }
        printf("Case #%d: %s\n", caseNum, R.c_str());
    }
    return 0;
}
