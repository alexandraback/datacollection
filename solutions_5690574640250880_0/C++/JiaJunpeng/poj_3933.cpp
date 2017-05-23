#include <vector> 
#include <map> 
#include <set> 
#include <algorithm> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <cctype> 
#include <string> 
#include <cstring> 
#include <ctime> 
#include <string.h> 
using namespace std;
int r,c,m,tr;
char ans[100][100];
bool dp[55][55][2501];
bool no;
bool solve(int r,int c,int m)
{
     int i,j,s,p,q,nr,nc,nm,jmin,jmax;
     if(dp[r][c][m])
        return false;
     dp[r][c][m]=true;
     if(r>=0&&m==0)
        return true;
     if(r<=0)
        return false;
   // printf("r=%d,c=%d,m=%d\n",r,c,m);
     for(i=2;i<=c;i++)
     {
         if(r!=tr)
         {
            if(m-i>=0)
            {
               nr=r-1;
               nc=i;
               nm=m-i;
               jmax=jmin=tr-r;
            }
            else
               break;
         }
         else
         {
             if(m-2*i>=0)
             {
                 jmin=tr-r;
                 jmax=jmin+1;
                 nr=r-2;
                 nc=i;
                 nm=m-2*i;
             }
             else
                 break;
         }
         if(solve(nr,nc,nm))
         {
             for(j=jmin;j<=jmax;j++)
               for(s=0;s<i;s++)
               {
                  ans[j][s]='.';
               }
             return true;
         }
     }
     return false;
}
int main()
{
    freopen("debug\\input.txt","r",stdin);
    freopen("debug\\output.txt","w",stdout);
    int i,j,s,p,q,t,tst=0;
    scanf("%d",&t);
    while(t--)
    {
       tst++;
       memset(ans,0,sizeof(ans));
       memset(dp,false,sizeof(dp));
       scanf("%d%d%d",&r,&c,&m);
       tr=r;
       for(i=0;i<r;i++) 
         for(j=0;j<c;j++)
            ans[i][j]='*';
       m=r*c-m;
       printf("Case #%d:\n",tst);
       if(m==1)
       {
         ans[0][0]='c';
         for(i=0;i<r;i++) 
          puts(ans[i]);
       }
       else if(r>1&&c>1)
       {
         if(!solve(r,c,m))
            puts("Impossible");
         else
         {
            ans[0][0]='c';
            for(i=0;i<r;i++)
               puts(ans[i]);
         }
       }
       else
       {
           for(i=0;i<r&&m>0;i++)
             for(j=0;j<c&&m>0;j++)
             {
                 ans[i][j]='.';
                 m--;
             }
           ans[0][0]='c';
           for(i=0;i<r;i++)
              puts(ans[i]);
       }
    }
    return 0;
}
