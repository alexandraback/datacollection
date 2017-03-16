#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <math.h>
#include <iostream>
using namespace std;


int iDfs (int u, vector<vector<int> > &iBff, vector<bool> &found) {
    
    found[u] = true;
    int maxCount = 0;
    for (int i = 0; i < iBff[u].size(); i++) {
        if (found[iBff[u][i]] == false) {
            maxCount = max(maxCount, iDfs(iBff[u][i], iBff, found) + 1);
        }
    }
    return maxCount;
}

void dfs(int u, vector<int> &bff, vector<bool> &inCycle, int &count) {
    
    inCycle[u] = false;
    count++;
    if (inCycle[bff[u]]) {
        dfs(bff[u], bff, inCycle, count);
    }
}


int main() {
    //    freopen("input.txt", "rt", stdin);
    //    freopen("output.txt", "wt", stdout);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    for (int z = 0; z < T; z++) {
        
        int N;
        cin >> N;
        
        
        vector<int> bff(N);
        vector<int> indegree(N, 0);
        vector<vector<int> > invertBff(N);
        
        for (int i = 0; i < N; i++) {
            int x;
            cin >> x;
            bff[i] = x-1;
            invertBff[x-1].push_back(i);
            indegree[bff[i]] += 1;
        }
        
        vector<bool> inCycle(N, true);
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (inCycle[j] && indegree[j] <= 0) {
                    inCycle[j] = false;
                    indegree[bff[j]] -= 1;
                }
            }
        }
        
        int maxCount = 0;
        
        for (int i = 0; i < N; i++) {
            int count = 0;
            if (inCycle[i]) {
                dfs(i, bff, inCycle, count);
            }
            maxCount = max(maxCount, count);
        }
        
        vector<pair<int, int> > twoCycle;
        vector<pair<int, int> > twoCycleTails;
        vector<bool> foundTwoCycle(N, false);
        for (int i = 0; i < N; i++) {
            if (foundTwoCycle[i] == false && bff[bff[i]] == i) {
                twoCycle.push_back(pair<int,int>(i, bff[i]));
                twoCycleTails.push_back(pair<int,int>(0,0));
                foundTwoCycle[i] = true;
                foundTwoCycle[bff[i]] = true;
            }
        }
        
        //invertBff
        //check for cycle of two's
        bool usedTwo = false;
        
        int TwoTotal = 0;
        
        for (int i = 0; i < twoCycle.size(); i++) {
            vector<bool> found(N, false);
            int one = twoCycle[i].first;
            int two = twoCycle[i].second;
            found[one] = true;
            found[two] = true;
            int countOne = iDfs(one, invertBff, found);
            int countTwo = iDfs(two, invertBff, found);
            TwoTotal += countOne;
            TwoTotal += countTwo;
            TwoTotal += 2;
        }
        
        
        
        
        maxCount = max(maxCount, TwoTotal);
        
        cout << "Case #" << z+1 << ": " << maxCount << "\n";
        
        
        
    }
    

    
    return 0;
}
