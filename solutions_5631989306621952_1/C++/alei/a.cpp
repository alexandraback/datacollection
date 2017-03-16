#include<bits/stdc++.h>
using namespace std;
typedef long long int uli;
int main(){
   freopen("al.in","r",stdin);
   freopen("al.out","w",stdout);
   int t;
   cin>>t;
   for(int tt=1;tt<=t;tt++){
      cerr<<tt<<endl;
      string s;
      cin>>s;        
      int n=s.size();
      string ans="";
      for(int i=0;i<n;i++){
         string a=string(1,s[i])+ans;
         string b=ans+string(1,s[i]);
         if(a>b)ans=a;
         else ans=b;
      }
      printf("Case #%d: %s\n",tt,ans.c_str());
   }
   return 0;
}
