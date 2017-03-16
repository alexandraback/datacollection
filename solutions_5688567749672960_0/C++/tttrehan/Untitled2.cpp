#include<bits/stdc++.h>
using namespace std;
const int MX = 1e6 + 10 ;

bool vis[MX] ;
int rev(int number)
{
	int reverse=0;
	while(number!=0)
   {
      reverse = reverse * 10;
      reverse = reverse + number%10;
      number = number/10;
   }
   return reverse;

}
int main()
{
    freopen("input.txt", "r", stdin);
	 freopen("output.txt", "w", stdout);
     int  z,t;
     	scanf("%d",&t);
     for(z=1;z<=t;z++)
     {
         int n;
         int res=0 ;

         	scanf("%d",&n);
         queue< pair<int,int> > q;
       for(int i=0;i<=n;i++)
       vis[i]=0;
         q.push(make_pair(1,1));
         vis[1]=1;
         while(!q.empty())
         {
             int now=q.front().first ;
             int c=q.front().second ;
             q.pop();
             if(now==n)
             {
                 res=c;
                 break;
             }
             if(now+1<=n&&!vis[now+1])
             {
                 vis[now+1]=1;
                 q.push(make_pair(now+1,c+1));
             }
             int rv=rev(now);
             if(rv<=n&&!vis[rv])
             {
                 vis[rv]=1;
                 q.push(make_pair(rv,c+1));
             }
         }
         printf("Case #%d: %d\n",z,res);
 
 
     }
 
 
    return 0;
}

