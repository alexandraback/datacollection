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


int main() {
    freopen("/Users/lujcmss/Downloads/A-small-attempt0.in.txt", "r", stdin);
    freopen("/Users/lujcmss/Downloads/A-small-attempt0.out.txt", "w", stdout);
    
    int T;
    scanf("%d", &T);
    
    for (int kase = 0; kase < T; kase++) {
        int n;
        string s;
        cin >> n >> s;
        
        int ans = 0;
        int tot = 0;
        for (int i = 0; i <= n; i++) {
            int num = 0;
            if (i < s.length()) {
                num = s[i] - '0';
            }
            if (i == 0) {
                tot += num;
            } else {
                if (tot < i) {
                    ans += i - tot;
                    tot = i + num;
                } else {
                    tot += num;
                }
            }
        }
        
        printf("Case #%d: %d\n", kase+1, ans);
    }
    
    return 0;
}