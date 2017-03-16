#include<iostream>
#include<string.h>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;

struct node{
       int num,next;
       };

node e[100011];
int taile;
int edge[1011];

void add(int xx,int yy)
{
    e[taile].num=yy;
    e[taile].next=edge[xx];
    edge[xx]=taile++;
}


int t;
int n;
int f[1011];

int cir_ans;
int max_link[1011];
int ans;


int bfs(int now,int fa,int step)
{
    //cout<<now<<' '<<fa<<' '<<step<<"    %%%"<<endl;
    int i;
    int ans=1;
    for(i=edge[now];i!=-1;i=e[i].next)
    {
        if(e[i].num!=fa)
        {
            ans=max(ans,1+bfs(e[i].num,now,step+1));
        }
    }
    return ans;
}


int main()
{
    int i,j,k,times;
    int now;
    int tmp;
    freopen("C-large.in","r",stdin);
    freopen("ans.out","w",stdout);
    
    cin>>t;
    for(times=1;times<=t;times++)
    {
        cin>>n;
        
        
        memset(edge,-1,sizeof(edge));
        taile=1;
        for(i=1;i<=n;i++)
        {
            cin>>f[i];
            add(f[i],i);
        }
        
        cir_ans=0;
        memset(max_link,0,sizeof(max_link));
        
        bool used[1011];
        
        for(i=1;i<=n;i++)
        {
            memset(used,0,sizeof(used));
            now=i;k=0;
            while(used[now]==0)
            {
                used[now]=1;
                k++;
                now=f[now];
            }
            if(now==i)
            {
                cir_ans=max(cir_ans,k);
            }
        }
        
        
        //for(i=1;i<=n;i++)
        //{
        //    cout<<f[i]<<' ';
        //}
        //cout<<endl;
        
        tmp=0;
        for(i=1;i<=n;i++)
        {
            for(j=i+1;j<=n;j++)
            {
                //cout<<i<<' '<<j<<endl;
                if(f[i]==j && f[j]==i)
                {
                    tmp+=bfs(i,j,0)+bfs(j,i,0);
                }
            }
        }
        ans=max(tmp,cir_ans);
        
        
        cout<<"Case #"<<times<<": "<<ans<<endl;
    }
    
    
    
    return 0;
}
