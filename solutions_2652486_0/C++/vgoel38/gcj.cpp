#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#include<iostream>
#include<stack>

using namespace std;

int main()
{
    
   //freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
   
   int t;
   scanf("%d",&t);
   
   int i,j,r,m,n,k;
   scanf("%d%d%d%d",&r,&n,&m,&k);
   int arr[10];
   
   
   printf("Case #1: \n");
   
   for(i=0;i<r;i++)
   {
                   int count=0;
                   for(j=0;j<k;j++)
                   scanf("%d",&arr[j]);
                   int flag=0;
                   
                   vector<vector<int> > v(200);
                   
                   for(j=0;j<k;j++)
                   {
                                   if(arr[j]!=1) {flag=1;break;}
                   }
                   if(flag==0)
                                   {
                                                 //printf("dg");
                                                if(count==0)
                                                {printf("222\n"); count=1;}
                                                else if(count==1) 
                                                {printf("234\n"); count=2;}
                                                else if(count==2) 
                                                {printf("334\n"); count=3;}
                                                else if(count==3) 
                                                {printf("333\n"); count=4;}
                                                else if(count==4) 
                                                {printf("444\n"); count=0;}
                                   }
                   else
                   {
                   for(j=0;j<k;j++)
                   {
                                   
                                   while(arr[j]!=1)
                                   {
                                                   if(5<=m && arr[j]%5==0)
                                                   {v[arr[j]].push_back(5); arr[j]/=5;}
                                                   if(4<=m &&arr[j]%4==0)
                                                   {v[arr[j]].push_back(4); arr[j]/=4;}
                                                   if(2<=m && arr[j]%2==0)
                                                   {v[arr[j]].push_back(2); arr[j]/=2;}
                                                   
                                                   if(3<=m && arr[j]%3==0)
                                                   {v[arr[j]].push_back(3); arr[j]/=3;}
                                                   
                                   }
                                   
                                   
                                  
                   }
                   int siz=0,index=0;
                   int brr[6];
                   for(j=0;j<=5;j++) brr[j]=0;
                   
                   
                   int y;
                   for(j=0;j<200;j++)
                   for(y=0;y<v[j].size();y++)
                   {brr[v[j][y]]=1;}
                   
                   j=0;
                   while(j!=n)
                   {
                              y=2;
                              for(y=2;y<=5;y++)
                              {
                                               if(j==n) break;
                                               else if(brr[y]==1) {printf("%d",y);j++;}
                              }
                   }
                   
                    printf("\n");
                    }
   } 
   
   
   return 0;
}
