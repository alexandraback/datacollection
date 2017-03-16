#include <iostream>
#include <vector>
#include <stack>
#include <cassert>

using namespace std;

vector<string> labels;
vector<vector<int>> adj;

bool citySort(int c1, int c2) {
    return labels[c1] < labels[c2];
}

int N, M;

bool canExtendDFS(vector<bool> marked, stack<int> s) {
    /* just normal DFS */
    while(!s.empty()) {
        int t = s.top(); s.pop();
        for(int n: adj[t]) {
            if (!marked[n]) {
                marked[n] = true;
                s.push(n);
            }
        }
    }
    
    return marked == vector<bool>(marked.size(), true);
}

void bestExtend(vector<bool> &marked, stack<int> &active, int &popLevels, int &extendThis) {
    int backtrackNode = -1;
    int hereNode      = -1;
    
    for(int node : adj[active.top()]) {
        if (marked[node]) continue;
        
        if (hereNode == -1 || citySort(node, hereNode)) {
            hereNode = node;
        }
    }
    
    int sav = active.top();
    active.pop();
    if (!active.empty() && canExtendDFS(marked, active)) {
        bestExtend(marked, active, popLevels, backtrackNode);
    }
    active.push(sav);
    
    bool goBack = (hereNode == -1) || (backtrackNode != -1 && citySort(backtrackNode, hereNode));
    
    if(goBack) {
        popLevels += 1;
        extendThis = backtrackNode;
    } else {
        popLevels = 0;
        extendThis = hereNode;
    }
}

int extend(vector<bool> &marked, stack<int> &active) {
    int popLevels; int extendThis;
    bestExtend(marked, active, popLevels, extendThis);
    
    assert(extendThis >= 0 && extendThis < N);
    
    while(popLevels--) {
        assert(active.size());
        active.pop();
    }
    
    active.push(extendThis);
    marked[extendThis] = true;
    
    return extendThis;
}

int main() {
    int T; cin >> T;
    for(int t = 1; t <= T; ++t) {
        cin >> N >> M;
        labels.resize(N);
        adj = vector<vector<int>>(N);
        
        
        int start = 0;
        for(int n = 0; n < N; ++n) {
            cin >> labels[n];
            
            if (citySort(n, start)) {
                start = n;
            }
        }
        
        for(int m = 0; m < M; ++m) {
            int from, to; cin >> from >> to; from--, to--;
            
            adj[from].push_back(to);
            adj[to].push_back(from);
        }
        
        stack<int> s;
        s.push(start);
        vector<bool> marked(N, false);
        marked[start] = true;
        string ans = labels[start];
        
        while(marked != vector<bool>(N, true)) {
            ans += labels[extend(marked, s)];
        }
        
        cout << "Case #" << t << ": " << ans << endl;
    }
}