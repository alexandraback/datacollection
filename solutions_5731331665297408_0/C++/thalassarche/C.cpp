#include <algorithm>
#include <iostream>
#include <list>
#include <queue>
#include <vector>

#include <cassert>

using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> zipcodes(n);
    for (int& i: zipcodes) cin >> i;
    
    vector<vector<int> > adj(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    list<int> route;
    vector<list<int>::iterator> last_visit(n, route.end());
    int start = distance(zipcodes.begin(), min_element(zipcodes.begin(), zipcodes.end()));
    queue<int> q;
    vector<int> visited(n, -1);
    int time = 0;
    
    visited[start] = time++;
    route.push_back(start);
    last_visit[start] = route.begin();
    for (int i: adj[start]) q.push(i);
    
    while (q.size()) {
        int next = q.front();
        q.pop();
        if (visited[next] >= 0) continue;
        
        int max_t = -1, max_i = -1;
        for (int i: adj[next]) {
            if (visited[i] > max_t) {
                max_t = visited[i];
                max_i = i;
            }
        }
        assert(max_i >= 0);
        
        list<int>::iterator v = last_visit[max_i];
        route.insert(v, max_i);
        last_visit[next] = route.insert(v, next);
        visited[next] = time++;
        for (int i: adj[next]) q.push(i);
    }
    
    vector<char> visited2(n, false);
    for (int i: route) {
        if (visited2[i]) continue;
        visited2[i] = true;
        cout << zipcodes[i];
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
    cout.flush();
    return 0;
}
