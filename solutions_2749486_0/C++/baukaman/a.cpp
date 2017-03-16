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


map<pair<int,int> ,int > m;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};


char fir[]={'N','S','E','W'};
int rir[]={1,0,3,2};

string calc(int x,int y){
 
 queue<int> qi;
 queue<string> qs;

 qi.push(0); qi.push(0); qi.push(1);
 qs.push("");
 m.clear();
 int cx,cy,st; string cs;
 int nx,ny;

 while(sz(qi)) {
  cx=qi.front(); qi.pop();
  cy=qi.front(); qi.pop();
  st=qi.front(); qi.pop();


  cs=qs.front(); qs.pop();

  cout<<cx<<" "<<cy<<endl;

  //if(abs(cx)>100 || abs(cy)>100) continue;

  //cout<<cx<<" "<<cy<<" "<<cs<<endl;

  if(cx==x && cy==y) {
    return cs;
  }

  go(dir,4) {
   nx=cx+st*dx[dir];
   ny=cy+st*dy[dir];
   if(!m.count(mp(nx,ny))){
     qi.push(nx); qi.push(ny); qi.push(st+1);
     qs.push(cs+fir[dir]);
   }
    
  }
 }

 return "";
}

string calc2(int x,int y){

 string ret="";
 string loc;

 if(y>0) {
   loc="SN";
   go(i,y) ret+=loc;
 }else{
   loc="NS";
   go(i,-y) ret+=loc;
 }

 if(x>0){
   loc="WE";
   go(i,x) ret+=loc;
 }else{
   loc="EW";
   go(i,-x) ret+=loc;
 }

 return ret;


}

void oku(){

int T;
cin>>T;
int x,y;

go3(cs,1,T+1){

 cin>>x>>y;
 printf("Case #%d: ",cs); cout<<calc2(x,y)<<endl;
 
}
 

}


int main(){
#ifndef ONLINE_JUDGE
freopen("in","r",stdin);
#endif

oku();

return 0;}