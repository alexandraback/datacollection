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

long long f[110];

int main() {
    freopen("/Users/lujcmss/Downloads/C-large.in.txt", "r", stdin);
    freopen("/Users/lujcmss/Downloads/c-large", "w", stdout);

    int T;
    scanf("%d", &T);
    
    for (int kase = 0; kase < T; kase++) {
        long long c, d, v;
        cin >> c >> d >> v;
        for (int i = 0; i < d; i++) {
            cin >> f[i];
        }
        
        int ans = 0;
        long long tot = 0;
        int index = 0;
        if (f[0] == 1) {
            tot = c;
            index = 1;
        }
        while (tot < v) {
            while (index < d && tot >= f[index] - 1) {
                tot += f[index] * c;
                index++;
            }
            if (tot < v) {
                ans++;
                tot += (tot+1) * c;
            }
        }
        
        printf("Case #%d: %d\n", kase+1, ans);
    }
    
    return 0;
}