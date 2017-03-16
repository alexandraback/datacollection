#include<iostream>
#include <algorithm>

using namespace std;
// const int maxn=100;
// int cases,t,n,lim,turn,a[maxn],next[maxn],sum[maxn],vis[maxn];
// ll sum1[maxn],ans;

const int maxn=100;
// typedef long long ll;
int cases, t, nGooglers, nSurprising, point, sum[maxn], result;

void init()
{
     int i;
     scanf("%d%d%d",&nGooglers,&nSurprising,&point);
     for (i=0;i<nGooglers;i++) 
         scanf("%d",&sum[i]);
}

void work()
{
     int i;
     result = 0;
     std::sort(sum, sum + nGooglers);     
     for (i=0;i<nGooglers;i++) {
         if ((sum[i] < point) || (sum[i] <= 3 * (point - 2) + 1)) {
            continue;
            }
         if (float(sum[i])/3 > (point - 1)) {
            result = result + nGooglers - i;
            break;
            }
         if (nSurprising > 0) {
            nSurprising--;
            result++;               
            }
         }
}

void print()
{
     printf("Case #%d: %d\n",t+1,result);
}

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    for (scanf("%d",&cases),t=0;t<cases;t++)
    {
        init();
        work();
        print();
    }
    return 0;
}
