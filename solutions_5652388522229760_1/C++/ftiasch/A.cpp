#include <cstdio>
#include <set>

int solve(int n)
{
    if (!n) {
        return -1;
    }
    std::set<int> digits;
    int current = 0;
    while (static_cast<int>(digits.size()) < 10) {
        current += n;
        for (int x = current; x; x /= 10) {
            digits.insert(x % 10);
        }
    }
    return current;
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++ t) {
        printf("Case #%d: ", t);
        int n;
        scanf("%d", &n);
        int result = solve(n);
        if (~result) {
            printf("%d\n", result);
        } else {
            puts("INSOMNIA");
        }
    }
    return 0;
}
