#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#define N 3000
using namespace std;

int visit[N];
int n;

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("dataB.out","w",stdout);

    int t, ys = 0;

    scanf("%d", &t);
    while (t--)
    {
        memset(visit, 0, sizeof(visit));
        scanf("%d", &n);
        int x;
        for (int i = 0; i < n + n - 1; ++i)
            for (int j = 0; j < n; ++j)
            {
                scanf("%d", &x);
                visit[x]++;
            }
        vector<int> ans;
        for (int i = 0; i < N; ++i)
            if (visit[i] %2 == 1)
                ans.push_back(i);
        sort(ans.begin(), ans.end());
        printf("Case #%d:", ++ys);
        for (int i = 0; i < ans.size(); ++i)
            printf(" %d", ans[i]);
        printf("\n");
    }

    return 0;
}


