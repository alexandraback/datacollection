#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <utility>

typedef long long Long;

char match(char p, int d)
{
    if (p == '?') {
        return true;
    }
    return p - '0' == d;
}

std::string fill(std::string s, char d)
{
    for (auto& c : s) {
        if (c == '?') {
            c = d;
        }
    }
    return s;
}

std::string format(Long n, int l)
{
    auto s = std::to_string(n);
    while (s.size() < l) {
        s = "0" + s;
    }
    return s;
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++ t) {
        std::string a, b;
        std::cin >> a >> b;
        int n = a.size();
        std::pair<Long, std::pair<Long, Long>> result{1e18, {0, 0}};
        bool gg = false;
        for (int i = 0; i < n; ++ i) {
            for (int x = 0; x < 10; ++ x) {
                for (int y = 0; y < 10; ++ y) {
                    if (x != y && match(a[i], x) && match(b[i], y)) {
                        std::string aa = a;
                        aa[i] = '0' + x;
                        std::string bb = b;
                        bb[i] = '0' + y;
                        if (x > y) {
                            aa = fill(aa, '0');
                            bb = fill(bb, '9');
                        } else {
                            aa = fill(aa, '9');
                            bb = fill(bb, '0');
                        }
                        auto na = std::stoll(aa);
                        auto nb = std::stoll(bb);
                        result = std::min(result, {std::abs(na - nb), {na, nb}});
                    }
                }
            }
            char d = '0';
            if (a[i] != '?') {
                d = a[i];
            }
            if (b[i] != '?') {
                if (a[i] != '?' && a[i] != b[i]) {
                    gg = true;
                    break;
                }
                d = b[i];
            }
            a[i] = b[i] = d;
        }
        if (!gg) {
            auto na = std::stoll(a);
            auto nb = std::stoll(b);
            result = std::min(result, {std::abs(na - nb), {na, nb}});
        }
        std::cout << "Case #" << t << ": " << format(result.second.first, n) << " " << format(result.second.second, n) << std::endl;
    }
}
