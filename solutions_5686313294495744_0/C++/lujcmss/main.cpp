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

vector<pair<string, string>> v;
map<string, int> word;

int main() {
    freopen("/Users/lujcmss/Downloads/C-small-attempt1.in.txt", "r", stdin);
    freopen("/Users/lujcmss/Downloads/c.txt", "w", stdout);
    
    int T;
    cin >> T;
    
    for (int kase = 0; kase < T; kase++) {
        int n;
        cin >> n;
        
        v.clear();
        word.clear();
        for (int i = 0; i < n; i++) {
            string s1, s2;
            cin >> s1 >> s2;
            s1 += "f";
            s2 += "s";
            word[s1]++;
            word[s2]++;
            v.push_back(make_pair(s1, s2));
        }
        
        int ans = 0, last = -1;
        while (ans != last) {
            last = ans;
            for (auto& p : v) {
                if (word.find(p.first) != word.end() && word[p.first] == 1) {
                    word.erase(p.first);
                    word.erase(p.second);
                    ans++;
                }
                if (word.find(p.second) != word.end() && word[p.second] == 1) {
                    word.erase(p.first);
                    word.erase(p.second);
                    ans++;
                }
            }
            map<string, int> tmp;
            tmp.clear();
            
            for (auto& p : v) {
                if (word.find(p.first) != word.end() && word.find(p.second) != word.end()) {
                    tmp[p.first]++;
                    tmp[p.second]++;
                }
            }
            for (auto& w : word) {
                if (tmp.find(w.first) == tmp.end()) {
                    ans++;
                }
            }
            word = tmp;
        }
        ans += (word.size() + 1) / 2;
        
        
        printf("Case #%d: %d\n", kase+1, n - ans);
    }
    return 0;
}