#include <vector>
#include <list>
#include <map>
#include <set>
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
#include <fstream>
#include <math.h>
#include <time.h>
#include <string.h>

#define vi vector<int>
#define vpii vector< pair<int,int> >
#define pii pair<int,int>
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define sqr(x) ((x)*(x))
#define FOR(i,n) for (int i = 0; i < int(n); i++)
#define READ(v,n) { FOR(i,n){int x;cin>>x;v.pb(x);} }
#define FREAD(v,n) { FOR(i,n){int x;in>>x;v.pb(x);} }
#define WRITE(v) "";FOR(i,sz(v))cout<<v[i]<<" ";cout
#define FWRITE(v) "";FOR(i,sz(v))out<<v[i]<<" ";out
#define gmin(a,b) { if (b < a) a = b; }
#define gmax(a,b) { if (b > a) a = b; }
#define pb push_back
#define ppb pop_back
#define OUT(k,i) { out<<"Case #"<<k+1<<": "<<i<<endl; }
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main(void){
  ifstream in("in.in");
  ofstream out("out.out");
  
  int T;
  in>>T;
  
  FOR(t,T){
    string s;
    in>>s;
    int n;
    in>>n;
    vi v;
    
    int number=0;
    FOR(i,s.length()){
      if(s[i]!='e' && s[i]!='a' && s[i]!='i' && s[i]!='o' && s[i]!='u'){number++;}else{number=0;}
      //out<<number<<endl;
      if(number>=n){v.pb(i-n+1);}//cout<<"."<<i<<"."<<endl;}                
    }         
    ull p=0;
    
    FOR(i,s.length()){
      int j=0;
      while(j<sz(v) && v[j]<i){j++;}
      if(j==sz(v)){}else{
        p+=s.length()-v[j]-n+1;                  
        //cout<<i<<","<<","<<v[j]<<s.length()-v[j]-n+1<<endl;
      }
    }
    
    OUT(t,p);
  
             
  }
  
  system("PAUSE");
  return 0;
}
