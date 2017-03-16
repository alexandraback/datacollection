#include "../codejam-dsl.hpp"

bool pali(int x) {
    ostringstream oss;
    oss << x;
    string s = oss.str();
    for (int i = 0, N = s.size()/2; i < N; ++i) {
        if (s[i] != s[s.size() - i - 1]) return false;
    }
    return true;
}

bool good(int x) {
    int r = (int) sqrt(x);
    if (r*r != x) return false;
    return pali(x) && pali(r);
}

void run()
{
    int A = rdi(), B = rdi(), ans = 0;
    for (int i = A; i <= B; ++i) {
        if (good(i)) ++ans;
    }
    cout << ans;
}
