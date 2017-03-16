#include <cstdio>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <stack>
#include <map>
#include <queue>
#include <string>
#include <list>
#include <set>
#include <unordered_map>
#include <cstring>
#include <ctime>
#include <bitset>
#include <cassert>
using namespace std;

#define INF 2100000000

int main() {
//    freopen("/Users/tianyi/Desktop/input.txt", "r", stdin);
//    freopen("/Users/tianyi/Desktop/output.txt", "w", stdout);
    int tc; scanf("%d", &tc);
    for (int casen = 1; casen <= tc; casen++) {
        long long n, x; scanf("%lld", &n);
        x = n; // x = the increment
        
        if (n == 0) {
            printf("Case #%d: INSOMNIA\n", casen);
            continue;
        }
        
        int used = 0;
        while (true) {
//            printf("%lld\n", n);
            // tally digits of n, set used
            long long tmp = n;
            while (tmp != 0) {
                used |= (1<<(tmp % 10));
                tmp /= 10;
            }
            
            if (used == (1<<10) -1) {
                printf("Case #%d: %lld\n", casen, n);
                break;
            }
            
            // test used, increment n
            n += x;
        }
    }
    return 0;
}