#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

vector<ll> v;

inline bool isPalindromic(ll n) {
    vector<int> v;
    for (; n > 0; v.push_back(n % 10), n /= 10);
    for (int i = 0, j = (int)v.size() - 1; i < j; ++i, --j) {
        if (v[i] != v[j]) {
            return false;
        }
    }
    return true;
}

ll gao(ll n) {
    return upper_bound(v.begin(), v.end(), n) - v.begin();
}

int main() {
    for (ll i = 1; i <= 10000000; ++i) {
        if (isPalindromic(i) && isPalindromic(i * i)) {
            v.push_back(i * i);
        }
    }
    int T;
    scanf("%d", &T);
    for (int caseNum = 1; caseNum <= T; ++caseNum) {
        ll A, B;
        scanf("%lld%lld", &A, &B);
        printf("Case #%d: %lld\n", caseNum, gao(B) - gao(A - 1));
    }
    return 0;
}
