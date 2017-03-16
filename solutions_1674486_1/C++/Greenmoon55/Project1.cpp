#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int nodeMax = 1010;
int p[nodeMax];//p:parent
int rank[nodeMax];
int map[nodeMax][nodeMax];
int n;
//bool worked[nodeMax];
//bool ans[nodeMax];

void make_set()
{
    for (int i=1;i<=n;i++) //pay attention!
    {
        p[i]=i;
        rank[i]=0;
    }
}

int find_set(int x)
{
    if (x!=p[x]) p[x]=find_set(p[x]);
    return p[x];
}

bool work(int a)
{
    int x, y;
    int temp;
    for (int i = 1; i <=map[a][0]; i++)
    {
        temp = map[a][i];
        x = find_set(a);
        y = find_set(map[a][i]);
        if (x != y)
        {
            if (rank[x]>rank[y]) p[y]=x;
            else
            {
                p[x]=y;
                if (rank[x]==rank[y]) rank[y]++;
            }
        }
        else return true;
    }
    for (int i = 1; i <= map[a][0]; i++)
    {
        if (work(map[a][i])) return true;
    }
    return false;
}

int main()
{
    int t;

    freopen("A-large.in","r", stdin);
    freopen("out.txt","w",stdout);
    cin >> t;
    for (int tcase = 1; tcase <= t; tcase++)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> map[i][0];
            for (int j  = 1; j <= map[i][0]; j++) cin >> map[i][j];
        }
        bool yes = false;
        for (int i = 1; i <= n; i++)
        {
            make_set();
            if (work(i))
            {
                yes = true;
                break;
            }
        }
        printf("Case #%d: ", tcase);
        if (yes) printf("Yes\n");
         else printf("No\n");
    }
    fclose(stdout);
    return 0;
}
