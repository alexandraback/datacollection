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
    freopen("/Users/lujcmss/Downloads/A-small-attempt2.in.txt", "r", stdin);
    freopen("/Users/lujcmss/Downloads/a-small-out", "w", stdout);

    int T;
    scanf("%d", &T);
    
    for (int kase = 0; kase < T; kase++) {
        int r, c, w;
        cin >> r >> c >> w;
        
        int minn = c / w;
        int maxn = 0;
        if (c % w == 0) maxn = c / w + w - 1;
        else maxn = (c / w - 1) + 2 * w - (c - w * (c / w - 1)) + 1 + (c % w);
        
        printf("Case #%d: %d\n", kase+1, minn * (r - 1) + maxn);
    }
    
    return 0;
}