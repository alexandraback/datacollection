#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cfloat>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

bool generateNextGraph(vector< vector<int> > &adjList, int b)
{
    long long powsOf2[51] = {1};
    long long maxVal = 1;
    vector<int> newList;
    for(int i=1; i <= b; ++i)
        powsOf2[i] = powsOf2[i-1] * 2;
    maxVal = powsOf2[b] - 1;

    for(int i=b-2; i>= 0; --i)
    {
        long long val = 0;
        for(int j=0; j < adjList[i].size(); ++j)
            val += powsOf2[adjList[i][j]];

        if(val < maxVal)
        {
            val++;
            int j = b-1;
            while(val)
            {
                if(val % 2)
                    newList.push_back(j--);
                val /= 2;
            }
            adjList[i].resize(newList.size());
            for(int j=0; j < newList.size(); ++j)
                adjList[i][j] = newList[j];
            return true;
        }
        else
        {
            adjList[i].resize(newList.size());
            for(int j=0; j < newList.size(); ++j)
                adjList[i][j] = newList[j];
        }
    }

    return false;
}

int dfs(int u, int color[51], vector< vector<int> > &adjList, long long ways[51], int b)
{
    color[u] = 1;

    for(int i=0; i < adjList[u].size(); ++i)
    {
        if(adjList[u][i])
        {
            int adj = adjList[u][i];
            if(color[adj] == 2)
            {
                ways[u] += ways[adj];
            }
            else if(color[adj] == 0)
            {
                ways[u] += dfs(adj, color, adjList, ways, b);
            }
            else
            {
                ;
            }
        }
    }

    color[u] = 2;
    return ways[u];
}

int main()
{
    int b, T;
    long long m;
    vector< vector<int> > adjList;
    scanf("%d", &T);
    for(int t=1; t <= T; ++t)
    {
        scanf("%d%lld", &b, &m);
        adjList.resize(b);
        bool found = false;

        int tried = 0;
        do
        {
            int color[51];
            long long ways[51];
            for(int i=0; i < b; ++i)
            {
                color[i] = 0;
                ways[i] = 0LL;
            }
            color[b-1] = 2;
            ways[b-1] = 1;
            long long result = dfs(0, color, adjList, ways, b);
            if(result == m)
            {
                found = true;
                break;
            }
            tried++;
        }
        while(generateNextGraph(adjList, b));

        printf("Case #%d: ", t);
        if(found)
        {
            printf("POSSIBLE\n");
            for(int i=0; i < b; ++i)
            {
                sort(adjList[i].begin(), adjList[i].end());
                for(int j=0, k=0; j < b; ++j)
                {
                    printf("%d", (k < adjList[i].size() && adjList[i][k] == j ? 1 : 0));
                    if(k < adjList[i].size() && adjList[i][k] <= j)
                    {
                        ++k;
                    }
                }
                printf("\n");
            }
        }
        else
        {
            printf("IMPOSSIBLE\n");
        }
    }

    return 0;
}
