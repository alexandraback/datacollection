// Compile with TDM-GCC-64 5.1 with c++11 features

#include <stdint.h>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <queue>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
    int N;
    std::cin >> N;
    std::string str;
    std::getline(std::cin, str);

    for (int case_no = 1; case_no <= N; ++case_no) {
        std::cout << "Case #" << case_no << ": ";

        std::string given_word;
        std::getline(std::cin, given_word);

        std::string last_word, word1, word2;
        for (char chr : given_word) {
            word1 = last_word + chr;
            word2 = chr + last_word;
            last_word = max(word1, word2);
        }

        cout << last_word << '\n';
    }

    return 0;
}

