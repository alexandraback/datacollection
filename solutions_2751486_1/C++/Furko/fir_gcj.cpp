#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <map>
#include <string>

using namespace std;
#define forn(i,a,b) for(i=a;i<=b;++i)
#define ford(i,a,b) for(i=b;i>=a;--i)
long long ans=0;
int last,len,i,e,n,f,t;
string s;

bool bad(char q){
 if (q=='a' || q=='e' || q=='i' || q=='o' || q=='u') return true;
 return false;
}
int main(){
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  cin>>t;
  forn(e,1,t){
   cin>>s>>n;
   last=s.size()+1;
   len=s.size();
   f=0; ans=0;
   ford(i,0,len-1)
    {
        if (bad(s[i])) {
         f=0;
         if (last!=len+1) ans+=len-last+1;
         }
        else {
          f++;
          if (f>=n) {
              last=i+n;
          }
          if (last!=len+1) ans+=len-last+1;
        }
        
    }
   cout<<"Case #"<<e<<": ";
   cout<<ans<<endl; 
  }
}
