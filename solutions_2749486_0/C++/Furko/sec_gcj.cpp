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
int e,t,x,y,xx,yy,i;
int main(){
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  cin>>t;
  
  forn(e,1,t){
   cin>>x>>y;
   xx=0;
   yy=0;
   cout<<"Case #"<<e<<": ";
   forn(i,1,50000) {
     if (xx==x && yy==y) break;
     if (xx!=x) {
        if (x<0) {
          cout<<"EW";       
          xx--;
        }        
        else {
         cout<<"WE";
         xx++;
        } 
     }
     else {
        if (y<0) {
          yy--;
          cout<<"NS";
        }   
        else {
         cout<<"SN";
         yy++;
        } 
     }
   }
   cout<<endl;
  }
  return 0;
}
