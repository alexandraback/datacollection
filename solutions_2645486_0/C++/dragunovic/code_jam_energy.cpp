#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string.h>

using namespace std;

int t,e,r,n;
int mx=0;
int dp[12][12];
vector <int> v;

void hitung(string z)
{
     int jml=0;
     for (int i=0; i<n; i++)
     {
         int k=z[i]-48;
         jml+=(k*v[i]);
     }
     
     if (mx < jml) mx=jml;
 }

void brute (int p, string s, int rem, int h)
{
     char ck=s[p];
     if (p==n) 
     {
          if (h>mx) mx=h;
//          cout << h << " " << s << endl;
     }
     else
     {
//         cout << p << " " << s << " " << rem << " " << h <<endl;
     for (int i=0; i<=rem; i++)
     {
         char c=48+i;
         int k = (rem-i) + r;
         
         if (k>e) k=e;
         

         s[p]=c;
         
         int th=h+(i*v[p]);
         
         if (dp[p+1][k] ==-1)
         {
             dp[p+1][k]=th;
             brute (p+1,s,k,th);
         }
         else
         if (dp[p+1][k] < th) {
             dp[p+1][k]=th;
             brute (p+1,s,k,th);
         }
         
         s[p]=ck;
         
     }
     
     }
}

int main ()
{
    scanf("%d",&t);
    for (int z=1; z<=t; z++)
    {
        v.clear();
        memset(dp,-1,sizeof(dp));
        scanf("%d%d%d",&e,&r,&n);
        
        int bil;
        for (int i=0; i<n; i++)
        {
            scanf("%d",&bil);
            v.push_back(bil);
        }
        
//        cout << e << " " << r << " " << n << " " << v.size() << endl;
        
        string s="";
        for (int i=0; i<=n; i++) s+='0';
        
        mx=0;
        
//        cout << s << endl;
        brute (0,s,e,0);
        
        printf("Case #%d: %d\n",z,mx);
        
    }
    
//    system("pause");
    return 0;
}
