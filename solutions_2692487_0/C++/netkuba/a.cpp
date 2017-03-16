#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int counter = 0;
void make() {
    printf("Case #%d: ", ++counter);
    int a, n; scanf("%d %d", &a, &n);
    vector<int> motes(n);
    for (int i=0; i<n; ++i) {
        scanf("%d", &motes[i]);
    }
    sort(motes.begin(), motes.end());
    int acc = 0;
    int result = n;
    if (a > 1) {
        for (int i=0; i<n; ++i) {
            while (a <= motes[i]) {
                ++acc;
                a += a-1;

            }
            a += motes[i];
            result = min(result, acc + n-i-1);
        }
    }
    printf("%d\n", result);
}

int main() {
    int t; scanf("%d", &t);
    while(t--) make();
    return 0;
}
