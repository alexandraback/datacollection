// Compile with g++ -Wall -O2

#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <cstdio>

using namespace std;

typedef set<int> IntSet;
typedef multimap<int, int> IntIntMMap;

struct GreaterSecond : binary_function<pair<int, int>, pair<int, int>, bool>
{
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const
    {
        return a.second > b.second;
    }
};

int main()
{
    int T;
    scanf("%d", &T);
    for (int testcase = 1; testcase <= T; ++testcase)
    {
        int N;
        scanf("%d", &N);
        vector<pair<int, int> > stages(N);
        for (int i = 0; i < N; ++i)
            scanf("%d%d", &stages[i].first, &stages[i].second);
        sort(stages.begin(), stages.end(), GreaterSecond());
        IntIntMMap rat1;
        for (int i = 0; i < N; ++i)
            rat1.insert(IntIntMMap::value_type(stages[i].first, i));
        IntIntMMap rat2;
        for (int i = 0; i < N; ++i)
            rat2.insert(IntIntMMap::value_type(stages[i].second, i));
        IntSet av1;
        IntSet av2;
        int stars = 0;
        int cost = 0;
        while (stars < 2 * N)
        {
            while (!rat1.empty())
            {
                IntIntMMap::iterator it = rat1.begin();
                if (it->first > stars)
                    break;
                av1.insert(it->second);
                rat1.erase(it);
            }
            while (!rat2.empty())
            {
                IntIntMMap::iterator it = rat2.begin();
                if (it->first > stars)
                    break;
                av2.insert(it->second);
                rat2.erase(it);
            }
            if (!av2.empty())
            {
                ++cost;
                IntSet::iterator it = av2.begin();
                if (av1.erase(*it))
                    ++stars;
                av2.erase(it);
                ++stars;
            }
            else if (!av1.empty())
            {
                ++cost;
                IntSet::iterator it = av1.begin();
                av1.erase(it);
                ++stars;
            }
            else
            {
                cost = -1;
                break;
            }
        }
        printf("Case #%d: ", testcase);
        if (cost == -1)
            printf("Too Bad\n");
        else
            printf("%d\n", cost);
    }
    return 0;
}
