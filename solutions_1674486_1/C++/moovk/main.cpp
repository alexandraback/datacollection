#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>


#define CLR(x,y) memset(x,y,sizeof(x))
using namespace std;
struct Data
{
    int to;
    int next;

};
Data edge[1000000];
int head[2000];
int id;
void adde(int a,int b)
{
    edge[id].to=b;
    edge[id].next=head[a];
    head[a]=id++;
}
bool is[2000];
bool DFS(int now)
{
    int k;
    for(k=head[now]; k+1; k=edge[k].next)
    {
        if(!is[edge[k].to])
        {
            is[edge[k].to]=1;
            if(!DFS(edge[k].to)) return 0;
        }
        else return 0;
    }
    return 1;
}
void work()
{
    int cas;
    scanf("%d",&cas);
    int ci;
    int n;
    int x;
    int i,j;
    int a;


    bool ans;
    for(ci=1; ci<=cas; ci++)
    {
        CLR(head,-1);
        id=0;
        scanf("%d",&n);
        for(i=1; i<=n; i++)
        {
            scanf("%d",&x);
            for(j=0; j<x; j++)
            {
                scanf("%d",&a);
                adde(i,a);
            }
        }
        ans=1;
        for(i=1; i<=n; i++)
        {
            CLR(is,0);
            is[i]=1;
            if(!DFS(i))
            {
                ans=0;

                break;
            }
        }
        printf("Case #%d: ",ci);
        if(ans) printf("No\n");
        else printf("Yes\n");
    }
}
int main()
{
    freopen("in","r",stdin);
    freopen("out.txt","w",stdout);
    work();
    return 0;

}

void f()
{
    cout << "sdjkflasdfj " << endl;
}

void KKKKKKK()
{
    int asldkfjasdfasdfasdfasdf;
}



int KKKK()
{
    double asdfasdfadf;
}
