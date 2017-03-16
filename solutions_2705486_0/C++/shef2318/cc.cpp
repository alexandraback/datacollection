#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cmath>
#include <set>
#include <map>
#include <string>
#include <string.h>
#include <iomanip>

#define X first
#define Y second
#define ll long long

using namespace std;

//const int n=3;
const int n=521196;
int len[530000];
char s[530000][25];
char g[5500];
int F, L, C;
int inf=1000000;
map<int, map<int, int> >dp;

inline void wat(int wh, int st)
{
       C=0;
       L=-inf;
       F=-inf;
       for (int i=0; i<len[wh]; i++)
       {
           if ( s[wh][i]!=g[st+i] )
           {
              if ( i-L<5 )
              {
                 C=inf;
                 return ;     
              }     
              C++;
              L=i+st;
              if ( C==1 )
                 F=i+st;
           } 
       }       
}
void solve(int nt)
{
     cin>>g;
     
     int l=strlen(g);
     dp.clear();
     for (int i=0; i<l; i++)
     {
         
         for (int z=-6; z<=i; z++)
             dp[i][z]=inf;    
         
     }
     for (int i=-1; i<0; i++)
         for (int j=-6; j<=-1; j++)
             dp[i][j]=0;
   
     for (int i=0; i<l; i++)
     {
         //cout<<"------"<<endl;
         //cout<<i<<endl;
         for (int j=1; j<=n; j++)
         {
             if ( i-len[j]+1>=0  )
             {
                wat(j, i-len[j]+1);    
                if ( C==inf )
                   continue;
                //cout<<s[j]<<" "<<L<<" "<<F<<" "<<C<<endl;
                if ( C==0 )
                {
                   for (int z=-5; z<=i-len[j]; z++)
                       dp[i][z]=min( dp[i][z], dp[i-len[j]][z] );     
                }
                else
                    for (int z=-5; z<=F-5; z++)
                        dp[i][L]=min( dp[i][L], dp[i-len[j]][z]+C );
             }    
         }  
       //  for (int j=-5; j<=i; j++)
       //      cout<<j<<" "<<dp[i][j]<<endl;  
     }
     int ans=inf;
     for (int i=-5; i<l; i++)
         ans=min(ans, dp[l-1][i]);
     cout<<"Case #"<<nt<<": "<<ans<<endl;
}
int main ()
{
    freopen("dict1.txt", "r", stdin);
    for (int i=1; i<=n; i++)
        scanf("%s", s[i]), len[i]=strlen(s[i]);
    
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int test;
    cin>>test;
    for (int i=1; i<=test; i++)
        solve(i);
    return 0;    
}
