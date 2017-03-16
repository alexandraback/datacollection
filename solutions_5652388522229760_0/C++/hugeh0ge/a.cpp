#include <cstdio>
#include <set>
using namespace std;

int T;
long long int n, cur;
set<int> unappeared;

bool check_digit(long long int x) {
    while (x > 0) {
        unappeared.erase(x%10);
        x /= 10;
    }
    return unappeared.empty();
}

int main() {
    scanf("%d", &T);
    for (int Case=1; Case<=T; Case++) {
        scanf("%lld", &n);
        
        if (n == 0) {
            printf("Case #%d: INSOMNIA\n", Case);
            continue;
        }

        unappeared.clear();
        for (int i=0; i<10; i++) unappeared.insert(i);

        cur = n;
        while (1) {
            if (check_digit(cur)) break;
            cur += n;
        }
        printf("Case #%d: %lld\n", Case, cur);
    }
}
