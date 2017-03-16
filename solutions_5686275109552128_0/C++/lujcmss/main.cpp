#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>

#include <thread>
#include <chrono>

#include <memory>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/stat.h>

using namespace std;

int d;
int p[1010];

bool check(int x) {
    for (int i = x; i > 0; i--) {
        int sum = 0;
        for (int j = 0; j < d; j++) {
            if (p[j] > i) {
                sum += (p[j] - 1) / i;
            }
        }
        if (sum + i <= x) {
            return true;
        }
    }
    return false;
}

int main() {
    freopen("/Users/lujcmss/Downloads/B-small-attempt0.in.txt", "r", stdin);
    freopen("/Users/lujcmss/Downloads/B-out", "w", stdout);
    
    int T;
    scanf("%d", &T);
    
    for (int kase = 0; kase < T; kase++) {
        scanf("%d", &d);
        int l = 0, r = 0;
        for (int i = 0; i < d; i++) {
            scanf("%d", p+i);
            r += p[i];
        }
        
        while (l < r) {
            int mid = (l + r) / 2;
            if (check(mid)) {
                r = mid;
            } else {
                l = mid+1;
            }
        }
        
        printf("Case #%d: %d\n", kase+1, l);
    }
    
    return 0;
}