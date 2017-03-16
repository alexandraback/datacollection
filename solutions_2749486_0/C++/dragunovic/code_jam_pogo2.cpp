#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <deque>
#include <queue>

using namespace std;

typedef struct {
    bool done;
    string s;
    
} tdata;
typedef pair <int,int> ii;

tdata dp[503][503];
int a,b;
int t;

void cari()
{
     ii px;
     queue <ii> q;
     px.first=250;
     px.second=250;
     q.push(px);
     

     while ((q.size() > 0))
     {
     int x,y;
     
     x=q.front().first;
     y=q.front().second;
//     if ((x==-90+100) && (y==-89+100)) cout << "YES\n" << endl;
     q.pop();
     
     int l=dp[x][y].s.length();
     
     if (l>500) break;
     
     if ((x+l+1 <=500) && (x+l+1 >=0))
     {
          if ((dp[x+l+1][y].done==false))
          {
              dp[x+l+1][y].done=true;
              dp[x+l+1][y].s=dp[x][y].s+'E';
              px.first = x+l+1;
              px.second = y;
              q.push(px);
          }
     } //cek
     
     if ((x-(l+1) <=500) && (x-(l+1) >=0))
     {
          if ((dp[x-(l+1)][y].done==false))
          {
              dp[x-(l+1)][y].done=true;
              dp[x-(l+1)][y].s=dp[x][y].s+'W';
              px.first = x-(l+1);
              px.second = y;
              q.push(px);
          }
     } //cek
     
     if ((y-(l+1) <=500) && (y-(l+1) >=0))
     {
          if ((dp[x][y-(l+1)].done==false))
          {
              dp[x][y-(l+1)].done=true;
              dp[x][y-(l+1)].s=dp[x][y].s+'S';
              px.first = x;
              px.second = y-(l+1);
              q.push(px);
          }
     }//cej
     
     if ((y+(l+1) <=500) && (y+(l+1) >=0))
     {
          if ((dp[x][y+(l+1)].done==false))
          {
              dp[x][y+(l+1)].done=true;
              dp[x][y+(l+1)].s=dp[x][y].s+'N';
              px.first = x;
              px.second = y+(l+1);
              q.push(px);
          }
     }
     }
 }

void reset()
{
     tdata dum;
    dum.done=false;
    dum.s="";
     for (int i=0; i<503; i++)
     {
         for (int j=0; j<503; j++)
         {
             dp[i][j]=dum;
         }
     }
     
 }

int main ()
{
    
    reset();
    dp[250][250].done=true;
    
    cari();
    
//    cout << dp[10][11].s << endl;
    
    scanf("%d",&t);
    
    
    for (int z=1; z<=t; z++)
    {
        scanf("%d%d",&a,&b);
        
        printf("Case #%d: ",z);
        cout << dp[a+250][b+250].s <<endl;
//        cout << dp[a+100][b+100].done << endl;
    }
    
    
    return 0;
}
