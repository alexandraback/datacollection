#include <cstdio>
#include <vector>
using namespace std;
vector<int> ord;
vector<int> key[201];
bool state[1<<21];
bool op[201];
int che;
int st[201];
int ty[201];
void rec(int n,int sta)
{
    if(state[sta])
        return;
    state[sta]=1;
    if(n==che)
    {
        ord.push_back(2000);
    }
    for(int i=1;i<=che;i++)
    {
        if(op[i]==1||st[ty[i]]==0)
            continue;
        op[i]=i;
        st[ty[i]]--;
        for(int j=0;j<key[i].size();j++)
            st[key[i][j]]++;
        rec(n+1,sta|(1<<(i-1)));
        st[ty[i]]++;
        for(int j=0;j<key[i].size();j++)
            st[key[i][j]]--;
        if(ord.size()!=0)
        {
            ord.push_back(i);
            return;
        }
        op[i]=0;
    }
    return;
}
int main()
{
    freopen("Tic.in","r",stdin);
    freopen("Whee.out","w",stdout);
    int t,tem;
    int k;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        printf("Case #%d: ",i);
        for(int j=0;j<(1<<21);j++)
            state[j]=0;
        for(int j=0;j<201;j++)
        {
            op[j]=0;
            key[j].clear();
            st[j]=0;
        }
        ord.clear();
        scanf("%d%d",&k,&che);
        for(int j=0;j<k;j++)
        {
            scanf("%d",&tem);
            st[tem]++;
        }
        for(int j=1;j<=che;j++)
        {
            scanf("%d%d",&ty[j],&k);
            for(int a=0;a<k;a++)
            {
                scanf("%d",&tem);
                key[j].push_back(tem);
            }
        }
        rec(0,0);
        if(ord.empty())
        {
            printf("IMPOSSIBLE\n");
            continue;
        }
        for(int i=ord.size()-1;i>0;i--)
            printf("%d ",ord[i]);
        printf("\n");
    }
}
