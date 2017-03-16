#include <bits/stdc++.h>
using namespace std;


int main() {
    int totaltc;
    int D;
    int tc = 1;
    int tmp;
    static int pancakes[1001];
    scanf("%d", &totaltc);
    while (totaltc--) {
        memset(pancakes,0,sizeof(pancakes));
        scanf("%d", &D);
        int maxpancake = 0;
        for (int i = 0; i < D; i++) {
            scanf("%d", &tmp);
            for (int i = 1; i < tmp; i++) {
                int add = tmp/i;
                add += (tmp%i != 0);
                add--;
                pancakes[i] += add;
                maxpancake = max(maxpancake, tmp);
            }
        }
        int besttime = 1000;
        for (int i = 1; i <= 1000; i++) {
            besttime = min(besttime, pancakes[i] + i);
        }
        printf("Case #%d: %d\n", tc++, besttime);
    }
    return 0;
}
