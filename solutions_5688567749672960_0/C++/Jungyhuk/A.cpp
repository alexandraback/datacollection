#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <cctype>
#include <algorithm>
#include <queue>
#define maxn 1000005

using namespace std;

int test,ttest,n,f[maxn];

bool flag[maxn];

queue<int>q;

void init()
 {
     scanf("%d\n",&n);
 }

void bfs()
{
    int i,j,k;
    q.push(1);f[1]=1;flag[1]=true;
    while (!q.empty())
    {
        j=q.front();
        if ((!f[j+1] || f[j]+1<f[j+1]) && j<=999999)
        {
            f[j+1]=f[j]+1;
            if (!flag[j+1])
            {
                q.push(j+1);flag[j+1]=true;
            }
        }
        int t = 0;
        int s = j;
        while (s)
        {
          t=t*10+s%10;
          s/=10;
        }
        if (!f[t] || f[j]+1<f[t])
        {
            f[t]=f[j]+1;
            if (!flag[t])
            {
                q.push(t);flag[t]=true;
            }
        }
        flag[j]=false;q.pop();
    }
}

void work()
 {
    printf("Case #%d: %d\n",ttest,f[n]);
 }

int main()
 {
     freopen("A.in","r",stdin);
     freopen("A.out","w",stdout);
     scanf("%d\n",&test);
     bfs();
     for (ttest=1;ttest<=test;ttest++)
     {
      init();
      work();
     }
     return 0;
 }
