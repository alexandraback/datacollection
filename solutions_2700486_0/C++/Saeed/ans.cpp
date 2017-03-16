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

const int MAX_N = 2000+200;

double d[MAX_N][MAX_N];

int main(){
  ios_base::sync_with_stdio(false) ;
  cout<<fixed;
  cout.precision(10);

  d[0][0] = 1;

  for (int i=1;i<=2000;i++)
    for (int j=0;j<=i;j++)
      if (j == 0)
	d[i][j] = d[i-1][j]/2;
      else
	d[i][j] = (d[i-1][j]+d[i-1][j-1])/2;

  for (int i=1;i<=2000;i++)
    for (int j=1;j<=i;j++)
      d[i][j]+=d[i][j-1];

  int ttime;
  cin>>ttime;
  for (int ccount=1;ccount<=ttime;ccount++){
    cout<<"Case #"<<ccount<<": ";
    int x,y,n;
    cin>>n>>x>>y;
    if (n == 0){
      cout<<0<<endl;
      continue;
    }
    int d = (abs(x)+y)/2+1;
    int D = 0,total = 0;
    while (total + 4*D + 1 <= n){
      total+=4*D+1;
      D++;
    }
    D++;
    //cout<<"hi "<<d<<' '<<D<<' '<<n-total<<endl;
    if (D > d){
      cout<<1<<endl;
      continue;
    }
    if (D < d){
      cout<<0<<endl;
      continue;
    }

    if (x==0){
      cout<<0<<endl;
      continue;
    }

    if (y >= n-total){
      cout<<0<<endl;
      continue;
    }

    if (n-total > 2*(d-1)+y){
      cout<<1<<endl;
      continue;
    }

    cout<<1-::d[n-total][y]<<endl;

  }

}
