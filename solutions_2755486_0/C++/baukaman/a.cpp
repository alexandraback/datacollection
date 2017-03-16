#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
 
using namespace std;
 
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
typedef long long ll;
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define mp make_pair                    
#define go(i,n) for(int i=0;i<n;i++)
#define go3(i,j,n) for(int i=j;i<n;i++)

vvi data;
map<double,int> str;

int work(){

 int n = sz(data);


 int di,wi,ei,si;
 int ret=0;


 go(day,100000){

 int nd=-1;

   go(i,n){
     
     di=data[i][0];
     wi=data[i][1];
     ei=data[i][2];
     si=data[i][3];

     if(day!=di) continue;

     //cout<<di<<" "<<wi<<" "<<ei<<" "<<si<<endl;

     for(double j=wi;j<=ei;j+=0.5)
     if(str[j]<si) {
      ret++;

      //cout<<"oops at"<<" "<<j<<" "<<str[j]<<endl<<endl;
      break;
     }
   }

   go(i,n){
     di=data[i][0];
     wi=data[i][1];
     ei=data[i][2];
     si=data[i][3];

     if(day!=di) continue;

     for(double j=wi;j<=ei;j+=0.5)
     if(str[j]<si) {
       str[j]=si;
       //cout<<"oops at"<<" "<<j<<" "<<str[j]<<endl<<endl;

     }
   }
 }

 return ret;

}

void print(){

  go(i,sz(data)){
  go(j,sz(data[i]))
   cout<<data[i][j]<<" ";
   cout<<endl;
  }
 
}


void oku(){

int T;
int N;
int di,ni,wi,ei,si,ddi,dpi,dsi;
cin>>T;



go3(cs,1,T+1){

 cin>>N;
 data.clear();
 str.clear();
 vi cum;

 go(i,N) {
  cin>>di>>ni>>wi>>ei>>si>>ddi>>dpi>>dsi;
  go(j,ni){
    cum.clear();
    cum.pb(di);
    cum.pb(wi);
    cum.pb(ei);
    cum.pb(si);
    di+=ddi;
    wi+=dpi;
    ei+=dpi;
    si+=dsi;
    data.pb(cum);
  }
 }

 printf("Case #%d: ",cs);  cout<<work()<<endl;  

}


}

int main(){
#ifndef ONLINE_JUDGE
freopen("in","r",stdin);
#endif

oku();

return 0;}