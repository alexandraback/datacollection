#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

void solvetp()
{
    int n;
    set <int> vals;
    scanf("%d",&n);
    for (int i=1; i<n*2; i++)
        for (int j=1; j<=n; j++)
        {
            int x;
            scanf("%d",&x);
            auto it=vals.find(x);
            if (it==vals.end())
                vals.insert(x);
            else
                vals.erase(it);
        }
    for (auto it=vals.begin(); it!=vals.end(); it++)
        printf("%d ",*it);
    printf("\n");
}

int main()
{
    freopen("D:/in.txt","r",stdin);
    freopen("D:/out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for (int it=1; it<=t; it++)
    {
        printf("Case #%d: ",it);
        solvetp();
    }
}
