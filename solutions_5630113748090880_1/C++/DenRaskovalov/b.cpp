#include <cstdio>

#include <map>

using namespace std;

using Map = map<int, int>;

int main() {
    int t;
    scanf("%d", &t);
    for (int iTest = 1; iTest <= t; ++iTest) {
        Map map;
        int n;
        scanf("%d", &n);
        for (int i = 0; i < 2*n - 1; ++i) {
            for (int j = 0; j < n; ++j) {
                int number;
                scanf("%d", &number);
                ++map[number];
            }
        }
        printf("Case #%d:", iTest);
        for (auto number: map) {
            if (number.second & 1) {
                printf(" %d", number.first);
            }
        }
        printf("\n");
    }

    return 0;
}
