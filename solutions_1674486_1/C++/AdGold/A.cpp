#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

vector<int> edgeList[1001];
int times[1001];

int main()
{
    freopen("A-large(1).in", "r", stdin);
    freopen("a.out", "w", stdout);
    int tests;
    queue<int> q2;
    scanf("%d", &tests);
    for (int i = 0; i < tests; i++)
    {
        int n, m, to;
        bool found = false;
        for (int j = 0; j < 1001; j++)edgeList[j].clear();
        scanf("%d", &n);
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &m);
            if (m == 0)q2.push(j+1);
            for (int k = 0; k < m; k++)
            {
                scanf("%d", &to);
                edgeList[to].push_back(j+1);
            }
        }
        while (q2.size() && !found)
        {
            for (int j = 0; j < 1001; j++)times[j] = 0;
            queue<int> q;
            q.push(q2.front());
            //printf("starting from %d\n", q2.front());
            q2.pop();
            while (q.size())
            {
                int f = q.front();
                q.pop();
                if (times[f] >= 1)
                {
                    printf("Case #%d: Yes\n", i+1);
                    found = true;
                    break;
                }
                times[f]++;
                for (int j = 0; j < edgeList[f].size(); j++)
                {
                    q.push(edgeList[f][j]);
                }
            }
        }
        if (!found)printf("Case #%d: No\n", i+1);
    }
    
}
