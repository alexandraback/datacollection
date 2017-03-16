#include <string>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <functional>
#include <stack>
#include <set>
#include <queue>
#include <cmath>
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

typedef long long ll;
const double eps = 1e-6;
const int maxint = -1u>>2;

int n,m;
int num[60];

bool e[60][60];

stack<int> s;

int ans[60];
bool visit[60];

int pt[60];

void check()
{
    int tmp[60];
    for(int i=n;i>=1;i--)
    {
        tmp[i] = s.top();
        s.pop();
    }
//    for(int i=1;i<=n;i++)
//    {
//        printf("tmp[i]:%d %d\n",i, tmp[i]);
//    }

    bool les = false;
    for(int i=1;i<=n;i++)
    {
        if(num[tmp[i]] < num[ans[i]] || ans[i] == -1)
        {
//            printf("i:%d %d %d\n",i, tmp[i], ans[i]);
//            printf("%d %d\n", num[tmp[i]], num[ans[i]]);
            les = true;
            break;
        }
        else if(num[tmp[i]] > num[ans[i]])
        {
            break;
        }
    }

    if(les)
    {
        for(int i=1;i<=n;i++)
        {
            ans[i] = tmp[i];
        }
    }
}

void doit2()
{
    while(!s.empty())   s.pop();

    stack<int> s2;
    while(!s2.empty()) s2.pop();

//    for(int i=1;i<=n;i++)printf("%d ", pt[i]);printf("\n");

    s.push(pt[1]);
    s2.push(pt[1]);
    for(int i=2;i<=n;i++)
    {
        bool found = false;
        while(1)
        {
            if(s2.empty())
            {
                break;
            }
            int top = s2.top();
//            printf("top:%d , pt[i]:%d e:%d\n", top, pt[i],e[top][pt[i]]);
            if(e[top][pt[i]])
            {
                found = true;
                s2.push(pt[i]);
                s.push(pt[i]);
                break;
            }
            else
            {
                s2.pop();
            }
        }
        if(found == false)
        {
            return ;
        }
    }
//    printf("before check()\n");
    check();
}

void doit(int pos)
{
    if(pos > n)
    {
        doit2();
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        if(!visit[i])
        {
            visit[i] = true;
            pt[pos] = i;
            doit(pos+1);
            visit[i] = false;
        }
    }
}

int main()
{
    freopen("in.txt","r", stdin);
    freopen("out.txt", "w", stdout);
    int T;
    scanf("%d",&T);
    for(int cas =1 ;cas <= T;cas++)
    {
        memset(ans, -1, sizeof(ans));
        memset(e,false, sizeof(e));
        memset(visit, false, sizeof(visit));
        scanf("%d%d",&n,&m);

        while(!s.empty())   s.pop();

        for(int i=1;i<=n;i++)
        {
            scanf("%d", &num[i]);
        }
        for(int i=1;i<=m;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            e[a][b] = e[b][a] = true;
        }

//        for(int i=1;i<=n;i++){for(int j=1;j<=n;j++)printf("%d ", e[i][j]);printf("\n");}

        doit(1);


        printf("Case #%d: ",cas);
        for(int i=1;i<=n;i++)
        {
            printf("%d", num[ans[i]]);
        }
        printf("\n");
    }


    return 0;
}

