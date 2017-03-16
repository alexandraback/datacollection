#define _USE_MATH_DEFINES
#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <complex>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <limits>
#include <climits>
#include <cfloat>
#include <functional>
using namespace std;

void shortestPath(const vector<vector<int> >& edges, int start, vector<int>& dist)
{
    int n = edges.size();
    dist.assign(n, INT_MAX);
    dist[start] = 0;
    queue<int> q;
    q.push(start);

    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(unsigned i=0; i<edges[v].size(); ++i){
            int u = edges[v][i];
            if(dist[u] == INT_MAX){
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
    }

    replace(dist.begin(), dist.end(), INT_MAX, -1);
}

int solve(const vector<int>& f)
{
    int n = f.size();
    vector<vector<int> > revEdge(n);
    for(int i=0; i<n; ++i)
        revEdge[f[i]].push_back(i);

    int maxCircle = 0;
    int ans = 0;
    for(int i=0; i<n; ++i){
        vector<int> dist;
        shortestPath(revEdge, i, dist);
        if(dist[f[i]] != -1)
            maxCircle = max(maxCircle, dist[f[i]] + 1);

        if(f[f[i]] == i){
            vector<vector<int> > revEdge2 = revEdge;
            revEdge2[f[i]].erase(find(revEdge2[f[i]].begin(), revEdge2[f[i]].end(), i));
            revEdge2[i].erase(find(revEdge2[i].begin(), revEdge2[i].end(), f[i]));

            vector<int> dist1, dist2;
            shortestPath(revEdge2, i, dist1);
            shortestPath(revEdge2, f[i], dist2);

            int tmp1 = 0;
            int tmp2 = 0;
            for(int j=0; j<n; ++j){
                tmp1 = max(tmp1, dist1[j]);
                tmp2 = max(tmp2, dist2[j]);
            }
            ans += tmp1 + tmp2 + 2;
        }
    }

    ans /= 2;
    ans = max(ans, maxCircle);
    return ans;
}

int main()
{
    int T;
    cin >> T;

    for(int t=1; t<=T; ++t){
        int n;
        cin >> n;
        vector<int> f(n);
        for(int i=0; i<n; ++i){
            cin >> f[i];
            -- f[i];
        }

        int ans = solve(f);
        cout << "Case #" << t << ": " << ans << endl;
    }

    return 0;
}