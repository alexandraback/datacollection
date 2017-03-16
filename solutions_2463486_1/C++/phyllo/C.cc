#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <fstream>
#include <queue>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;

class Bignum{
public:
  Bignum(){}
  Bignum(string s){
    for(int i=0;i<s.length();i++) d.push_front(s[i]-'0');
    normalize();
  }
  Bignum &normalize(){
    for(int i=d.size()-1;i>=0;i--){ if(d[i]!=0) break; d.pop_back(); }
    return *this;
  }
  int operator[](int i){ return i>=d.size()?0:d[i]; }
  int size(){ return normalize(),d.size(); }
  void toZero(){ d.clear(); d.push_front(0); }
  void toOne(){ d.clear(); d.push_front(1); }
  Bignum &inc(){ Bignum one("1"); return operator+=(one); }
  Bignum &operator+=(Bignum n){
    int l=max(size(),n.size());
    d.resize(l+1,0);
    for(int c=0,i=0;i<=l;i++) d[i]=(c=d[i]+n[i]+c/10)%10;
    return normalize();
  }
  Bignum &operator-=(Bignum n){
    //assert(size()>=n.size());
    for(int c=0,i=0;i<d.size();i++) d[i]=((c=d[i]-n[i]+(c-9)/10)+10)%10;
    return normalize();
  }
  Bignum &operator*=(int n){
    for(int i=0;i<15;i++) d.push_back(0);
    for(int c=0,i=0;i<d.size();i++) d[i]=(c=d[i]*n+c/10)%10;
    return normalize();
  }
  Bignum operator+(Bignum n){ return Bignum(*this)+=n; }
  Bignum operator-(Bignum n){ return Bignum(*this)-=n; }
  Bignum operator*(int n){ return Bignum(*this)*=n; }
  Bignum operator*(Bignum n){
    Bignum ret;
    int ka=size(),kb=n.size();
    ret.d.resize(ka+kb,0);
    for(int i=0;i<ka;i++) for(int c=0,j=0;j<=kb;j++) ret.d[i+j]=(c=ret.d[i+j]+d[i]*n[j]+c/10)%10;
    return ret.normalize();
  }
  Bignum &operator*=(Bignum n){ return (*this)=(*this)*n; }

  int div(int n){
    int c=0;
    for(int i=size()-1;i>=0;i--) d[i]=(c=c%n*10+d[i])/n;
    return c%n;
  }
  Bignum &operator<<=(int n){
    for(int i=0;i<n;i++) d.push_front(0);
    return normalize();
  }
  Bignum operator<<(int n){ return Bignum(*this)<<=n; }
  bool operator>(Bignum n){
    if(size()!=n.size()) return size()>n.size();
    for(int i=size()-1;i>=0;i--) if(d[i]!=n[i]) return d[i]>n[i];
    return false;
  }
  bool operator==(Bignum n){
    if(size()!=n.size()) return false;
    for(int i=0; i<size(); i++) if(d[i]!=n[i]) return false;
    return true;
  }
  deque<int> d;
};
ostream &operator<<(ostream &os, const Bignum &l)
{
  Bignum n=l;
  if (n.size()==0) os<<0;
  else for (int i=n.d.size()-1;i>=0;i--) os<<n.d[i];
  return os;
}


bool isFair(const Bignum& n){
  rep(i,n.d.size()/2){
    if(n.d[i] != n.d[n.d.size()-1-i]) return false;
  }
  return true;
}

int create_main(){
  cout << 1 << endl;
  cout << 4 << endl;
  cout << 9 << endl;
  
  queue<string> que;
  que.push("11");
  que.push("22");
  while(true){
    string st = que.front(); que.pop();
    if(st.length()>50) break;
    Bignum tmp(st);
    if(isFair(tmp)){
      Bignum tmptmp = tmp*tmp;
      if(isFair(tmptmp)){
        cout << tmp << endl;
      }
      
      if(st.length()%2==0){
        string tmp1 = st.substr(0, st.length()/2);
        string tmp2 = st.substr(st.length()/2, st.length()/2);
        string hoge1 = tmp1 + "0" + tmp2;
        string hoge2 = tmp1 + "1" + tmp2;
        string hoge3 = tmp1 + "2" + tmp2;
        
        if(isFair(Bignum(hoge1) * Bignum(hoge1))) que.push(hoge1);
        if(isFair(Bignum(hoge2) * Bignum(hoge2))) que.push(hoge2);
        if(isFair(Bignum(hoge3) * Bignum(hoge3))) que.push(hoge3);

      }else{
        string tmp1 = st.substr(0, st.length()/2+1);
        string tmp2 = tmp1; reverse(ALLOF(tmp2));
        string hoge = tmp1 + tmp2;

        if(isFair(Bignum(hoge) * Bignum(hoge))) que.push(hoge);
      }
    }
  }

  cout << "100000000000000000000000000000000000000000000000000" << endl;
  return 0;
}


vector<Bignum> ans;

void readdata(){
  ifstream ifs("out5");
  string str;

  while(ifs >> str){
    Bignum tmp(str);
    ans.push_back(tmp*tmp);
  }
}

int calc(Bignum nn){
  //cout << ":" << nn << endl;

  int mid;
  int l = 0, r = ans.size()-1;
  while(l<r){
    mid = (l+r)/2;
    if(nn>ans[mid]) l = mid+1; else r = mid;
  }

  for(int i=mid-2; i<mid+3; i++){
    if(i<0 || i+1>=ans.size()) continue;
    if((nn>ans[i]||nn==ans[i]) && ans[i+1]>nn){
      //cout << i << endl;
      return i;
    }
  }
  return mid;
}

int solve(Bignum A, Bignum B){
  A -= Bignum("1");
  return calc(B) - calc(A);
}

int main(){
  //create_main();
  //return 0;
  
  readdata();
  
  int T;
  cin >> T;
  
  rep(t,T){
    string A, B;
    cin >> A >> B;
    cout << "Case #" << t+1 << ": " << solve(A, B) << endl;
  }
  
  return 0;
}
