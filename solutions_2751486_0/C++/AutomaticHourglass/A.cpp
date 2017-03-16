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

int CountC(string inp)
{
  int ret=0;
  for (int i = 0; i < inp.size(); ++i)
  {
    if(inp[i]!='a' && inp[i]!='e' && inp[i]!='i' && inp[i]!='o' && inp[i]!='u')
    {
      ++ret;
    }
  }
  return ret;
}

vec Calculate(string input, int n)
{
  vec ret;
  int t=0;
  cout<<input.size()<<endl;
  t=CountC(input.substr(0,n));
  if(t==n) ret.push_back(n-1);
  for (int i = n; i < input.size(); ++i)
  {
    cout<<i<<" "<<i-n<<endl;
    t+=CountC(input.substr(i,1))-CountC(input.substr(i-n,1));
    if(t==n) ret.push_back(i);
  }
  return ret;
}

int main()
{
  ifstream input;
  string file="A-small-attempt1";
  string filein=file+".in";
  string fileout=file+".out";
  input.open(filein.c_str(),ios::in);
  ofstream out;
  out.open(fileout.c_str(),ios::out);

  int count;
  input>>count;

  string in;
  int n;

  for (int i = 0; i < count; ++i)
  {
    input>>in;
    input>>n;

    int res=0;
    vec comp=Calculate(in,n);
    cout<<"here"<<endl;
    if(comp.size()==0)
    {
      res=0;
    }
    else if(comp.size()==1)
    {
      cout<<"here"<<endl;
      res=in.size()-n+1;
      cout<<comp[0];
    }
    else
    {
      cout<<"heref"<<endl;
      for (int j = 0; j < comp.size(); ++j)
      {
        cout<<comp[j]<<"A";
      }
      res=comp[0]-n+1;
      for (int j = 1; j < comp.size(); ++j)
      {
        res+=2*(comp[j]-comp[j-1])+1;
      }
      int ss=comp.size();
      res+=(comp[0]-n+1)*(comp[1]-comp[0]);
      res+=(in.size()-comp[ss-1]-1)*(comp[ss-1]-comp[ss-2]+1);
    }
    cout<<"==="<<res<<endl;
    // printing the output
    out<<"Case #"<<i+1<<": ";
    out<<res;
    //out<<showpoint<<tt;


    if(i<count-1) out<<endl;
    cout<<i+1<<"/"<<count<<endl;
  }
  return 0;
}