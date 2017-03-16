#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

bool ispalindrome(int64_t n) {
        std::stringstream ss;
        ss << n;
        std::string str = ss.str();
        for (int i = 0, j = str.length() - 1; i < j; ++i, --j)
                if (str[i] != str[j])
                        return false;
        return true;
}

int main() {
        std::vector<int64_t> num;
        for (int64_t i = 1; i < 100; ++i)
                if (ispalindrome(i)) {
                        int64_t t = i * i;
                        if (ispalindrome(t))
                                num.push_back(t);
                }
        printf("num.size = %d\n", num.size());

        std::ifstream fin("C-small-attempt0.in");
        std::ofstream fout("C-small-attempt0.out");
        int T;
        fin >> T;
        for (int casenum = 1; casenum <= T; ++casenum) {
                int64_t a, b;
                fin >> a >> b;
                int low = std::lower_bound(num.begin(), num.end(), a) - num.begin();
                int high = std::upper_bound(num.begin(), num.end(), b) - num.begin();
                fout << "Case #" << casenum << ": ";
                fout << (high - low) << '\n';
        }
        fin.close();
        fout.close();
        system("pause");
        return 0;
}