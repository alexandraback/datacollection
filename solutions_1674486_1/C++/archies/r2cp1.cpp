#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<stack>
#define SSD(x) (scanf("%d",&x))
#define SSL(x) (scanf("%lld",&x))
#define SSF(x) (scanf("%f",&x))
#define SSS(x) (scanf("%s",x))
#define ABS(x) (x>0?x:-x)
using namespace std;
#define MOD 1000000007
struct node
{
    int flag;
    vector<int>lis;
};    
int main()
{
     int t,i,j;
     int ans;
     
     freopen("inp.in","r",stdin);
     freopen("output.txt","w+",stdout);
     scanf("%d",&t);
     int check[10000];
     int n,m;
     for(int t1=1;t1<=t;t1++)
     {
         node a[10000];
          SSD(n);
          for(i=1;i<=n;i++)
          {
              a[i].flag=0;
              SSD(m);
              int temp;
              for(j=0;j<m;j++)
              {
                  SSD(temp);
                  a[i].lis.push_back(temp);
              }
          }
          i=1;
          queue<int> pq;
          int flag=0;
          j=1;
          while(j<=n)
          {
               for(i=1;i<=n;i++) check[i]=0;
               pq.push(j);
               while(!pq.empty())
               {
                   int t=pq.front();
                   pq.pop();
                   for(int k=0;k<a[t].lis.size();k++)
                   {
                       pq.push(a[t].lis[k]);
                       if(!check[a[t].lis[k]]) check[a[t].lis[k]]++;
                       else {flag=1;goto x;}
                   }
               }
               j++;
               
           } 
           //if(!pq.empty()) cout<<"a";       
           x:;
           if(flag==1)         
             printf("Case #%d: Yes\n",t1);
             else
             printf("Case #%d: No\n",t1);
             
     }
     return 0;
}

