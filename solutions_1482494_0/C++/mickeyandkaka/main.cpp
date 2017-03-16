#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef vector<int> VI;

#define clr(a,b)    (memset(a,b,sizeof(a)))
#define PB push_back
#define MP make_pair
#define SZ(v) (int)v.size()
#define ALL(c) c.begin(),c.end()
#define forn(i,s,t)   for(int i=s; i<=t; i++)
#define repv(i,v)   for(int i=0;i<(int)v.size();i++)
#define repi(it,c)  for(typeof(c.begin()) it=c.begin();it!=c.end();++it)

const int INF = 0x3f3f3f3f;
const double eps = 1E-8;

struct P
{
    int num,id;
    P() {}
    P(int a,int b)
    {
        num = a,id =b;
    }
};

bool operator <(const P& a,const P& b)
{
    return a.num > b.num;
}

priority_queue<P> lv1,lv2;

bool check1[1010],check2[1010];
int T;

struct st
{
    int a,b;
} p[1010];
int n;

int main()
{
    freopen("B-small-attempt4.in","r",stdin);
    freopen("out","w",stdout);

    int cas = 1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
            scanf("%d%d",&p[i].a,&p[i].b);

        while(!lv1.empty()) lv1.pop();
        while(!lv2.empty()) lv2.pop();

        for(int i=1; i<=n; i++)
            lv1.push(P(p[i].a,i));
        for(int i=1; i<=n; i++)
            lv2.push(P(p[i].b,i));

        //printf("debug\n");

        clr(check1,false);
        clr(check2,false);
        int cnt = 0;
        int step = 0;
        int cur = 0;

        while(1)
        {
            if(lv2.empty() )  break;

            P tmp = lv2.top();

            int require = tmp.num;
            if(check2[tmp.id] == true)
            {
                lv2.pop();
                continue;
            }

            if(cur >= require)
            {
                step++;

                if(check1[tmp.id] == true && check2[tmp.id] == false)
                    cur += 1;
                else if(check1[tmp.id] == false && check2[tmp.id] == false)
                    cur += 2;

                check2[tmp.id] = true;
                check1[tmp.id] = true;
                lv2.pop();
                cnt++;
            }
            else
            {
                if(lv1.empty()) break;

                P tmp2 = lv1.top();
                if(check1[tmp2.id] == true)
                {
                    lv1.pop();
                    continue;
                }

                int require2 = tmp2.num;
                if(cur >= require2)
                {
                    step++;
                    cur += 1;
                    check1[tmp2.id] = true;
                    lv1.pop();
                }
                else
                    break;
            }
        }

        if(cnt < n)
            printf("Case #%d: Too Bad\n",cas++);
        else
            printf("Case #%d: %d\n",cas++,step);
    }

    return 0;
}
