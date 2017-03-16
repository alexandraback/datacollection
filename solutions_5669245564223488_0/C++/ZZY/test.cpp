#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
string s[11],ss;
int ans,a[11];
bool used[11],f[26];;
void dfs(int p,int n)
{
       int i;
       if (p>n)
       {
             ss="";
             for (i=1;i<=n;i++) ss+=s[a[i]];
             n=ss.length();
             memset(f,false,sizeof(f));
             f[ss[0]-'a']=true;
             for (i=1;i<n;i++)
               if (ss[i]!=ss[i-1])
               {
                      p=ss[i]-'a';
                      if (f[p]) return;
                      f[p]=true;
               }
             ans++; 
             return;
       }
       for (i=1;i<=n;i++)
         if (!used[i])
         {
               a[p]=i;
               used[i]=true;
               dfs(p+1,n);
               used[i]=false;
         }
}
int main()
{ 
       int T,cases,n,i;
       freopen("B-small-attempt0.in","r",stdin);
       freopen("output.txt","w",stdout);
       cin>>T;
       for (cases=1;cases<=T;cases++)
       { 
              cin>>n;
              for (i=1;i<=n;i++) cin>>s[i];
              memset(used,false,sizeof(used));
              ans=0;
              dfs(1,n);
              printf("Case #%d: %d\n",cases,ans);
       }
       return 0;
}
