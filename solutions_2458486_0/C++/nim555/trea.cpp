#include<stdio.h>
#include<vector>
#include<iostream>
#include<stack>

using namespace std;
stack<int>answer;
int n;
int keyn[1000];
int chest[1000];
vector<int> key[1000];
vector<int> chestore[1000];
bool vis[1000];
void clea()
{for(int i=0;i<1000;i++)
        {
         keyn[i]=0;
         chest[i]=0;
         vis[i]=0;
         key[i].clear();
         chestore[i].clear();
        }
}
bool dfs(int ke,int door,int count)
{//cout<<keyn[1]<<keyn[2];
 keyn[ke]--;
 vis[door]=1;
 count++;
 answer.push(door);
for(int k=0;k<chestore[door].size();k++)
        {//cout<<chestore[door][k]<<door;
         keyn[chestore[door][k]]++;
        }
//cout<<keyn[1]<<keyn[2]<<count;
//cout<<"\n"<<answer.top();
 if(count==n)
             return 1;
 for(int i=1;i<=200;i++)
         {
          if(keyn[i]>0)
                       {
                        for(int j=0;j<key[i].size();j++)
                                {
                                 if(vis[key[i][j]]==0)
                                                      {
                                                       return dfs(i,key[i][j],count);
                                                      }
                                }
                       }
         }
 
 keyn[ke]++;
 vis[door]=0;
 count--;
 answer.pop();
 for(int k=0;k<chestore[door].size();k++)
        {
         keyn[chestore[door][k]]--;
        }

}


int main()
{
int t;
scanf("%d",&t);
int pico=0;
while(t--)
          {clea();
          pico++;
           int k;
           scanf("%d %d",&k,&n);
           for(int i=0;i<k;i++) 
                   {int sc;
                    scanf("%d",&sc);
                    keyn[sc]++;
                   }
          for(int i=1;i<=n;i++)
                  {
                   int sc;
                   scanf("%d",&sc);
                   chest[i]=sc;
                   key[sc].push_back(i);
                   
                   scanf("%d",&sc);
                   for(int j=0;j<sc;j++)
                           {
                            int sc1;
                            scanf("%d",&sc1);
                            chestore[i].push_back(sc1);
                           }
                  }
                  int i;
          for(i=1;i<=200;i++)
                  {
                   if(keyn[i]>0)
                               {int j;
                                for(j=0;j<key[i].size();j++)
                                        {//cout<<key[i][j];
                                         if(dfs(i,key[i][j],0))
                                                              break;
                                        }
                               if(j<key[i].size())
                                                  break;
                               }
                  }
          //cout<<answer.top();
          printf("Case #%d: ",pico);
          if(i<=200)
                    {//cout<<i;
                    int itr=0;
                    int ans[1000];
                     while(!answer.empty())
                                           {ans[itr]=answer.top();
                                            itr++;
                                            answer.pop();
                                           }
                    for(int f=itr-1;f>=0;f--)
                            printf("%d ",ans[f]);
                    printf("\n");
                    }
          else
              printf("IMPOSSIBLE\n");
          }
}
