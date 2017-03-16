#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <string>
#include <queue>
#define MAXN 12
#define INF 1000000000
#define eps 1e-6
using namespace std;
int N,x;
double D[MAXN],H[MAXN],M[MAXN];
struct BIKE
{
    double p,m;
}tmp;
vector<BIKE>b;
int process()
{
    if(b.size()==1) return 0;
    if(b[0].m<b[1].m) swap(b[0],b[1]);
    double s=b[0].m*(360.0-b[0].p)/360.0;
    double f=b[1].m*(360.0-b[1].p)/360.0;
    if(b[0].m==b[1].m) return 0;
    if(b[0].p>b[1].p)
    {
        if(s-eps <f+b[1].m) return 0;
        else return 1;
    }
    else
    {
        if(f+b[1].m>s-eps) return 0;
        else return 1;
    }
}
int main()
{
    freopen("C-small-1-attempt1.in","r",stdin);
    freopen("C-small-1-attempt1.out","w",stdout);
    int Case=1,T;
    scanf("%d",&T);
    //ini();
    while(T--)
    {
        scanf("%d",&N);
        for(int i=0;i<N;++i)
        {
            scanf("%lf%lf%lf",&D[i],&H[i],&M[i]);
            for(int j=0;j<H[i];++j)
            {
                tmp.p=D[i];
                tmp.m=M[i]+j;
                b.push_back(tmp);
            }
        }
        printf("Case #%d: %d\n",Case++,process());
        b.clear();
    }
    return 0;
}
