#include<stdio.h>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;

struct acti
{
    int v;
    int c;
    int cap;
    bool operator < (const acti &a) const
    {
        return v < a.v;
    }
};

priority_queue<acti> pq;
int e, r, n;
int v[100000];

int main()
{
    freopen("B-small-attempt4.in", "r", stdin);
    freopen("Bsmall.out", "w", stdout);
    int T;
    long long ans;
    int cas, i, cur;

    scanf("%d", &T);
    for (cas=1; cas<=T; cas++)
    {
        scanf("%d%d%d", &e, &r, &n);
        for (i=0; i<n; i++)
        {
            scanf("%d", &v[i]);
        }
        while (!pq.empty()) pq.pop();
        ans = 0;
        for (i=n-1; i>=0; i--)
        {
            if (i==0) cur = e;
            else cur = min(e, r);
            int cap = e - cur;
            while (!pq.empty() && cur>0)
            {
                acti a = pq.top();
                if (a.v <= v[i]) break;
                pq.pop();
                int dif = min(a.cap - a.c, cur);
                cur -= dif;
                a.c += dif;
                if (a.c == a.cap)
                {
                    ans += a.c * (long long)a.v;
  //                  printf("%I64d\n", ans);
                }
                else pq.push(a);
            }
            if (cur == cap) ans += cur * (long long)e;
            else
            {
                acti a;
                a.v = v[i];
                a.c = cur;
                a.cap = cap;
                pq.push(a);
//                printf("%d %d\n", a.v, a.c);
            }
        }
        //printf("size = %d\n", pq.size());
        while (!pq.empty())
        {
            acti a = pq.top();
            ans += a.c * (long long)a.v;
            //printf("%I64d\n", ans);
            pq.pop();
        }
        printf("Case #%d: %I64d\n", cas, ans);
    }
    return 0;
}
/*
5
10 1 4
1 2 9 10

*/
