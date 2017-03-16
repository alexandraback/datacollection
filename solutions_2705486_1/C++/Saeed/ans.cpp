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

const int INF = 1<<25;

string s;

int dyna[5000][5];

struct trie{
  struct node{
    map<char,node*> children;
    bool end;
    node(){
      children.clear();
      end = false;
    }
    void add(string s){
      if (s.size() == 0)
	end = true;
      else{
	if (children.find(s[0]) == children.end())
	  children[s[0]] = new node();
	children[s[0]]->add(s.substr(1));
      }
    }

    void move(int index,int remaining,int th){
      if (end)
	dyna[index][remaining] = min(dyna[index][remaining],th);
      if (index > s.size())
	return;
      if (remaining == 0){
	for (map<char,node*> :: iterator i=children.begin();i!=children.end();i++)
	  if (i->first != s[index])
	    i->second->move(index+1,4,th+1);
	  else
	    i->second->move(index+1,0,th);
      }else
	if (children.find(s[index]) != children.end())
	  children[s[index]]->move(index+1,remaining-1,th);
      
    }

  }*root;
  trie(){
    root = new node();
  }
  void move(int index,int remaining,int th){
    root->move(index,remaining,th);
  }
  void add(string s){
    root->add(s);
  }
}tr;

void read_dict(){
  fstream fin("dict.txt");
  string t;
  while (fin>>t){
    tr.add(t);
  }
}

int main(){
  ios_base::sync_with_stdio(false) ;
  read_dict();
  int ttime;
  cin>>ttime;
  for (int ccount=1;ccount<=ttime;ccount++){
    cin>>s;
    for (int i=0;i<=s.size();i++)
      for (int j=0;j<=4;j++)
	dyna[i][j] = INF;
    dyna[0][0] = 0;
    for (int i=0;i<s.size();i++)
      for (int j=0;j<=4;j++)
	if (dyna[i][j] < INF)
	  tr.move(i,j,dyna[i][j]);
    int ans = INF;

    /*
    for (int i=0;i<=s.size();i++,cout<<endl)
      for (int j=0;j<=4;j++)
	cout<<dyna[i][j]<<' ';
    */
    for (int i=0;i<=4;i++)
      ans = min(ans,dyna[s.size()][i]);
    cout<<"Case #"<<ccount<<": "<<ans<<endl;
  }
}
