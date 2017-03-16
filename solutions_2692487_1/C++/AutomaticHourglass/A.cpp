#include <string>
#include <map>
#include <math.h>
#include <sstream>
#include <time.h>
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
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define fx first
#define sx second

typedef pair<int,int> ii;
typedef vector<int> vec;
typedef vector<ii> vecp;
typedef long long int lli;
typedef unsigned long long int ulli;

struct mypair_comp{
  bool operator()(const ii &l, const ii &r){
    return l.fx<r.fx;
  }
};


/*int dyn(int e, int n, int R, int N, int E)
{
  if(n==N) return 0;
  int t1;
  if(res.count(ii(E,n))==0)
  {
    int maxx=dyn(min(E,e+R),n+1,R,N,E);
    for (int i = 1; i <= e; ++i)
    {
      int temp=dyn(min(E,e-i+R),n+1,R,N,E)+i*values[n];
      if(temp>maxx)
      {
        maxx=temp;
        t1=i;
      }
    }
    res[ii(e,n)]=maxx;
    //cout<<n<<"==="<<t1<<"==="<<maxx<<endl;
    return maxx;
  }
  else return res[ii(e,n)];
}*/

int log(float n)
{
  int count=0;
  while(n>1)
  {
    n/=2;
    ++count;
  }
  return count;
}

int func(int A, vec vall)
{
  cout<<A<<"***"<<vall.size()<<endl;
  if(A==1) return vall.size();
  //cout<<A<<endl;
  if(vall.size()==0) return 0;
  vec::iterator it=vall.begin();
  while(*it<A && it!=vall.end())
  {
    A+=*it;
    ++it;
  }
  if(it== vall.end()) return 0;
  vall.erase(vall.begin(),it);
  if(vall.size()<=1) return vall.size();
  else
  {
    int temp=func(2*A-1,vall)+1;
    if(temp<vall.size()) return temp;
    return vall.size();
  }
}

int main()
{
  ifstream input;
  string file="A-large";
  string filein=file+".in";
  string fileout=file+".out";
  input.open(filein.c_str(),ios::in);
  ofstream out;
  out.open(fileout.c_str(),ios::out);

  int count;
  input>>count;


  vec values;
  
  for (int i = 0; i < count; ++i)
  {
    int A,N;
    input>>A>>N;
    values.clear();

    for (int j = 0; j < N; ++j)
    {
      int temp;
      input>>temp;
      values.push_back(temp);
    }

    sort(values.begin(),values.end());
    int tt=func(A,values);
    cout<<tt<<endl;
    //printing the output
    out<<"Case #"<<i+1<<": ";
    out<<tt;
    if(i<count-1) out<<endl;
  }
  //cout<<log(2.0);

  return 0;
}




















