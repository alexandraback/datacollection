#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

long long convertFrom(long long num, long long base) {
    std::string s;
    while (num != 0) {
        s += num % 2 + '0';
        num /= 2;
    }
    long long ans = 0;
    long long temp = 1;
    for (int i = 0; i < s.length(); ++i) {
        ans += temp * (s[i] - '0');
        temp *= base;
    }
    return ans;
}

long long find_divisor(long long num) {
    for (long long i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return i;
        }
    }
    return 0;
}

std::vector<int> solve(long long  s) {
    std::vector<int> ans;
    ans.push_back(s);
    for (int i = 2; i <= 10; ++i) {
        long long t = convertFrom(s, i);
        long long divisor = find_divisor(t);
        if (divisor == 0) {
            ans.clear();
            return ans;
        } else {
            ans.push_back(divisor);
        }
    }
    return ans;
}

int main(){
    const int length = 32, k = 500;
    int t = 0;
    long long cur = 0b1000000000000001;
    std::cout << "Case #1: " << std::endl;
    while (t != k) {
        std::vector<int> ans = solve(cur);
        if (!ans.empty()) {
            std::cout << std::bitset<length>(ans[0]);
            for (int i = 1; i < ans.size(); ++i) {
                std::cout << ' ' << ans[i];
            }
            std::cout << std::endl;
            ++t;
        }
        cur += 2;
    }
}
