#include <algorithm>
#include <iostream>
#include <cstdint>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
using namespace std;

uint64_t rev(uint64_t n)
{
    stringstream ss;
    ss << n;
    string str = ss.str();
    reverse(str.begin(), str.end());
    stringstream ss2;
    ss2 << str;
    ss2 >> n;
    return n;
}

int main(int argc, char **argv)
{
    ios_base::sync_with_stdio(false);
    auto& in = std::cin;
//     std::ifstream in("../t1.txt");

    int T;
    in >> T;

    for (int t = 1; t <= T; ++t)
    {
        int N;
        in >> N;
        vector<uint64_t> dp(N + 1, 1);

        for (int i = 2; i <= N; ++i)
        {
            dp[i] = dp[i - 1] + 1;
            auto r = rev(i);
            if ((i % 10) != 0 && r < i)
                dp[i] = std::min(dp[i], dp[r] + 1);
        }

        std::cout << "Case #" << t << ": " << dp[N] << '\n';
    }

    return 0;
}
