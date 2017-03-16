#include <assert.h>
#include <vector>
#include <list>
#include <map>
#include <math.h>
#include <set>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
#define FOR(i,a,b)    for(int i=a;i<(int)b;++i)
#define FOR_D(i,a,b)  for(int i=a;i>=b;--i)
template<class T> inline T   sqr(T v)  { return v * v; }
template<class T> inline int sign(T v) { return v == 0 ? 0 : (v > 0 ? 1 : -1); }

//////////////////////////////////////////////////////////////////////////

//b
void main()
{
  ifstream is("GoogleCodeJam/B-small-attempt0.in");
  ofstream os("output.txt");

  int t;
  is>>t;

  for (int ti=0;ti<t;++ti)
  {
    string s;
    is>>s;
    int res=0;
    FOR (i,1,s.size())
      if (s[i]!=s[i-1])
        ++res;
    if (s.back()=='-')
      ++res;

    os << "Case #"<<ti+1<<": ";
    os<<res;
    os<<"\n";
  }
}




//void main()
//{
//  ifstream is("a.in");
//  ofstream os("a.out");
//
//  int t;
//  is>>t;
//
//  for (int ti=0;ti<t;++ti)
//  {
//    //solve
//
//    os << "Case #"<<ti+1<<": ";
//    //out
//    os<<"\n";
//  }
//}


