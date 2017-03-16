

#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<bitset>

#include<algorithm>
#include<cmath>
using namespace std;


// Definitions

#define LLD long long int
#define PB push_back
#define MP make_pair
#define PII pair<int,int>
#define VI vector<int>
#define VL vector<LLD>
#define VII vector< vector<int> >
#define VLL vector< vector<LLD> >
#define VP vector< PII >
#define S(a) scanf("%lld",&a)
#define St string

// Main Code
LLD N;

void init()
{
   }


void DFS(VLL v , VL x)
{    
   stack<LLD> q;
   VL visited(N+1,0);
   
   q.push(1);
   LLD t;
   //visited[1]=1;
   
   while(!q.empty())
   {                VL vis(N+1,0);
                    while(!q.empty())
                    {
                                     t=q.top();
                                     //cout<<t<<endl;
                                     q.pop();
                                     vis[t]=1;
                                     visited[t]=1;
                                     for(LLD i = 1 ; i <= x[t] ; i++)
                                     {
                                        //cout<<t<<" "<<v[t][i]<<" "<<x[t];
                                        //system("pause");
                                        if(vis[ v[t][i] ])
                                        {
                                                    cout<<"Yes"<<endl;
                                                    return ;
                                        }
                                        
                                        else
                                        {
                                            vis[ v[t][i] ]=1;
                                            visited[ v[t][i] ]=1;
                                            q.push(v[t][i]);
                                        }
                                        
                                     }
                                    // if(!q.empty())
                                    // cout<<q.top();
                                     
                    }
                    
                    for( LLD i =1 ; i <=N ; i++)
                    {
                         if(!visited[i])
                         {
                                        q.push(i);                    
                                        break;
                                        }
                         }
   }
   
   cout<<"No"<<endl;                   
                                             
   
     
   return ;
   }

int main()
{
       init();
       LLD t;
       S(t);
       int cases=1;
       while(t--)
       {
                 S(N);
                 LLD M;
                 VLL v(N+1,N+1);
                 VL x(N+1);
                 for(LLD i = 1 ; i <= N ; i++ )
                 {
                         S(M);
                         x[i]=M;
                        // v[i].resize(M+1);
                         for( LLD j = 1 ; j <= M ; j++ )
                         {
                              S(v[i][j]);
                              }
                 }
                 
                 cout<<"Case #"<<cases++<<": ";
                 DFS(v,x);
                 
                                          
                 
                 
       }
   return 0;
}
