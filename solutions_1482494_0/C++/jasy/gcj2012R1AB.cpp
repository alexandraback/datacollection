#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

static std::string solve ()
{
    int N;
    std::cin >> N;
    std::vector<bool> u(N,false);
    std::vector<std::pair<int, int> > ai(N);
    std::vector<std::pair<int, int> > bi(N);
    for (int i=0; i<N; ++i) {
        int a,b;
        std::cin >> a >> b;
        ai[i].first = a;
        ai[i].second = i;
        bi[i].first = b;
        bi[i].second = i;
    }
    std::sort(ai.begin(), ai.end());
    std::sort(bi.begin(), bi.end());
    int s = 0;
    int n = 0;
    int an = 0;
    for (int i=0; i<N; ++i) {
        const int x = bi[i].first;
        while (s<x) {
            if (N<=an || s < ai[an].first) {
                return "Too Bad";
            }
            const int p = ai[an].second;
            if (!u[p]) {
                u[p] = true;
                ++s;
                ++n;
            }
            ++an;
        }
        int p = bi[i].second;
        s += u[p]? 1: 2;
        ++n;
        u[p] = true;
    }
    std::stringstream ss;
    ss << n;
    return ss.str();
}

int main ()
{
    int T;
    std::cin >> T;
    for (int i=1; i<=T; ++i) {
        std::cout << "Case #" << i << ": " << solve() << "\n";
    }
    return 0;
}
