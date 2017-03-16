#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <deque>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int N;
vector<int>E[1003];
set<int>B[1003];

int main()
{
    freopen("a.in", "rt", stdin);
    freopen("a.out", "wt", stdout);
    int T;
    scanf("%d", &T);
    for (int cas=1; cas<=T; ++cas)
    {
        scanf("%d", &N);
        for (int i=0; i<N; ++i) E[i].clear(), B[i].clear();
        for (int i=0; i<N; ++i)
        {
            int M, P;
            scanf("%d", &M);
            for (int j=0; j<M; ++j) scanf("%d", &P), --P, E[P].push_back(i);
        }
        for (int i=0; i<N; ++i)
        {
            queue<int>Q;
            for (int j=0; j<(int)E[i].size(); ++j) Q.push(E[i][j]);
            while (!Q.empty())
            {
                int f = Q.front(); Q.pop();
                if (B[f].find(i)!=B[f].end()) goto YES;
                B[f].insert(i);
                for (int j=0; j<(int)E[f].size(); ++j) Q.push(E[f][j]);
            }
        }
        printf("Case #%d: No\n", cas);
        continue;
        YES:
        printf("Case #%d: Yes\n", cas);
    }
    return 0;
}
