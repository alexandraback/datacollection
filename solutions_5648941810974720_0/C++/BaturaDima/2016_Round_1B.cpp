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
typedef long long     ll;
typedef unsigned int  UInt;
#define FOR(i,a,b)    for(int i=a;i<(int)b;++i)
#define FOR_D(i,a,b)  for(int i=a;i>=b;--i)
template<class T> inline T   sqr(T v)  { return v * v; }
template<class T> inline int sign(T v) { return v == 0 ? 0 : (v > 0 ? 1 : -1); }
template<class T> int get_bit(T v, int bit_index) { return (v >> bit_index) & 1; } //return {0,1}



void main()
{
  ifstream is("GoogleCodeJam/A-small-attempt0.in");
  //ifstream is("GoogleCodeJam/A-large.in");
  //ifstream is("GoogleCodeJam/input.txt");
  ofstream os("GoogleCodeJam/output.txt");

  string num[10] = 
  {"ZERO", 
  "ONE", 
  "TWO", 
  "THREE", 
  "FOUR", 
  "FIVE", 
  "SIX", 
  "SEVEN", 
  "EIGHT", 
  "NINE"};
  //z - 0
  //w - 2
  //u-4
  //x-6
  //g - 8
  //////////////////////////////////////////////////////////////////////////
  //f - 5
  //h-3
  //o-1
  //r-3
  //s-7
  string nn("ZOWHUFXSG");

  int t;
  is>>t;

  for (int ti=0;ti<t;++ti)
  {
    //solve
    string s;
    is>>s;

    map<char,int> m;
    FOR (j,'A','Z'+1)
      m[j]=0;
    FOR (i,0,s.size())
      ++m[s[i]];

    multiset<int> res;
    for (int i=0;i<9;i+=2)
      while(m[nn[i]])
    {
      res.insert(i);
      FOR (j1,0,num[i].size())
        --m[num[i][j1]];
    }

    for (int i=1;i<9;i+=2)
      while(m[nn[i]])
    {
      res.insert(i);
      FOR (j1,0,num[i].size())
        --m[num[i][j1]];
    }

    FOR (j,0,m['I'])
      res.insert(9);

    os << "Case #"<<ti+1<<": ";
    for (multiset<int>::iterator it=res.begin();it!=res.end();++it)
      os<<*it;
    //out
    os<<"\n";
  }
}



//void main()
//{
//  //ifstream is("GoogleCodeJam/A-small-attempt0.in");
//  //ifstream is("GoogleCodeJam/A-large.in");
//  ifstream is("GoogleCodeJam/input.txt");
//  ofstream os("GoogleCodeJam/output.txt");
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


