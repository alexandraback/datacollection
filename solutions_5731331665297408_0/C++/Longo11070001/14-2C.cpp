#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int OUTBOUND = 1;
const int RETURN = 0;

struct Edge{
    int to,next;
}edge[3000];

int N,M;
int head[60];
int ne;
char postal[300];
bool check[60],use[3000];
char table[60][7];
int pointer;
char currentpostal[300];

void addedge(int x,int y)
{
    edge[ne].to=y;
    edge[ne].next=head[x];
    head[x]=ne++;
    edge[ne].to=x;
    edge[ne].next=head[y];
    head[y]=ne++;
}

void dfs(int index,int status)
{
    
    int i,record = 1;
    if(status == OUTBOUND){
        record = 0;
        for(i=pointer;i<pointer+5;i++)
            currentpostal[i]=table[index][i-pointer];
        pointer+=5;
        check[index] = true;
    
    if(pointer == 5*N)
    {
        int flag = 1;
        for(i=0;i<5*N;i++){
            if(currentpostal[i]<postal[i])
            {
                flag = 0;
                break;
            }
            else if(currentpostal[i]>postal[i])
            {
                break;
            }
        } 
        if(!flag)
        {
            memcpy(postal,currentpostal,sizeof(postal));
        }
        check[index] = false;
        pointer -= 5;
        return;
    }
    }
    for(i=head[index];i!=-1;i=edge[i].next)
    {
        if(check[edge[i].to]){
            if(use[i^1] && !use[i]){
                use[i]=true;                  
                dfs(edge[i].to,RETURN);
                use[i]=false;
            }
        }
        else{
            use[i]=true;
            dfs(edge[i].to,OUTBOUND);
            use[i]=false;
        }
        
    }
    if(!record){
        check[index] = false;
        pointer -= 5;
    }
}

int main()
{
    int T,kase,i,x,y;
    scanf("%d",&T);
    for(kase = 1; kase <= T; kase++)
    {
        ne = 0;
        pointer = 0;
        memset(head,-1,sizeof(head));
        memset(check,false,sizeof(check));
        memset(use,false,sizeof(use));
        scanf("%d%d",&N,&M);
        for(i=1;i<=N;i++)
            scanf("%s",table[i]);
        for(i=0;i<M;i++)
        {
            scanf("%d%d",&x,&y);
            addedge(x,y);
        }
        for(i=0;i<5*N;i++)
            postal[i]='9';
        for(i=1;i<=N;i++)
            dfs(i,OUTBOUND);
        cout<<"Case #"<<kase<<": ";
        for(i=0;i<5*N;i++)
            printf("%c",postal[i]);
        cout<<endl;
    }
    return 0;
}
