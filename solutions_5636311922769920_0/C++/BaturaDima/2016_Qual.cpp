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

//a - тупо просиммулировать до опред-го числа. Попробовать док-ть, что только с 0 невозможно, а остальные быстро дадут рез-т
//b - по идее можно и big сдать
//c - можно попробовать на долгий перебор поставить
//d - пока только small

//////////////////////////////////////////////////////////////////////////


//d-small
void main()
{
  ifstream is("GoogleCodeJam/D-small-attempt0.in");
  //ifstream is("GoogleCodeJam/input.txt");
  ofstream os("GoogleCodeJam/output.txt");

  int t;
  is>>t;

  for (int ti=0;ti<t;++ti)
  {
    int k,c,s;
    is>>k>>c>>s;

    os << "Case #"<<ti+1<<": ";
    FOR (i,1,k+1)
      os<<i<<" ";
    os<<"\n";
  }
}

////b
//void main()
//{
//  ifstream is("GoogleCodeJam/B-small-attempt0.in");
//  ofstream os("GoogleCodeJam/output.txt");
//
//  int t;
//  is>>t;
//
//  for (int ti=0;ti<t;++ti)
//  {
//    string s;
//    is>>s;
//    int res=0;
//    FOR (i,1,s.size())
//      if (s[i]!=s[i-1])
//        ++res;
//    if (s.back()=='-')
//      ++res;
//
//    os << "Case #"<<ti+1<<": ";
//    os<<res;
//    os<<"\n";
//  }
//}

//void main()
//{
//  ifstream is("GoogleCodeJam/A-small-attempt0.in");
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


