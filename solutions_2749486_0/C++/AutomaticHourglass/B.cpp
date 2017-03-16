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

string func(int x, int y)
{
  int xCoor=0;
  int s=1;
  string out;
  if(x!=0)
  {
    while(xCoor<abs(x)-1)
    {
      out+="WE";
      ++xCoor;
      s+=2;;
    }
    if (x<0)
    {
       out+="W";
       ++s;
    }
    else
    {
      out+="WE";
      s+=2;
    }
  }

  if(y!=0)
  {
    int yCoor=0;
    if(y<0)
    {
      while(yCoor>=y+1)
      {
        out+="NS";
        --yCoor;
        s+=2;
      }
    }
    else
    {
      while(yCoor<=y-1)
      {
        out+="SN";
        ++yCoor;
        s+=2;
      } 
    }
  }
  return out;
}

int main()
{
  ifstream input;
  string file="B-small-attempt2";
  string filein=file+".in";
  string fileout=file+".out";
  input.open(filein.c_str(),ios::in);
  ofstream out;
  out.open(fileout.c_str(),ios::out);

  int count;
  input>>count;
  int x,y;

  for (int i = 0; i < count; ++i)
  {
    input>>x>>y;

    // printing the output
    out<<"Case #"<<i+1<<": ";
    out<<func(x,y);
    if(i<count-1) out<<endl;
    cout<<i+1<<"/"<<count<<endl;
  }
  return 0;
}