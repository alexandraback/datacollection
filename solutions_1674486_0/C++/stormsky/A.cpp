#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int case_all, case_count = 1;
    scanf("%d", &case_all);
    for (case_count = 1; case_count <= case_all; case_count += 1)
    {
        printf("Case #%d:", case_count);
        int n = 0, isover = -1;
        scanf("%d", &n);
        set <int> gh[n + 1];
        for (int i = 1; i <= n; ++i)
        {
            int j, k;
            scanf("%d", &j);
            for (int jj = 0; jj < j; ++jj)
            {
                scanf("%d", &k);
                gh[i].insert(k);
            }
        }
        for (int i = 1; i <= n; ++i)
        {
            set <int> p;
            vector <int> q;
            for (set<int>::iterator it = gh[i].begin(); it != gh[i].end(); ++it)
            {
                q.push_back(*it);
                p.insert(*it);
            }
            while (q.size() > 0)
            {
                int x = q[0];
                q.erase(q.begin());
                for (set<int>::iterator it = gh[x].begin(); it != gh[x].end(); ++it)
                {
                    q.push_back(*it);
                    if (p.find(*it) != p.end())
                    {
                        isover = 1;
                        printf(" Yes");
                        break;
                    }
                    else
                    {
                        p.insert(*it);
                    }
                }
                if (isover == 1)
                {
                    break;
                }
            }
            if (isover == 1)
            {
                break;
            }
        }
        if (isover == -1)
        {
            printf(" No");
        }
        printf("\n");
    }
    return 0;
}
