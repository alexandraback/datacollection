#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>


using namespace std;
#define ll long long


int BFF[1000];
int N;
int dist[1000][1000];

vector<int> loop(int x) {
    vector<int> m;
    m.push_back(x);
    int p = BFF[x], p2 = BFF[x];
    bool vis[1000] = {0};
    vis[x] = true;
    while (!vis[p]) {
        dist[x][p] = m.size();
        m.push_back(p);
        vis[p] = true;
        p = BFF[p];
    }
    if (p == x) {
        return m;
    } else {
        return {};
    }
}

int maxDist(int x, int exclude) {
    int best = 0;
    for (int i=0;i<N;++i) {
        if (i == x || i == exclude) continue;
        
        if (dist[i][x] != -1) {
            if (dist[i][exclude] > dist[i][x]) {
                best = max(best, dist[i][x]);
            }
        }
    }
    return best;
}

int main() {
    int T;
    cin>>T;
    for (int t=1;t<=T;++t) {
        memset(dist,-1,sizeof(dist));
        cin>>N;

        for (int i=0;i<N;++i) {
            cin>>BFF[i];
            BFF[i]--;
        }

        int bestLoop = 0;
        vector<pair<int,int>> pairs;
        for (int i=0;i<N;++i) {
            vector<int> L = loop(i);
            bestLoop = max(bestLoop, (int)L.size()); 
            if (L.size() == 2 && L[0] < L[1]) {
                pairs.push_back(make_pair(L[0], L[1])); 
            }
        }
        //printf("Loop is %d\n", bestLoop);

        int bestPairs = 0;
        for (int i=0;i<pairs.size();++i) {
            int cur = maxDist(pairs[i].first, pairs[i].second) + maxDist(pairs[i].second, pairs[i].first) + 2;
            //printf("Pair %d,%d is %d\n", pairs[i].first, pairs[i].second, cur);
            //printf("Chain to %d is %d\n", pairs[i].first, maxDist(pairs[i].first, pairs[i].second));
            //printf("Chain to %d is %d\n", pairs[i].second , maxDist(pairs[i].second, pairs[i].first));
            bestPairs += cur;
        }



        printf("Case #%d: %d\n", t, max(bestPairs, bestLoop));
    }

}
