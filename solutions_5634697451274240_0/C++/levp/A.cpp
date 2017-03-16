#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int solve(std::string s) {
    int ans = 0;
    s += '+';
    for (int i = 0; i < s.length() - 1; ++i) {
        if (s[i + 1] != s[i]) {
            ++ans;
        }
    }
    return ans;
}

int main(){
    int t;
    std::cin >> t;
    for (int i = 0; i < t; ++i) {
        std::string s;
        std::cin >> s;
        std::cout << "Case #" << i + 1 << ": " << solve(s) << std::endl;
    }
    
}
