#include <cstdlib>
#include <iostream>
#include <vector>
#include <sstream>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <math.h>

#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define sqr(x) ((x)*(x))
#define FOR(i,n) for (int i = 0; i < int(n); i++)
#define READ(v,n) { FOR(i,n){int x;cin>>x;v.pb(x);} }
#define WRITE(v) "";FOR(i,sz(v))cout<<v[i]<<" ";cout
#define FWRITE(v) "";FOR(i,sz(v))out<<v[i]<<" ";out
#define gmin(a,b) { if (b < a) a = b; }
#define gmax(a,b) { if (b > a) a = b; }
#define pb push_back
#define ppb pop_back
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main(void){
  
  ifstream in("in.in");
  ofstream out("out.out");

  int T, R, N, M, K;
  in>>T>>R>>N>>M>>K;
  out<<"Case #1:"<<endl;
  FOR(r,R){
    vi v;
    vi res;
    vi c(11,0);
    FOR(k,K){int x;in>>x;v.pb(x);}
    FOR(i,sz(v)){
      FOR(j,9){
        if(v[i]%(j+1)==0){c[j+1]++;}                
      }             
    }
    int n=N;
    vi v2=v;
    vi c2=c;
    int pet=0;
    int sedm=0;
    while(n){        //cout<<WRITE(v2)<<","<<WRITE(c2)<<endl;
      int add=0;
      if(((pet==0 && c[5]>0) || c2[5]>K/3) && 5<=M){add=5;pet=1;}else   
      if(((sedm==0 && c[7]>0) || c2[7]>K/3) && 7<=M){add=7;sedm=1;}else   
      if(c2[8]>K/3 && 8<=M){add=8;}else   
      if(c2[4]>K/3 && 4<=M){add=4;}else       
      if(c2[9]>K/3 && 9<=M){add=9;}else
      if(c2[6]>K/3 && 6<=M){add=6;}else
      if(c2[3]>K/3 && 3<=M){add=3;}else
      if(c2[2]>K/3 && 2<=M){add=2;}else{
        add=2;
      }
      //cout<<n<<" "<<add<<endl;
      int cut=0;
      res.pb(add);
      FOR(i,sz(v2)){
        if(v2[i]%add==0 && cut<K){v2[i]/=add;cut++;}              
      }
      FOR(j,9){c2[j+1]=0;}
      FOR(i,sz(v2)){
        FOR(j,9){
          if(v2[i]%(j+1)==0){c2[j+1]++;}                
        }             
      }

        
      n--;
    }
    cout<<WRITE(res)<<endl;
    out<<FWRITE(res)<<endl;
  }
  
  
  system("PAUSE");
  return 0;
}
