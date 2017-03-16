#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

const int maxn=1000009;
double v[maxn];

int A,B;
void input()
{
    scanf("%d%d",&A,&B);
    for(int i=1; i<=A; ++i)
    {
        scanf("%lf",v+i);
    }
}
double slove()
{
    input();
    v[0]=1;
    double TMP=1;
    double ans=B+2;
    for(int i=0; i<=A; ++i)
    {
        TMP*=v[i];
        ans=min(ans,((A-i)*2+B-A+1)*TMP+(1-TMP)*((B+1)+(A-i)*2+B-A+1));
    }
    return ans;
}
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("out","w",stdout);
    int t;
    scanf("%d",&t);
    int cot=1;
    while(t--)
    {
        printf("Case #%d: %.6f\n",cot++,slove());
    }

    return 0;
}

