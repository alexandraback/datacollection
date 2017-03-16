#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <deque>
using namespace std;


string solve(int N, vector<int> G[]) {
    for(int i=1;i<=N;i++) {
        bool a[1002] = {false, };
        deque<int> q;

        a[i] = true;
        q.push_back(i);

        int t,u;
        while(!q.empty()) {
            t = q.front(); q.pop_front();

            for(int i=0;i<G[t].size();i++) {
                u = G[t][i];
                if(a[u] == true) return "Yes";
                q.push_back(u);
                a[u] = true;
            }
        }
    }

    return "No";
}

int main() {
    int T;

    cin >> T;
    for(int cs=1; cs<=T; cs++) {
        int N,M;
        vector<int> G[1002];

        cin >> N;
        for(int i=1;i<=N;i++) {
            cin >> M;
            while(M--) {
                int tt;
                cin >> tt;
                G[tt].push_back(i);
            }
        }

        string ret = solve(N,G);
        printf("Case #%d: %s\n", cs, ret.c_str());
    }

    return 0;
}
