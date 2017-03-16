#include<stdio.h>
#include<vector>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define _P q[st].point
#define _EP q[end].point

int T,n,ch,m,x,st,end,u[1005];

struct node
{
    int point;
}q[100000];

int main()
{
    int i,j,k,l;
    freopen("2.in","r",stdin);
    freopen("2.txt","w",stdout);
    vector<int> p[60][1001];
    scanf("%d",&T);
    for(l=1;l<=T;l++)
    {
        scanf("%d",&n);
        ch=0;
        for(i=1;i<=n;i++)
        {
            
            scanf("%d",&m);
            for(j=1;j<=m;j++)
            {
                scanf("%d",&x);
                p[l][i].push_back(x);
            }
        }
        for(j=1;j<=n;j++)
        {
            for(k=1;k<=n;k++)u[k]=0;
            st=0;
            _P=j;
            end=1;
            u[_P]=1;
            for(;st<end;st++)
            {
    //            printf("[%d]",_P);
                for(i=0;p[l][_P].begin()+i<p[l][_P].end();i++)
                {
                    if(u[p[l][_P][i]])
                    {
                        ch=1;
                        break;
                    }else{
                        u[p[l][_P][i]]=1;
                        _EP=p[l][_P][i];
                        end++;
                    }
                }
            }
        }
        printf("Case #%d: ",l);
        if(ch)printf("Yes\n");
        else printf("No\n");
    }
    
    scanf(" ");
    return 0;
}
