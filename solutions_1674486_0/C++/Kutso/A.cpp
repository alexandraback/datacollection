#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

vector <int> m[2000];
int a,l,n,j,k,fix[2000],IS[1002][1002],it;


bool DFS(int cur, int fin, int from)
{int i;
     if (cur==fin) return true;
     fix[cur] = 1;
     for (i=0; i<m[cur].size(); i++)
         if (!fix[m[cur][i]]) 
         {
            if (DFS(m[cur][i],fin,cur))
            {                                    
               IS[cur][m[cur][i]] = it;  
               return true;                                     
            }
         }
     return false;
}

void DFS2(int cur)
{int i;
     fix[cur] = 1;
     for (i=0; i<m[cur].size(); i++)
         if (!fix[m[cur][i]] && IS[cur][m[cur][i]]!=it) 
         {
          DFS2(m[cur][i]);
         }
}
int main()
{
    int t, tcnt = 0, Sum;
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int a,b,res;
    scanf("%d",&t);
    while (t--)
    {
         it =0;
         tcnt++;
         scanf("%d",&n);
         for (l=0; l<n; l++)
         {
             for (k=0; k<n; k++) IS[l][k] = 0;
             m[l].clear();
             }
             
         for (l=0; l<n; l++)
         {
             scanf("%d",&a);
             for (k=0; k<a; k++)
             {
                 scanf("%d",&b);
                 b--;
                 m[l].push_back(b);
             }
         }
         
         bool boo = 0;
         for (l=0; l<n; l++)
             for (k=0; k<n; k++)
                 if (l!=k)
                 {
                          it++;
                          for (j=0; j<n; j++) fix[j] = 0;
                          res = DFS(l,k,-1);
                          if (res)
                          {                        
                             for (j=0; j<n; j++) fix[j] = 0;
                             DFS2(l);
                             if (fix[k]) boo = 1;
                          }
                 }
         
         printf("Case #%d: ",tcnt);
         if (!boo) puts("No"); else puts("Yes");     
          
    }
}
