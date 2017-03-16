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
    freopen("/Users/tianyi/Desktop/input.txt", "r", stdin);
    freopen("/Users/tianyi/Desktop/output.txt", "w", stdout);
    int tc; scanf("%d", &tc);
    for (int casen = 1; casen <= tc; casen++) {
        long long k, c, s; scanf("%lld%lld%lld", &k, &c, &s);
        long long n = 1;
        for (int i = 1; i <= c-1; i++) {
            n *= k;
        }
        printf("Case #%d:", casen);
        for (int i = 1; i <= k; i++) {
            printf(" %lld", n*i);
        }
        printf("\n");
    }
    
    return 0;
}