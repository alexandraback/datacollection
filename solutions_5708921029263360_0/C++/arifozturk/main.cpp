#include <cstdio>
#include <vector>
using namespace std;
int t,ja,p,lim,s;
vector<int>v;
int main()
{
    freopen ("in.in","r",stdin);
    freopen ("out.out","w",stdout);
    scanf("%d",&t);
    for(int xyz=1;xyz<=t;xyz++)
    {
        v.clear();
        scanf("%d%d%d%d",&ja,&p,&s,&lim);
        for(int i=1;i<=ja;i++)
        {
            for(int j=1;j<=p;j++)
            {
                if(i==j) continue;
                for(int k=1;k<=s;k++)
                {
                    if(i==k) continue;
                    if(k==j) continue;
                    v.push_back(i),v.push_back(j),v.push_back(k);
                }
            }
        }
        int limita=min(lim,s)-1;
        for(int i=1;i<=ja;i++)
        {
            for(int k=1;k<=limita;k++)
            {
                if(k==i)
                {
                    limita++;
                    if(limita>s) limita=p;
                    continue;
                }
                v.push_back(i),v.push_back(i),v.push_back(k);
            }
        }
        limita=min(lim,p)-1;
        for(int i=1;i<=ja;i++)
        {
            v.push_back(i),v.push_back(i),v.push_back(i);
            for(int k=1;k<=limita;k++)
            {
                if(k==i)
                {
                    limita++;
                    if(limita>p) limita=p;
                    continue;
                }
                v.push_back(i),v.push_back(k),v.push_back(i);
            }
        }
        limita=min(lim,ja)-1;
        for(int i=1;i<=p;i++)
        {
            for(int j=1;j<=limita;j++)
            {
                if(j==i)
                {
                    limita++;
                    if(limita>ja) limita=ja;
                    continue;
                }
                v.push_back(j),v.push_back(i),v.push_back(i);
            }
        }
        int mar=v.size();
        printf("Case #%d: %d\n",xyz,mar/3);
        for(int i=0;i<mar;i+=3)
        {
            printf("%d %d %d\n",v[i],v[i+1],v[i+2]);
        }
    }
}
