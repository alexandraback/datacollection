#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
int num[234];
map<int,int>h;
vector<int>g;
int main()
{
    freopen("c.in","r",stdin);
    freopen("c.out","w",stdout);
int T;
scanf("%d",&T);
for(int C=1;C<=T;C++)
{
    h.clear();
    g.clear();
    int n;
    scanf("%d",&n);
    int sum=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&num[i]);
    }
    int M=1<<n;
    printf("Case #%d:\n",C);
    int f=0;
    for(int i=0;i<M;i++)
    {
        int tmp=0;
        for(int j=0;j<n;j++)
        {
            int t=1<<j;
            if((t&i)==t)
            tmp+=num[j];
        }
        g.clear();
        if(h[tmp]!=0)
        {
            f=1;
            for(int k=0;k<n;k++)
            {
                int t=1<<k;
                if((t&h[tmp])==t)
                g.push_back(num[k]);
            }
            for(int d=0;d<g.size();d++)
            printf("%d%c",g[d],d==g.size()-1?'\n':' ');
            g.clear();
            for(int k=0;k<n;k++)
            {
                int t=1<<k;
                if((t&i)==t)
                g.push_back(num[k]);
            }
            for(int d=0;d<g.size();d++)
            printf("%d%c",g[d],d==g.size()-1?'\n':' ');
            break;
        }
        else
        {
            h[tmp]=i;
        }
    }
    if(f==0)
    printf("Impossible\n");
}

    return 0;
}
