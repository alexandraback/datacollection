#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int maxn = 1024;

struct Node
{
    int a, b, level;
};

bool operator <(const Node & A, const Node & B ) { return A.b<B.b; }

Node A[maxn];
int n, ans, cas;

int main()
{
    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);
    scanf("%d",&cas);
    for (int run = 1; run<=cas; run++ )
    {
        scanf("%d",&n);
        for (int i = 0; i<n; i++ )
        {
            scanf("%d%d",&A[i].a,&A[i].b);
            A[i].level = 0;
        }
        sort(A, A+n);
        ans = 0;
        int stars = 0, count;
        bool ok;
        while (1)
        {
            count = 0;
            ok = 0;
            for (int i = 0; i<n; i++ )
                if (A[i].level<2 && A[i].b<=stars)
                {
                    ok = 1;
                    stars += 2-A[i].level;
                    A[i].level = 2;
                    ++ans;
                }
                else if (A[i].level==2) ++count;
            if (count==n) { ok = 1; break; }
            if (ok) continue;
            ok = 0;
            for (int i = n-1; i>=0; i-- )
                if (A[i].level==0 && A[i].a<=stars)
                {
                    ok = 1;
                    ++stars;
                    A[i].level = 1;
                    ++ans;
                    break;
                }
            if (!ok) break;
        }
        printf("Case #%d: ",run);
        if (!ok) printf("Too Bad\n");
        else printf("%d\n",ans);
    }
    return 0;
}
