#include <cstdlib>
#include <bitset>
#include <functional>
#include <utility>
#include <tuple>
#include <limits>
#include <cstdint>
#include <cctype>
#include <string>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <random>
#include <numeric>
#include <iostream>
#include <sstream>

using namespace std;

unordered_map<int, int> fw;
unordered_map<int, unordered_set<int>> bw;
unordered_map<int, int> twos;
unordered_map<int, int> twos2;

int n, best = 0;
vector<bool> flag;
bool deb = false;

int dfs(int start){
    if(deb)
        cerr << "DFS " << start << endl;
    
    if(bw.find(start) == bw.end())
        return 1;
    
    int ret = 0;
    for(int next : bw[start]){
        if(flag[next])
            continue;
        ret = max(ret, dfs(next));
    }
    if(deb)
        cerr << "DFS " << start << " ret " << ret + 1 << endl;
    return ret + 1;
}

void build(int start){
    if(deb)
        cerr << "START " << start << endl;
    flag.assign(n+1, false);
    flag[start] = true;
    int cnt = 1;
    int cur = start, next, prev = -1;
    while (true) {
        next = fw[cur];
        if(deb)
            cerr << prev << "," << cur << "," << next << endl;
        if(flag[next]){
            if(next == start){
                if(cnt == 2){
                    break;
                } else{
                    best = max(best, cnt);
                    return;
                }
            }
            if(next == prev)
                break;
            
            return;
        }
        flag[next] = true;
        prev = cur;
        cur = next;
        ++cnt;
    }
    
    int left = dfs(start) - 1;
    int right = dfs(cur) - 1;
    cnt += left += right;
    
    for(auto &p : twos){
        if(!flag[p.first] && !flag[p.second]){
            cnt += twos2[p.first];
        }
    }
    
    best = max(best, cnt);
    if(deb)
    cerr << "BEST " << best << endl;
}

void comp(int tc){
    cin >> n;
    
    fw.clear();
    bw.clear();
    flag.clear();
    twos.clear();
    
    for(int i=1; i<=n; ++i){
        int a;
        cin >> a;
        fw[i] = a;
        bw[a].insert(i);
    }
    
    for(int i=1; i<=n; ++i){
        int other = fw[fw[i]];
        if(i == other){
            twos[min(i, fw[i])] = max(i, fw[i]);
        }
    }
    
    flag.assign(n+1, false);
    for(auto &p : twos){
        flag[p.first] = true;
        flag[p.second] = true;
        twos2[p.first] = 2 + dfs(p.first) - 1 + dfs(p.second) - 1;
    }
    
    best = 0;
    for(int i=1; i<=n; ++i){
        build(i);
    }
    
    cout << "Case #" << tc << ": " << best << endl;
}

int main(){
    int T;
    cin >> T;
    for(int tc=1; tc<=T; ++tc){
        comp(tc);
    }
}