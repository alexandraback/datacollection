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
#define max(a,b)    (((a) > (b)) ? (a) : (b))
#define min(a,b)    (((a) < (b)) ? (a) : (b))
#define sqr(a)    ((a)*(a))

//////////////////////////////////////////////////////////////////////////

ifstream is("a.in");
ofstream os("a.out");


int s0=0;
int s1=0;
vector<int> s;
vector<int> set0,set1;

bool solve(int i)
{
  if (i>=s.size())
    return s0!=0 && s0==s1;

  if (solve(i+1))
  {
    return true;
  }

  s0+=s[i];
  if (solve(i+1))
  {
    set0.push_back(s[i]);
    return true;
  }
  s0-=s[i];

  s1+=s[i];
  if (solve(i+1))
  {
    set1.push_back(s[i]);
    return true;
  }
  s1-=s[i];

  return false;
}

void main()
{
  int t;
  is>>t;

  for (int ti=0;ti<t;++ti)
  {
    //solve
    int n;
    is >>n;
    s.resize(n);
    for (int i=0;i<n;++i)
    {
      is >> s[i];
    }

    os << "Case #"<<ti+1<<": ";
    os<<"\n";
    //out

    s0=0;
    s1=0;
    set0.clear();set1.clear();

    if (solve(0))
    {
      for (int i=0;i<set0.size();++i)
        os<<set0[i]<<" ";
      os<<"\n";
      for (int i=0;i<set1.size();++i)
        os<<set1[i]<<" ";
    }
    else
      os <<"Impossible";

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
//  int n;
//  vector<int> s;
//
//  for (int ti=0;ti<t;++ti)
//  {
//    //solve
//    is >>n;
//    s.resize(n);
//    int sum=0;
//    for (int i=0;i<n;++i)
//    {
//      is >> s[i];
//      sum+=s[i];
//      //if (s[i]<min0)
//      //  min0=s[i];
//      //else if (s[i]<min1)
//      //  min1=s[i];
//    }
//
//    os << "Case #"<<ti+1<<": ";
//
//    for (int i=0;i<n;++i)
//    {
//      double low=0,hi=1;
//      while (hi-low>1e-10)
//      {
//        double res= (hi+low)/2;
//
//        double ss=0;
//        for (int j=0;j<n;++j)
//          if (j!=i)
//          {
//            double v = double(sum*res+s[i]-s[j])/(sum);
//            if (v>0)
//              ss+=v;
//            if (ss>1-res)
//              break;
//          }
//
//        if (ss>1-res)
//          hi=res;
//        else
//          low=res;
//      }
//
//      //int min0=1000;
//      //for (int j=0;j<n;++j)
//      //  if (j!=i)
//      //    min0 = min(min0,s[j]);
//      //double res = double(sum+min0-s[i])/(2*sum)*100;
//      double res= (hi+low)/2;
//      os << res*100<< " ";
//    }
//
//
//
//    //out
//    os<<"\n";
//  }
//}


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
//
