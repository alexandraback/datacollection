#include <iostream>
#include <cstdio>
#include <cstring>
#define M(x,y) memset(x,y,sizeof(x))
using namespace std;
struct NODE
{
    int to;
    int next;

};
NODE edge[1000000];
int head[2000];
int ie;
void adde(int a,int b)
{
    edge[ie].to=b;
    edge[ie].next=head[a];
    head[a]=ie++;
}
bool is[2000];
bool DFS(int now)
{
    int k;
//    cout << "now " << now << endl;
    for(k=head[now];k+1;k=edge[k].next)
    {
//        cout<<now << "==" <<  edge[k].to << endl;
        if(!is[edge[k].to])
        {
            is[edge[k].to]=true;
            if(!DFS(edge[k].to)) return false;
//            is[edge[k].to]=false;
        }
        else return false;
    }
    return true;
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int cas;
    scanf("%d",&cas);
    int ci;
    int n;
    int x;
    int i,j;
    int a;
    bool ans;
    for(ci=1;ci<=cas;ci++)
    {
        M(head,-1);
        ie=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&x);
            for(j=0;j<x;j++)
            {
                scanf("%d",&a);
                adde(i,a);
            }
        }
        ans=true;
        for(i=1;i<=n;i++)
        {
            M(is,0);
            is[i]=true;
            if(!DFS(i))
            {
                ans=false;
//                cout << i << endl;
                break;
            }
        }
        printf("Case #%d: ",ci);
        if(ans) printf("No\n");
        else printf("Yes\n");
    }
}
