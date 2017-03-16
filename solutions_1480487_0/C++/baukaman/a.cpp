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
#include <cstring>

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
#define inf 1000000000
#define eps 1e-8

int n;

vector<double> get(vi v){
 
 int s=0;
 double nd;

 go(i,sz(v)) s+=v[i];

 double lo=0, hi=s, md;

 go(i,500){
  md=(lo+hi) / 2.0;
  double ac=0;
  
  go(i,n)
   {
     nd=(md-v[i])/s;
     if(nd<0) {lo=md; goto K;}
     ac+=nd;
   }
  if(ac<=1.0) hi=md;
  else lo=md;
  K:;
 }

 vector<double> ret;

 go(i,sz(v)) ret.pb((hi-v[i])/s);
 return ret;
}

double func(vi v,int pos){

 double s=0;
 go(i,n)
 s+=v[i];

 double lo=0, hi=1.0;

 go(i,500){
  double md=(lo+hi)/2;
  double ego=v[pos]+md*s;
  int ncnt=0;
  double ns=0;
  go(i,n)
  if(i!=pos && v[i]+eps<ego) ncnt++ ,ns+=v[i];
  
  double bst= ( ns + s*(1.0-md) ) / ncnt;

  if(ego >= bst+eps) hi=md;
  else lo=md;
 }
 
 //return (lo-v[pos])/n;
 return 100*hi;

}

void oku(){
  int T;
  cin>>T;
  double cnt;
  double t,w;
  go(ii,T){
   cin>>n;
   vi v;
   go(i,n) v.pb(0), cin>>v[i];
   printf("Case #%d: ",ii+1);
   go(i,n) printf("%.6f ",func(v,i));
   cout<<endl;


  }

}

int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
#endif

oku();

return 0;}