#include <iostream>
using namespace std;

int work(int n, int m, int w) {
        if (w == m) {
                return n + (w-1);
        }
        int t = m / w;
        return n * t + (w-1) + (m % w != 0);
}

int main()
{
        int d;
        scanf("%d", &d);
        for (int i = 1; i <= d; ++i) {
                int n, m, c;
                scanf("%d%d%d", &n, &m, &c);
                printf("Case #%d: %d\n", i, work(n, m, c));
        }
}
