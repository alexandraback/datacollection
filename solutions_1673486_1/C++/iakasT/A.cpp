#include <cstdio> 
#include <cstdlib> 
#include <cmath> 
#include <climits> 
#include <cfloat> 
#include <map> 
#include <utility> 
#include <set> 
#include <iostream> 
#include <memory> 
#include <string> 
#include <vector> 
#include <algorithm> 
#include <functional> 
#include <sstream> 
#include <complex> 
#include <stack> 
#include <queue> 
#include <cassert>
#include <fstream>
using namespace std; 
#define REP(i,b,n) for(int i=b;i<n;i++) 
#define rep(i,n)      REP(i,0,n) 
#define pb push_back  
#define mp make_pair 
#define ALL(C)   (C).begin(),(C).end() 
#define fe(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr != (c).end();itr++)
template<class T> void vp(T &a,int p){rep(i,p)cout << a[i]<<" ";cout << endl;}  
typedef complex<double>P; 
typedef long long ll; 
typedef unsigned long long ull; 
typedef pair<int,int> pii; 
const ll mod = 1000000009;

double correct(int n,vector<double> &a){//[0,n-1] (全部合ってる
  double ret = 1;
  rep(i,n)ret *= a[i];
  return ret;
}

//そのまま打ち続ける
double pattern1(int a,int b,vector<double> & in){
  double ret = 0;
  double p = correct(a,in);
  double op = 1-p;
  ret = p * (b-a + 1) + op * (b - a + 1 + b + 1);
  //cout <<"pattern1 " << ret << endl;
  return ret;
}

//i文字目までを消して、そのまま打ち続ける。
double pattern2(int a,int b,vector<double> & in){
  double ret = 10*b;
  double p = 1;
  rep(i,a){
    double num = a-i;
    //double p = correct(i,in);
    if (i != 0)p *= in[i-1];
    double op = 1-p;
    double tmp = p * (num + num + b-a + 1) + op * (num + num + b-a + 1 + b + 1);
    //cout << "key plcae " << num  <<" " << tmp << " " << p << endl;
    ret = min(ret,tmp);
  }
  return ret;
}

main(){
  int te,tc=1;
  cin>>te;
  while(te--){
    int a,b;
    cin>>a>>b;
    vector<double> in(a);
    rep(i,a)cin>>in[i];
    double ans = b+2;//1回エンターを押して残りは打ちなおす
    //cout <<"pattern 0 " << ans << endl;
    double ans2 = pattern1(a,b,in);
    double ans3 = pattern2(a,b,in);
    //cout <<ans <<" " << ans2 <<" " << ans3 << endl;
    ans = min(ans,min(ans2,ans3));
    printf("Case #%d: %.10lf\n",tc++,ans);
    //cout <<"Case #" << tc++ << ": " <<endl;
  }
  return 0;
}

