#include<bits/stdc++.h>
using namespace std;

int main()
{
  freopen("C-small-attempt1.in","r",stdin);
    freopen("outputEEE444555.o","w",stdout);
   int t,n,i,ca=1;
   cin >> t;
   map<string,int>mp1,mp2;
   map<string,int>mp3;
   while(t--)
   {
       cin >> n;
       string s1[1005],s2[1005];
       for(i=1; i<=n; i++)
       {
           cin >> s1[i] >> s2[i];
           mp1[s1[i]]++;
           mp2[s2[i]]++;
       }
       int cnt=0,sum=0;
       for(i=1; i<=n; i++)
       {
           if(mp1[s1[i]]>=2 && mp2[s2[i]]>=2)
           {
               if(mp3[s1[i]]==1) sum++;
               mp3[s1[i]]++;
               cnt++;
           }
       }

       cnt-=sum;
       mp1.clear();
       mp2.clear();
       printf("Case #%d: %d\n",ca++,cnt);
   }

}
