#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <utility>

typedef long long ll;
typedef std::pair<int, int> pii;

std::string S;

std::string solve() {
    std::string res;
    for(int i = 0; i < S.size(); ++i) {
        if(S[i] >= res[0]) res = S[i] + res;
        else res = res + S[i];
    }
    return res;
}

int main() {
    int CS;
    std::cin >> CS;
    for(int cs = 1; cs <= CS; ++cs) {
        std::cin >> S;

        std::string ans = solve();
        std::cout << "Case #" << cs << ": " << ans << std::endl;
    }

    return 0;
}
