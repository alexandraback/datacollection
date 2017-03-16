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
#include <time.h>
#include <errno.h>
#include <Semaphore.h>

using namespace std;

vector<string> v = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
vector<pair<char, int>> searchv = {{'Z',0}, {'W',2}, {'X',6},  {'G',8}, {'T',3}, {'R',4}, {'F',5}, {'V',7},  {'O',1}, {'E',9}};
map<char, int> m;

int main() {
    freopen("/Users/lujcmss/Downloads/A-small-attempt0.in.txt", "r", stdin);
    freopen("/Users/lujcmss/Downloads/a.txt", "w", stdout);
    
    int T;
    cin >> T;
    
    for (int kase = 0; kase < T; kase++) {
        string s;
        cin >> s;
        
        m.clear();
        for (int i = 0; i < s.size(); i++) {
            m[s[i]]++;
        }
        
        vector<int> final;
        final.clear();
        final.resize(10);
        for (auto p : searchv) {
            int tmp = m[p.first];
            final[p.second] = tmp;
            if (tmp) {
                for (int i = 0; i < v[p.second].size(); i++) {
                    m[v[p.second][i]] -= tmp;
                }
            }
        }
        
        printf("Case #%d: ", kase+1);
        for (int i = 0; i < 10; i++) {
            assert(m[i] == 0);
            if (final[i]) {
                for (int j = 0; j < final[i]; j++) {
                    printf("%d", i);
                }
            }
        }
        printf("\n");
    }
    return 0;
}