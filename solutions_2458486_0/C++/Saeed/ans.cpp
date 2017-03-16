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

struct box{
  int index;
  int open;
  vector<int> property;
  bool operator < (const box &s)const{
    return(index < s.index);
  }
};

int cal(map<int,int> keys,vector<box> boxes){
  vector<vector<bool> > reach(boxes.size(),vector<bool>(boxes.size()));
  for (int i=0;i<boxes.size();i++)
    for (int j=0;j<boxes.size();j++)
      if (binary_search(boxes[i].property.begin(),
			boxes[i].property.end(),
			boxes[j].open))
	reach[i][j] = true;
  for (int i=0;i<reach.size();i++)
    for (int j=0;j<reach.size();j++)
      for (int k=0;k<reach.size();k++)
	if (reach[j][i] && reach[i][k])
	  reach[j][k] = true;
  for (int i=0;i<boxes.size();i++)
    if (keys[boxes[i].open] > 0 && reach[i][i])
      return(i);
  vector<bool> h(boxes.size(),true);
  for (int i=0;i<reach.size();i++)
    for (int j=0;j<reach.size();j++)
      if (reach[i][j])
	h[j] = false;
  for (int i=0;i<boxes.size();i++)
    if (keys[boxes[i].open] > 0 && h[i])
      return(i);
  return(-1);
}

bool can(map<int,int> keys,vector<box> boxes){
  while (boxes.size()){
    int next = cal(keys,boxes);
    if (next == -1)
      return(false);
    else{
      for (int i=0;i<boxes[next].property.size();i++)
	keys[boxes[next].property[i]]++;
      keys[boxes[next].open]--;
      swap(boxes[next],boxes.back());
      boxes.pop_back();
    }
  }
  return(true);
}

int main(){
  ios_base::sync_with_stdio(false) ;
  int ttime;
  cin>>ttime;
  for (int ccount=1;ccount<=ttime;ccount++){
    int m,n;
    cin>>m>>n;
    map<int,int> keys;
    vector<box> boxes(n);
    for (int i=1;i<=m;i++){
      int temp;
      cin>>temp;
      keys[temp]++;
    }
    for (int i=0;i<boxes.size();i++){
      cin>>boxes[i].open;
      boxes[i].index = i+1;
      int temp;
      cin>>temp;
      for (int j=1;j<=temp;j++){
	int q;
	cin>>q;
	boxes[i].property.push_back(q);
      }
    }
    for (int i=0;i<boxes.size();i++)
      sort(boxes[i].property.begin(),boxes[i].property.end());
    vector<int> ans;
    if (can(keys,boxes)){
      while (boxes.size()){
	sort(boxes.begin(),boxes.end());
	int ind = -1;
	for (int i=0;i<boxes.size() && ind == -1;i++)
	  if (keys[boxes[i].open] > 0){
	    map<int,int> q = keys;
	    q[boxes[i].open]--;
	    for (int j=0;j<boxes[i].property.size();j++)
	      q[boxes[i].property[j]]++;
	    vector<box> t = boxes;
	    swap(t[i],t.back());
	    t.pop_back();
	    if (can(q,t)){
	      ind = boxes[i].index;
	      keys = q;
	      boxes = t;
	    }
	  }
	ans.push_back(ind);
      }
    }
    cout<<"Case #"<<ccount<<": ";
    if (ans.size() == n){
      for (int i=0;i<ans.size();i++)
	cout<<ans[i]<<' ';
      cout<<endl;
    }else
      cout<<"IMPOSSIBLE"<<endl;
  }
}
