#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

deque <char> q;

void solvetp()
{
    char base[10005];
    scanf("%s",base);
    int pl=0;
    while (base[pl])
    {
        if (q.empty())
            q.push_front(base[pl]);
        else
            if (base[pl]>=q.front())
                q.push_front(base[pl]);
            else
                q.push_back(base[pl]);
        pl++;
    }
    while (q.size())
    {
        printf("%c",q.front());
        q.pop_front();
    }
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
