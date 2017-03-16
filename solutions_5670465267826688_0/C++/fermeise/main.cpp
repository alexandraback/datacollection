
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
#pragma warning(disable: 4996)

const char* vis[] = {"x", "1", "i", "j", "k"};

int mul(int a, int b) {
    const int table[5][5] = {
        0, 0, 0, 0, 0,
        0, 1, 2, 3, 4,
        0, 2,-1, 4,-3,
        0, 3,-4,-1, 2,
        0, 4, 3,-2,-1
    };

    if(a < 0) {
        if(b < 0) {
            return table[-a][-b];
        } else {
            return -table[-a][b];
        }
    } else {
        if(b < 0) {
            return -table[a][-b];
        } else {
            return table[a][b];
        }
    }
}

bool f(long long l, long long x, const std::string& line) {
    int val = 1;
    for(int a = 0; a < std::min(l * 4, l * x); a++) {
        if(val == 2) {
            val = 1;
            for(int b = a; b < std::min(l * 8, l * x); b++) {
                if(val == 3) {
                    val = 1;
                    for(int c = b; c < std::min(l * (8 + (x % 4)), l * x); c++) {
                        val = mul(val, line[c % l] - 'g');
                    }
                    return val == 4;
                }
                val = mul(val, line[b % l] - 'g');
            }
            return false;
        }
        val = mul(val, line[a % l] - 'g');
    }

    return false;
}

int main() {
    std::string line;

    int numTestCases = 0;
    std::cin >> numTestCases;
    std::getline(std::cin, line);

    for(int testCase = 0; testCase < numTestCases; testCase++) {
        long long l, x;
        std::cin >> l;
        std::cin >> x;
        std::getline(std::cin, line);

        std::getline(std::cin, line);

        std::cout << "Case #" << (testCase + 1) << ": " << (f(l, x, line) ? "YES" : "NO") << std::endl;
    }
}
