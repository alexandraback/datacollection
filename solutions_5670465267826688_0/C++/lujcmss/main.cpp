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
map<pair<int, int>, int> mp;

int get(int x, int y) {
    return x / abs(x) * y / abs(y) * mp[make_pair(abs(x), abs(y))];
}

int calc(int loopsum, long long times) {
    if (times == 0) {
        return 1;
    }
    if (times == 1) {
        return loopsum;
    }
    
    int tmp = calc(loopsum, times / 2);
    int res = get(tmp, tmp);
    if (times % 2) {
        return get(res, loopsum);
    } else {
        return res;
    }
}

int main() {
    freopen("/Users/lujcmss/Downloads/C-small-attempt0.in.txt", "r", stdin);
    freopen("/Users/lujcmss/Downloads/C-out", "w", stdout);
    
    mp.clear();
    mp[make_pair(1, 1)] = 1; mp[make_pair(1, 2)] = 2; mp[make_pair(1, 3)] = 3; mp[make_pair(1, 4)] = 4;
    mp[make_pair(2, 1)] = 2; mp[make_pair(2, 2)] = -1; mp[make_pair(2, 3)] = 4; mp[make_pair(2, 4)] = -3;
    mp[make_pair(3, 1)] = 3; mp[make_pair(3, 2)] = -4; mp[make_pair(3, 3)] = -1; mp[make_pair(3, 4)] = 2;
    mp[make_pair(4, 1)] = 4; mp[make_pair(4, 2)] = 3; mp[make_pair(4, 3)] = -2; mp[make_pair(4, 4)] = -1;
    
    int T;
    scanf("%d", &T);
    
    for (int kase = 0; kase < T; kase++) {
        long long l, x;
        scanf("%lld%lld", &l, &x);
        
        string s;
        cin >> s;
        
        printf("Case #%d: ", kase+1);
        
        int loopsum = 1;
        for (int i = 0; i < s.length(); i++) {
            loopsum = get(loopsum, s[i] - 'g');
        }
        
        set<int> can1;
        can1.clear();
        int index1 = -1;
        int sum1 = 1;
        int loop1 = -1;
        size_t size1 = 0;
        
        do {
            size1 = can1.size();
            loop1++;
            
            for (int i = 0; i < s.length(); i++) {
                sum1 = get(sum1, s[i] - 'g');
                can1.insert(sum1);
                if (sum1 == 2 && index1 == -1) {
                    index1 = i;
                }
            }
        } while (index1 == -1 && size1 != can1.size());
        
        if (index1 == -1) {
            printf("NO\n");
            continue;
        }
        
        set<int> can2;
        can2.clear();
        int index2 = -1;
        int sum2 = 1;
        int loop2 = -1;
        size_t size2 = 0;
        
        do {
            size2 = can2.size();
            loop2++;
            
            for (int i = (int)s.length() - 1; i >= 0; i--) {
                sum2 = get(s[i] - 'g', sum2);
                can2.insert(sum2);
                if (sum2 == 4 && index2 == -1) {
                    index2 = i;
                }
            }
        } while (index2 == -1 && size2 != can2.size());
        
        if (index2 == -1) {
            printf("NO\n");
            continue;
        }
        
        if (loop1 + loop2 + 1 > x) {
            printf("NO\n");
            continue;
        } else if (loop1 + loop2 + 1 == x) {
            if (index1 + 1 >= index2) {
                printf("NO\n");
                continue;
            }
        }
        
        int mid = 1;
        if (loop1 + loop2 + 1 == x) {
            for (int i = index1 + 1; i < index2; i++) {
                mid = get(mid, s[i] - 'g');
            }
        } else {
            int left = 1, right = 1;
            for (int i = index1 + 1; i < s.length(); i++) {
                left = get(left, s[i] - 'g');
            }
            for (int i = 0; i < index2; i++) {
                right = get(right, s[i] - 'g');
            }
            mid = get(get(left, calc(loopsum, x - loop1 - loop2 - 2)), right);
        }
        
        if (mid == 3) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    
    return 0;
}