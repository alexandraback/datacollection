#include <algorithm>
#include <bitset>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

bool isless(string& a, string& b) {
    for(int i = 0; i < a.length(); i++) {
        if(a[i] < b[i]) return true;
    }
    return false;
}

string ans = "A";
int T, N, M;
string zips[50];
vector<int> edges[50];

int main() {
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small.out", "w", stdout);
    cin >> T;
    for(int t = 1; t <= T; t++) {
        cin >> N >> M;
        ans = "A";
        for(int n = 0; n < N; n++) {
            cin >> zips[n];
            edges[n].clear();
        }
        for(int m = 0; m < M; m++) {
            int a, b;
            cin >> a >> b;
            a--; b--;
            edges[a].push_back(b);
            edges[b].push_back(a);
        }
        int start = -1;
        for(int i = 0; i < N; i++) {
            if(isless(zips[i], ans)) {
                ans = zips[i];
                start = i;
            }
        }
        int numvisited = 1;
        set<int> seen;
        for(int i = 0; i < edges[start].size(); i++) {
            seen.insert(edges[start][i]);
        }
        vector<int> vis(N, 0);
        vis[start] = 1;
        while(numvisited < N) {
            int best = -1;
            string tbest = "A";
            for(int i = 0; i < N; i++) {
                if(seen.find(i) != seen.end() && !vis[i]) {
                    if(isless(zips[i], tbest)) {
                        best = i;
                        tbest = zips[i];
                    }
                }
            }
            numvisited++;
            ans += tbest;
            vis[best] = 1;
            for(int i = 0; i < edges[best].size(); i++) {
                seen.insert(edges[best][i]);
            }
        }
        cout << "Case #" << t << ": " << ans << endl;
    }
}