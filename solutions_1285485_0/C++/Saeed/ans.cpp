#include <cstdio>
#include <iostream>
#include <cmath>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <complex>
#include <algorithm>
#include <functional>
#include <fstream>
#include <numeric>
#include <string>
#include <valarray>
#define int long long

using namespace std;

typedef pair<int,int> Pair;

template<class t>
ostream & operator << (ostream & tout,const vector<t> &s){
  tout<<'[';
  for (int i=0;i<s.size();i++)
    if (i+1 == s.size())
      tout<<s[i];
    else
      tout<<s[i]<<',';
  tout<<']';
  return(tout);
}

template<class a,class b>
ostream & operator << (ostream & tout,const pair<a,b> &c){
  return(tout<<'('<<c.first<<','<<c.second<<')');
}

template<class T> struct __set__print{
  __set__print(ostream& out) : tout(out), count(0) {}
  void operator() (T x) { 
    if (count > 0)
      tout<<',';
    tout<<x;
    ++count; 
  }
  ostream& tout;
  int count;
};

template<class T>
ostream & operator << (ostream & tout,const set<T> &s){
  tout<<'{';
  for_each(s.begin(),s.end(),__set__print<T>(tout));
  return(tout<<'}');
}

template<class T,class Q> struct print_map{
  print_map(ostream& out) : tout(out), count(0) {}
  void operator() (const pair<T,Q> &x) { 
    if (count > 0)
      tout<<',';
    tout<<'('<<x.first<<" => "<<x.second<<')';
    ++count; 
  }
  ostream& tout;
  int count;
};

template<class T,class Q>
ostream & operator << (ostream & tout,map<T,Q> s){
  tout<<'{';
  for_each(s.begin(),s.end(),print_map<T,Q>(tout));
  return(tout<<'}');
}

template<class T>
string to_string(T s){
  stringstream tin;
  tin<<s;
  string res;
  getline(tin,res);
  return(res);
}


template<class T>
vector<T> to_vector(T *s,int n){
  vector<T> result;
  for (int i=0;i<n;i++)
    result.push_back(s[i]);
  return(result);
}

// *********************************** MY CODE ***************************

int n,m,d;

int ch(int a,int start,int len){
  if (a < 0)
    if (a%2)
      return(start-2*len*(abs(a)/2)-start*2);
    else
      return(start-2*len*(abs(a)/2));
  else
    if (a%2)
      return(start+2*len*(abs(a)/2)+(len-start)*2);
    else
      return(start+2*len*(abs(a)/2));
}

Pair find(int a,int b,Pair place,int n,int m){
  return(Pair(ch(a,place.first,n),ch(b,place.second,m)));
}

#undef int
int main(){
#define int long long
  ios_base::sync_with_stdio(false) ;
  int ttime;
  cin>>ttime;
  for (int ccount=1;ccount<=ttime;ccount++){
    cin>>n>>m>>d;
    Pair place (0,0);
    for (int i=1;i<=n;i++)
      for (int j=1;j<=m;j++){
	char temp;
	cin>>temp;
	if (temp == 'X')
	  place = Pair(i*2-1-2,j*2-1-2);
      }
    set<Pair> all;
    for (int a=-200;a<=200;a++)
      for (int b=-200;b<=200;b++) if (a != 0 || b != 0){
	Pair where = find(a,b,place,(n-2)*2,(m-2)*2);
	if ((where.first-place.first)*(where.first-place.first)+
	    (where.second-place.second)*(where.second-place.second) <= 4*d*d){
	  int x = where.first-place.first;
	  int y = where.second-place.second;
	  int q = __gcd(abs(x),abs(y));
	  all.insert(Pair(x/q,y/q));
	}
      }
    cout<<"Case #"<<ccount<<": "<<all.size()<<endl;
  }
}
