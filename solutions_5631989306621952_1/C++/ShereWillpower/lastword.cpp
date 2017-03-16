#include<bits/stdc++.h>
using namespace std;

int main()
 {

   freopen("A-large.in","r",stdin);
     freopen("output.txt","w",stdout);
   int t;
   cin>>t;


   int p;
   for(p=1;p<=t;p++)
     {

       string s;
       cin>>s;

       string ans="";
       int l=s.size();
       int i;

       char ch;
       for(i=0;i<l;i++)
        {
           ch=s[i];
           if(ans=="")
             ans+=ch;
           else if(ans[0]>ch)
               ans=ans+ch;
               else
               ans=ch+ans;
        }
        cout<<"Case #"<<p<<": "<<ans<<endl;
    }
 }
