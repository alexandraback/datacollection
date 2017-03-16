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

int k, l, s;
string keys, tar;

int tot, expc, maxn;

int check(string str) {
    int ret = 0;
    for (int i = 0; i < str.length() - l + 1; i++) {
        bool flag = true;
        for (int j = 0; j < l; j++) {
            if (str[i+j] != tar[j]) {
                flag = false;
                break;
            }
        }
        if (flag) ret++;
    }
    
    return ret;
}

void make(int deep, string cur) {
    if (deep == s) {
        tot++;
        int tmp = check(cur);
        maxn = max(maxn, tmp);
        expc += tmp;
        return;
    }
    
    for (int i = 0; i < k; i++) {
        make(deep+1, cur+keys[i]);
    }
}

int main() {
    freopen("/Users/lujcmss/Downloads/B-small-attempt0.in.txt", "r", stdin);
    freopen("/Users/lujcmss/Downloads/b-small-out", "w", stdout);
    
    int T;
    scanf("%d", &T);
    
    for (int kase = 0; kase < T; kase++) {
        cin >> k >> l >> s;
        cin >> keys >> tar;

        tot = expc = maxn = 0;
        make(0, "");
        
        double ans = maxn ? maxn - 1.0 * expc / tot : 0;
        printf("Case #%d: %.6f\n", kase+1, ans);
    }
    
    return 0;
}