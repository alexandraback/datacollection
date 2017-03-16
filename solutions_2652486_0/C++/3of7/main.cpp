#include <cmath>
#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

map< vector<int>, int > m;

void dfs(vector<int> v) {
    if(v.size() == 3) {
        m[v] = 0;
        return;
    }
    for(int i=2; i<=5; i++) {
        vector<int> vv = v;
        vv.push_back(i);
        dfs(vv);
    }
}

int dfs2(vector<int> v, int target) {
    int ret = 0;
    if(target == 1) return 0;
    for(int i=0; i<8; i++) {
        int val = 1;
        for(int j=0; j<3; j++) {
            if(i & (1<<j)) {
                val*=v[j];
            }
        }
        if(val == target) ret=1;
    }
    return ret;
}

int main() {
    int T;
    cin>>T;
    for(int casenum=1; casenum<=T; casenum++) {
        int R, N, M, K;
        cin >> R >> N >> M >> K;
        cout<<"Case #"<<casenum<<":\n";
        for(int r = 0; r < R; r++) {
            m.clear();
            dfs(vector<int>());
            for(int k = 0; k < K; k++) {
                int val;
                cin >> val;
                map< vector<int>, int >::iterator it = m.begin();
                while(it != m.end()) {
                    vector<int> v = (it->first);
                    int addme = dfs2(v, val);
                    it->second += addme;
                    ++it;
                }
            }
            int best = -1;
            vector<int> ans;
            map< vector<int>, int >::iterator it = m.begin();
            while(it != m.end()) {
                if(it->second > best) {
                    best = it->second;
                    ans = it->first;
                }
                ++it;
            }
            for(int i=0; i<3; i++) {
                cout<<ans[i];
            }
            cout<<endl;
        }
    }
    return 0;
}