#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<map>
#include<set>
#include<deque>
#include<bitset>
#define ll __int64
#define inf 0x7FFFFFFF
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
int node[55];
vector<int>V[55];
int pai[55];
int flag[55][55];
int record[55];
int once[55];
int bfs(int from,int to)
{
    queue<pair<int,vector<int> > >Q;
    vector<int>P;
    Q.push(make_pair(from,P));
    int allNum=0;
    while(!Q.empty())
    {
        allNum++;
        if(allNum>=100) break;
        pair<int,vector<int> > now=Q.front();
        Q.pop();
        for(int i=0;i<V[now.first].size();i++)
        {
            if(flag[now.first][V[now.first][i]]==0){
            if(V[now.first][i]==to)
            {
                vector<int>get=now.second;
                get.push_back(now.first);
                get.push_back(V[now.first][i]);

                int panpan=0;
                for(int j=0;j<get.size();j+=2)
                {
                    if(flag[get[j+1]][get[j]]==0)
                    {
                        once[get[j+1]]++;
                        if(once[get[j+1]]>1)
                        {
                            panpan=1;
                            break;
                        }
                    }
                }
                //cout<<"hey"<<endl;
                if(panpan==1) continue;

                for(int j=0;j<get.size();j+=2)
                {
                    flag[get[j]][get[j+1]]=1;
                }
                return 1;
            }
            if(record[V[now.first][i]]==1)
            {
                vector<int>get=now.second;
                get.push_back(now.first);
                get.push_back(V[now.first][i]);
                Q.push(make_pair(V[now.first][i],get));
            }}
        }
    }
    return -1;
}
int out[55];
int main()
{
    int i,j,k;
    int n,m,t;
    freopen("C-small-attempt1.in","r",stdin);freopen("C-output.txt","w",stdout);
    scanf("%d",&t);for(int tcase=1;tcase<=t;tcase++)
    //while(scanf("%d",&n)!=EOF)
    {
        scanf("%d%d",&n,&m);
        memset(out,0,sizeof(out));
        for(i=0;i<=n;i++)
        {
            V[i].clear();
        }
        for(i=1;i<=n;i++)
        {
            scanf("%d",&node[i]);
        }
        for(i=1;i<=m;i++)
        {
            int from,to;
            scanf("%d%d",&from,&to);
            V[from].push_back(to);
            V[to].push_back(from);
        }
    for(i=0;i<=52;i++)
    {
        pai[i]=i;
    }
        do
        {
            memset(once,0,sizeof(once));
            memset(flag,0,sizeof(flag));
            memset(record,0,sizeof(record));
            int judge=0;
            for(i=2;i<=n;i++)
            {
                int get=bfs(pai[i-1],pai[i]);
                record[pai[i-1]]=1;
                record[pai[i]]=1;
                if(get==-1) {judge=1;break;}
            }
            if(judge==0)
            {
                //success
                if(out[1]==0)
                {
                    for(i=1;i<=n;i++)
                    {
                        out[i]=pai[i];
                    }
                }
                else
                {
                    int pan=0;
                    for(i=1;i<=n;i++)
                    {
                        if(node[out[i]]<node[pai[i]])
                        {
                            pan=-1;
                            break;
                        }
                        if(node[out[i]]>node[pai[i]])
                        {
                            pan=1;
                            break;
                        }
                    }
                    if(pan==1)
                    {
                        for(i=1;i<=n;i++)
                        {
                            out[i]=pai[i];
                        }
                    }
                }
            }
        }while(next_permutation(pai+1,pai+n+1));
        printf("Case #%d: ",tcase);
        for(i=1;i<=n;i++)
        {
            printf("%d",node[out[i]]);
        }
        printf("\n");
    }
    fclose(stdin);    fclose(stdout);
}
