#include <cstdio>
#include <cstdlib>
#include <vector>

std::vector<int> check(int l, long long mask)
{
    std::vector<int> result;
    for (int b = 2; b <= 10; ++ b) {
        long long n = 0;
        for (int i = l - 1; i >= 0; -- i) {
            n = n * b + (mask >> i & 1);
        }
        int t = 0;
        for (int p : {2, 3, 5, 7}) {
            if (p < n && n % p == 0) {
                t = p;
                break;
            }
        }
        if (t) {
            result.push_back(t);
        } else {
            return {};
        }
    }
    return result;
}

int main(int argc, char* argv[])
{
    int n = std::atoi(argv[1]);
    int j = std::atoi(argv[2]);
    puts("Case #1:");
    for (long long mask = (1LL << n - 1) | 1; mask < (1LL << n) && j; mask += 2) {
        auto&& result = check(n, mask);
        if (!result.empty()) {
            j --;
            for (int i = n - 1; i >= 0; -- i) {
                printf("%d", (int)(mask >> i & 1));
            }
            for (int i : result) {
                printf(" %d", i);
            }
            puts("");
        }
    }
    return 0;
}
