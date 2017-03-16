using namespace std;
#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
void dfs(int x,int y);
int dp[100][100],mat[100][100],flag,num;
int main()
{
 //   freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);
    int cases,i,j,x,val,tc,k;
    scanf("%d",&cases);tc=0;
    while(cases--)
    {
         tc++;
         scanf("%d",&num);
         for(i=0;i<=num;i++)
         for(j=0;j<=num;j++) {mat[i][j]=0;dp[i][j]=0;}
         
         for(i=1;i<=num;i++)
         {
              scanf("%d",&x);
              for(j=1;j<=x;j++)
              {
                   scanf("%d",&val);
                   mat[i][val]=1;
                 //  dp[i][val]+=1;
              }
         }
          
         for(i=1;i<=num;i++) dp[i][i]=1;
                      
         flag=0;
              
         for(i=1;i<=num;i++)
         {
              for(j=1;j<=num;j++)
              {
                   if(i==j) continue;
                   dfs(i,j);
                //   cout<<i<<" "<<j<<dp[i][j]<<endl;
                   if(flag) break;
              }
              if(flag) break;
         }
         
         if(flag) printf("Case #%d: Yes\n",tc);
         else printf("Case #%d: No\n",tc);
    }
    return 0;
}

void dfs(int x,int y)
{
     int i;
     if(dp[x][y]>0) return;
     
     for(i=1;i<=num;i++)
     {
          if(mat[x][i]==0) continue;
          dfs(i,y);
          if(dp[i][y]>1) {flag=1;return;}
          
          dp[x][y]+=dp[i][y];
          if(dp[x][y]>1) {flag=1;return;}
     }
}
