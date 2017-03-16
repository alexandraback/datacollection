#include <cstdio>
#include <vector>
using namespace std;

const int max_height = 1000;

int solve()
{
    int D; scanf("%d", &D);
    vector<int> stacks;
    for (int i = 0; i < D; i++)
    {
        int p; scanf("%d", &p);
        stacks.push_back(p);
    }

    int min_time = max_height;
    for (int cutoff = 1; cutoff <= max_height; cutoff++)
    {
        int clock = 0;
        for (auto height : stacks)
        {
            if (height % cutoff == 0) clock += height / cutoff - 1;
            else clock += height / cutoff;
        }
        min_time = min(min_time, clock + cutoff);
    }
    return min_time;
}

int main()
{
    int T; scanf("%d", &T);
    for (int t = 1; t <= T; t++)
        printf("Case #%d: %d\n", t, solve());
    return 0;
}
