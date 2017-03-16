#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cassert>

const int INF = 1e9 + 7;
const int MX = 256;

int T[MX];
std::string S;

std::vector<std::pair<int, char>> vec = {
    {0, 'Z'},
    {6, 'X'},
    {8, 'G'},
    {4, 'U'},
    {5, 'F'},
    {7, 'V'},
    {3, 'R'},
    {2, 'W'},
    {9, 'I'},
    {1, 'O'}
};

std::string numb[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

int act[MX];

std::string solve() {
    std::string res;
    for (int i = 'A'; i <= 'Z'; ++ i)
        T[i] = 0;

    std::cin >> S;

    for (const auto &it : S) 
        ++T[(int)it];
    
    for (const auto &it : vec) {
        int cnt = T[it.second];
        /* std::cerr << "cnt : " << cnt << "\n" << std::flush; */

        for (int i = 0; i < cnt; ++ i) 
            res += it.first + '0';

        for (const auto &ptr : numb[it.first]) {
            T[ptr] -= cnt;
        }
    }

    /* for (int i = 'A'; i <= 'Z'; ++ i) { */
    /*     /1* std::cerr << (char)i << " = " << T[i] << "\n" << std::flush; *1/ */
    /*     assert(T[i] == 0); */
    /* } */

    std::sort(res.begin(), res.end());

    return res;
}


int main() {
    int test;
    std::cin >> test;
    
    for (int i = 1; i <= test; ++ i)
        std::cout << "Case #" << i << ": " << solve() << "\n";

    return 0;
}
