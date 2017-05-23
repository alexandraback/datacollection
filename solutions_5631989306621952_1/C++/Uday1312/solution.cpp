#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

   vector<char>v1,v2,v3;

   int i,j,k,l;
   string s,s1,s2,s3;
   int t,ts;

   cin>>ts;

   for(t=1;t<=ts;t++)
   {
       cin>>s;
       l=s.size();
       s3=s2=s1="";

       s2+=s[0];

       for(i=1;i<l;i++)
       {
           if(s[i]>=s2[0])
            s2=s[i]+s2;
           else
            s2=s2+s[i];
       }
     printf("Case #%d: ",t);
       cout<<s2<<endl;
   }
}
