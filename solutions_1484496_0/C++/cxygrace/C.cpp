#include<iostream>
#include<stdio.h>
#include<ctime>
#include<cstdlib>
using namespace std;
const int maxn = 500;
int dat[maxn], n;
int ansa[maxn], ansb[maxn], ca, cb;
bool dfsearch(int dep = 0, int nowa = 0, int nowb = 0)
{
     if (nowa == nowb && ca != 0 && cb != 0) return true;
     if (dep>=n) return false;
     int x = rand() % (abs(abs(nowb-nowa)-dat[dep])<2 ? 4 : abs(abs(nowb-nowa)-dat[dep]));
     int y = rand() % (nowa+nowb<2 ? 2 : nowa+nowb);
     if (x==0) if (dfsearch(dep+1, nowa, nowb)) return true;
     if (y>=nowa)
     {
        ansa[ca++] = dat[dep];
        if (dfsearch(dep+1, nowa+dat[dep], nowb)) return true;
        ca--;
     }
     ansb[cb++] = dat[dep];
     if (dfsearch(dep+1, nowa, nowb+dat[dep])) return true;
     cb--;
     if (y<nowa)
     {
        ansa[ca++] = dat[dep];
        if (dfsearch(dep+1, nowa+dat[dep], nowb)) return true;
        ca--;
     }
     if (x) if (dfsearch(dep+1, nowa, nowb)) return true;
     return false;
}
void init()
{
     scanf("%d", &n);
     for (int i=0; i<n; i++) scanf("%d", dat+i);
}
void work()
{
     ca = cb = 0;
     if (dfsearch())
     {
        printf("%d", ansa[0]);
        for (int i=1; i<ca; i++) printf(" %d", ansa[i]);
        printf("\n%d", ansb[0]);
        for (int i=1; i<cb; i++) printf(" %d", ansb[i]);
        printf("\n");
     }
     else printf("Impossible\n");
}
int main()
{
    srand(time(NULL));
    int test;
    scanf("%d", &test);
    for (int i=1; i<=test; i++)
    {
        init();
        printf("Case #%d:\n", i);
        work();
    }
    return 0;
}
