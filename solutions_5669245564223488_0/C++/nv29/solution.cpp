#include<iostream>
#include<cstring>
#include <stdio.h>

#define mod 1000000007

 
using namespace std;
 
 
int adj[27][27],coun[27],vis[27];
int fact[108];
 
int dfs(int node)
{
   vis[node]=1;
    int j;
    int ret=fact[coun[node]];
for(j=0;j<27;j++) {
    if(adj[node][j]&&!vis[node])
    ret=ret*dfs(j);
}

  return ret;
}
 
 
int main()
{
    int t,i,j,n;
    int test;

 
     scanf("%d",&t);
     fact[0]=1;
      test=1;
               for(i=1;i<=100;i++) {
                   fact[i] = fact[i-1]*i;
               }
    for (test = 1; test <= t; test++) {
       
       memset(adj,0,sizeof(adj));
       for (i = 0; i < 27; i++) {
           coun[i] = 0;
       }
      
       scanf("%d",&n);

       int flag=1;

       string s[n+9];

       int index[27];

       for (i = 0; i < 27; i++) {
           index[i] = 0;
       }


       for (i = 0; i < 27; i++) {
           vis[i] = 0;
       }
     
       for(i=0;i<n;i++) {
           cin>>s[i];
           int st=s[i][0]-'a';
           int check=0;
           for(j=1;j<s[i].length();j++) {
               int val=s[i][j]-'a';
               if(val==st)
                   continue;
               check=1;
               
               adj[st][val]++;
               index[val]++;
               if(adj[st][val]>1)
                   flag=0;
               st=val;
           }
       
       if(!check)
           coun[st]++;
       }
 
       for(i=0;i<26;i++) {
           int c=0;
           for(j=0;j<26;j++) {
               if(i==j)
                   continue;
               if(adj[i][j])
                   c++;
           }
           if(c>1)
              flag=0;
       }
 
       for(i=0;i<26;i++) {
           int c=0;
           for(j=0;j<26;j++) {
               if(adj[i][j])
               c++;
           }

           int g=0;
           if(c!=0&&index[i]!=0)
               g=1;
 
           if(coun[i]&&g)
               flag=0;
        }

       if(!flag)
           printf("Case #%d: 0\n",test);
       else {
           int ans=1;
           int c=0;
           for(i=0;i<26;i++) {
               if(vis[i]||index[i])
                   continue;
               int zz=0;
               if(coun[i])
               zz=1;
 
               for(j=0;j<26;j++) {
                   if(adj[i][j])
                   zz=1;
               }
               if(!zz)
                   continue;
               int z=dfs(i);
               ans = ans*z;
               c++;
            }

            ans = (ans * fact[c]) % mod;
            printf("Case #%d: %d\n", test, ans);
        }
}
         return 0;
}
