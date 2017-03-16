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

const int INF = 1<<25;

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

const int MAX_N = 100+20;

int dyna[MAX_N][MAX_N];

bool is_su(vector<int> s){
  return(s[2] - s[0] == 2);
}

vector<vector<int> > find(int s){
  int t = s/3;
  vector<vector<int> > results;
  for (int i=t-3;i<=t+3;i++)
    for (int j=t-3;j<=t+3;j++)
      for (int k=t-3;k<=t+3;k++) if (i+j+k == s){
	vector<int> temp;
	temp.push_back(i);
	temp.push_back(j);
	temp.push_back(k);
	sort(temp.begin(),temp.end());
	if (temp[2] - temp[0] <= 2 && temp[0] >= 0 && temp[2] <= 10)
	  results.push_back(temp);
      }
  return(results);
}

int main(){
  ios_base::sync_with_stdio(false) ;
  int ttime;
  cin>>ttime;
  for (int ccount=1;ccount<=ttime;ccount++){
    int n,s,p;
    cin>>n>>s>>p;

    for (int i=0;i<MAX_N;i++)
      for (int j=0;j<MAX_N;j++)
	dyna[i][j] = -INF;
    dyna[0][0] = 0;
    for (int i=0;i<n;i++){
      int t;
      cin>>t;
      vector<vector<int> > all = find(t);
//       cout<<t<<' '<<all<<endl;
//       for (int j=0;j<=n;j++)
// 	cout<<dyna[i][j]<<' ';
//       cout<<endl;
      for (int j=0;j<=n;j++)
	for (int k=0;k<all.size();k++){
	  if (is_su(all[k]) && j+1 <= n)
	    dyna[i+1][j+1] >?= dyna[i][j]+(all[k].back() >= p);
	  if (!is_su(all[k]))
	    dyna[i+1][j] >?= dyna[i][j]+(all[k].back() >= p);
	}
    }
    cout<<"Case #"<<ccount<<": "<<dyna[n][s]<<endl;
  }
}
