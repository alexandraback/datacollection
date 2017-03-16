#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#include<iostream>
#include<stack>

using namespace std;
int e,r,n;
int arr[20];
int ans;
int x;
void func(int e,int r,int v,int i)
{
    if(i==n)
    {
              if(v>ans) ans=v;
              return;
    }
    int j;
    for(j=0;j<=e;j++)
    {
                    func((j+r)>x?x:(j+r),r,v+(e-j)*arr[i],i+1);
    }
}

int main()
{
    
   //freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
   
   int i,j,test;
   
   scanf("%d",&test);
   for(i=1;i<=test;i++)
   {
                      scanf("%d%d%d",&e,&r,&n);
                      x=e;ans=0;
                       for(j=0;j<n;j++) scanf("%d",&arr[j]);
                       
                       func(e,r,0,0);
                       printf("Case #%d: %d\n",i,ans);
   }
   
   return 0;
}
