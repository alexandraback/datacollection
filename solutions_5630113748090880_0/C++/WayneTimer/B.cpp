#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int a[3000];
int main()
{
    int T,n,max_x;
    scanf("%d",&T);
    for (int o=1;o<=T;o++)
    {
        scanf("%d",&n);
        max_x = -1;
        memset(a,0,sizeof(a));
        for (int i=0;i<2*n-1;i++)
            for (int j=0;j<n;j++)
            {
                int x;
                scanf("%d",&x);
                a[x]++;
                if (x>max_x) max_x = x;
            }
        vector<int> ans;
        ans.clear();
        for (int i=1;i<=max_x;i++)
            if (a[i]&1 != 0)
                ans.push_back(i);
        sort(ans.begin(),ans.end());
        printf("Case #%d:",o);
        int l = ans.size();
        for (int i=0;i<l;i++)
            printf(" %d",ans[i]);
        puts("");
    }
    return 0;
}
