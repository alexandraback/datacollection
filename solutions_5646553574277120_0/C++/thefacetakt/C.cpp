#include <cstdio>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    for (int z = 1; z <= T; ++z)
    {
        printf("Case #%d: ", z);
        int c, d, v;
        scanf("%d %d %d", &c, &d, &v);
        vector <int> nominals(d);
        for (int i = 0; i < d; ++i)
            scanf("%d", &nominals[i]);
        vector <bool> possible(v + 1);
        for (int i = 0; i < (1 << d); ++i)
        {
            int cur = 0;
            for (int k = 0; k < d; ++k)
                if ((i >> k) & 1)
                    cur += nominals[k];
            if (cur <= v)
                possible[cur] = 1;
        }
        int answer = 0;
        for (int i = 1; i <= v; ++i)
        {
            if (!possible[i])
            {
                ++answer;
                for (int j = 0; j < (1 << nominals.size()); ++j)
                {
                    int cur = i;
                    for (int k = 0; k < nominals.size(); ++k)
                    {
                        if ((j >> k) & 1)
                            cur += nominals[k];
                    }
                    if (cur <= v)
                        possible[cur] = 1;
                }
                nominals.push_back(i);
            }
        }
        printf("%d\n", answer);
    }
}