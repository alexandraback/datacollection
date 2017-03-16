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


bool isCons(char c){
 if(c=='a' || c=='e' || c=='o' || c=='u' || c=='i') return false;
 return true;

}

int calc(string s,int n){
 
 int m = sz(s);
 int ret=0;
 string w;
 int b=-1;
 int cur=0;

 go3(len,1,m+1){
  for(int i=0;i+len<=m;i++)
   {
     w=s.substr(i,len);
     cur=0;
     b=-1;
     go(j,sz(w))
     if(isCons(w[j])){
      cur++;
      b=max(b,cur);
     } else cur=0;

    if(b>=n) {
     ret++;
    }
     
   }
 }
  return ret;


}

void oku(){

int T;
cin>>T;
string s;
int n;

go3(cs,1,T+1){
 cin>>s>>n;
 printf("Case #%d: %d\n",cs,calc(s,n));

}



}

int main(){
#ifndef ONLINE_JUDGE
freopen("in","r",stdin);
#endif

oku();

return 0;}