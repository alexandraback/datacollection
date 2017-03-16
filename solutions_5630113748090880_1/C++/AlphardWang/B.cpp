#include <cstdio>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

map<int, int> cnt;
vector<int> ans;
int main()
{
    int cases;
    scanf("%d", &cases);
    ans.reserve(100);
    for (int c = 1; c <= cases; ++c)
    {
        int n, d;
        ans.clear();
        cnt.clear();
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 1; j < n * 2; ++j)
            {
                scanf("%d", &d);
                if (cnt.find(d) == cnt.end())
                {
                    cnt[d] = 1;
                }
                else
                {
                    ++cnt[d];
                }
            }
        }

        for (auto& num : cnt)
        {
            if ((num.second & 1) == 1)
            {
                ans.push_back(num.first);
            }
        }

        sort(ans.begin(), ans.end());
        printf("Case #%d:", c);
        for (auto num : ans)
        {
            printf(" %d", num);
        }

        printf("\n");
    }
}