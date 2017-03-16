#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
 
using namespace std;

#define MX 2000000

int T, N, M;
int k, Count;
int Head[MX], nxt[MX], V[MX];
bool getit[1001];
int cc[1001];
void insert(int a, int b)
{
    nxt[Count] = Head[a];
    V[Count] = b;
    Head[a] = Count++;
}


bool dfs(int p)
{

    for(int i = Head[p]; i != -1; i = nxt[i])
    {
        int v = V[i];
        cc[v]++;
        if(cc[v] > 1) return true;

        if(dfs(v)) return true;
    }
    return false;
}
//#define HOME
//#define SMALL
//#define LARGE
int main() 
{
#ifdef HOME
    freopen("1.txt", "r", stdin);
#endif
#ifdef SMALL
    freopen("out", "w", stdout);
    freopen("A-small-attempt0.in", "r", stdin);
#endif
#ifdef LARGE
    freopen("out", "w", stdout);
    freopen("A-large.in", "r", stdin);
#endif
    scanf("%d", &T);
    for(int c = 1; c <= T;c++)
    {
        Count = 0;
        memset(Head, -1, sizeof(Head));
        memset(getit, false, sizeof(getit));
        scanf("%d", &N);

        for(int i = 1;i <= N;i++)
        {
            scanf("%d", &M);

            for(int j = 0;j < M;j++)
            {
                scanf("%d", &k);
                insert(i, k);
            }
        }

        bool ok = false;

        for(int i = 1;i <= N;i++)
        {
            if(getit[i]) continue;

            memset(cc, 0, sizeof(cc));
            cc[i]++;
            if(dfs(i))
            {
                ok = true;

                break;
            }
        }

        printf("Case #%d: %s\n", c, (ok?"Yes":"No") );
    }
}
