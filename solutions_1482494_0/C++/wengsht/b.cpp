#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

const int MX = 1001;
int pow;
int had[MX];
int T, N;
int k;

struct Node
{
    int index;
    int a, b;
}node[MX], node2[MX];

bool _cmpb(struct Node L, struct Node R)
{
    return L.b < R.b;
}
bool _cmpa(struct Node L, struct Node R)
{
    if(L.a != R.a) return L.a < R.a;
    return L.b > R.b;
}
//#define HOME
//#define small
//#define large
int main()
{
#ifdef HOME
    freopen("1.txt", "r", stdin);
#endif
#ifdef small
    freopen("B-small-attempt1.in", "r", stdin);
    freopen("out", "w", stdout);
#endif
#ifdef large
    freopen("B-large.in","r",stdin);
    freopen("out", "w", stdout);
#endif
    scanf("%d", &T);
    int _case = 1;
    while(T--)
    {
        pow = 0;
        memset(had, 0, sizeof(had));
        scanf("%d", &N);
        for(int i = 1;i <= N;i++)
        {
            scanf("%d %d", &node[i].a, &node[i].b);
            node[i].index = i;
        }
        memcpy(node2, node, sizeof(node[0]) * MX);
        sort(node+1, node+N+1,_cmpb);
        sort(node2+1,node2+N+1,_cmpa);

        int Count = 0;
        int i = 1;
        while(i <= N)
        {
            bool ok = false;
            for(; i <= N;)
            {
                k = node[i].index;
               
                if(node[i].b <= pow)
                {
                    Count++;
                    ok = true;
                    pow += 2 - had[k];
                    had[k] = 2;
                    i++;
                }
                else break;
            }
            int to_a = N;
            for(; to_a >= i;to_a--)
            {
                if(node[to_a].a <= pow && had[node[to_a].index] < 1) break;
            }
            if(to_a >= i)
            {
                ok = true;
                had[node[to_a].index] = 1;
                pow++;
                Count++;
            }
            if(!ok) break;
        }

        if(i == N+1)
            printf("Case #%d: %d\n", _case++, Count);
        else
            printf("Case #%d: Too Bad\n", _case++);
    }

}
