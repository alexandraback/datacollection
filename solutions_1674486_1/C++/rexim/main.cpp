#include <cstdio>
#include <iostream>

#include <vector>
#include <list>
#include <string>

#include <algorithm>
#include <functional>

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;

const int MAXN = 1010;
int n = 0;
list<int> graph[MAXN];
int d[MAXN];

bool bfs(int s)
{
    for(int i = 0; i < n; ++i)
        d[i] = 0;

    list<int> queue;
    queue.push_back(s);

    while(!queue.empty()) {
        int v = queue.front(); queue.pop_front();

        if(d[v] == 1) return true;
        ++d[v];

        for(auto &u : graph[v])
            queue.push_back(u);
    }

    return false;
}

bool solve_case()
{
    for(int i = 0; i < n; ++i)
        if(bfs(i))
            return true;

    return false;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    for(int i = 0; i < t; ++i) {
        cin >> n;

        for(int j = 0; j < n; ++j) {
            int m;
            cin >> m;

            graph[j].clear();
            d[j] = 0;

            for(int k = 0; k < m; ++k) {
                int v;
                cin >> v;
                graph[j].push_back(v - 1);
            }
        }


        cout << "Case #" << i + 1 << ": ";

        if(solve_case())
            cout << "Yes";
        else
            cout << "No";

        cout << endl;
    }

    return 0;
}
