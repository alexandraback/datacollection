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

namespace{
  template <typename T>
  class Point2
  {
  public:
    Point2(){}
    Point2(T x_, T y_):x(x_), y(y_) {}

    Point2<T>& operator +=(const Point2<T>&);
    Point2<T>& operator -=(const Point2<T>&);
    Point2<T>& operator /=(T);
    Point2<T>& operator *=(T);

    T length() const;
    T length_square() const;

  public:
    T x;
    T y;
  };

  template<class T>
  inline Point2<T>& Point2<T>::operator +=(const Point2<T>& r)           
  {
    x += r.x;
    y += r.y;
    return *this;
  }
  typedef Point2<int>    Point2I;

  //////////////////////////////////////////////////////////////////////////

  int n,m,h;
  int floor_[100][100];
  int ceil_[100][100];
  float times[100][100];
  //float move[100][100][4];
  //struct Move
  //{
  //  //Point2I s;
  //  Point2I f;
  //  //float t;
  //};
  typedef Point2I Move ;
  typedef multimap<float, Move> Front;
  Front front;

  const float inf=1e10;
}


void push_moves(const Point2I& pos, float time)
{
  static const Point2I dirs[4]={Point2I(-1,0),Point2I(+1,0),Point2I(0,-1),Point2I(0,+1)};
  for (int i=0;i<4;++i)
  {
    Point2I f = pos;
    f+=dirs[i];

    if ((unsigned int)f.x<(unsigned int)n&&(unsigned int)f.y<(unsigned int)m)
    {
      int c0=ceil_[pos.x][pos.y];
      int c1=ceil_[f.x][f.y];
      int f0=floor_[pos.x][pos.y];
      int f1=floor_[f.x][f.y];
      float water = h - (time>0?time*10:0.f);
      float max_f = (float)(c1-50);
      if (f0<=max_f && f1<=max_f && c0>=f1+50)
      {
        float time_c0 = max(f0,water) <= max_f ? time : (h-max_f)/10;
        float time_c1 = max(f1,water) <= max_f ? time : (h-max_f)/10;
        //float time_3 = max(f1,water) <= max_f ? time : (h-max_f)/10;
        float time_=max(time_c0,time_c1);
        float water = h - (time_>0?time_*10:0.f);
        float t=water>=f0+20 ? time_+1:time_+10;

        if (t<times[f.x][f.y])
          front.insert(Front::value_type(t, f));
      }
    }
  }
}

void expand()
{
  while (!front.empty())
  {
    Front::iterator it (front.begin());
    float t= it->first;
    Move move = it->second;
    front.erase(it);

    if (t<times[move.x][move.y])
    {
      times[move.x][move.y]=t;
      if (move.x==n-1&&move.y==m-1)
        break;
      push_moves(move, t);
    }
  }
}


void main()
{
  ifstream is("a.in");
  ofstream os("a.out");

  int t;
  is>>t;


  for (int ti=0;ti<t;++ti)
  {
    //solve

    is>>h>>n>>m;
    for (int i=0;i<n;++i)
      for (int j=0;j<m;++j)
        is>>ceil_[i][j];
    for (int i=0;i<n;++i)
      for (int j=0;j<m;++j)
      {
        is>>floor_[i][j];
        times[i][j]=inf;
      }

    front.clear();
    //time_reach=inf;
    //push_moves(Point2I(0,0), (float)-1e5);
    front.insert(Front::value_type(-inf, Point2I(0,0)));
    expand();
    //front.insert(Front::value_type(-1e5, make_pair(Point2I(0,0),Point2I(0,1))));
    //front.insert(Front::value_type(-1e5, make_pair(Point2I(0,0),Point2I(1,0))));

    os << "Case #"<<ti+1<<": ";
    //out
    float time_reach=times[n-1][m-1];

    if (time_reach<0)
      time_reach=0;
    os<<time_reach;

    os<<"\n";
  }
}

//
//ifstream is("a.in");
//ofstream os("a.out");
//
//
//int s0=0;
//int s1=0;
//vector<int> s;
//vector<int> set0,set1;
//
//bool solve(int i)
//{
//  if (i>=s.size())
//    return s0!=0 && s0==s1;
//
//  if (solve(i+1))
//  {
//    return true;
//  }
//
//  s0+=s[i];
//  if (solve(i+1))
//  {
//    set0.push_back(s[i]);
//    return true;
//  }
//  s0-=s[i];
//
//  s1+=s[i];
//  if (solve(i+1))
//  {
//    set1.push_back(s[i]);
//    return true;
//  }
//  s1-=s[i];
//
//  return false;
//}
//
//void main()
//{
//  int t;
//  is>>t;
//
//  for (int ti=0;ti<t;++ti)
//  {
//    //solve
//    int n;
//    is >>n;
//    s.resize(n);
//    for (int i=0;i<n;++i)
//    {
//      is >> s[i];
//    }
//
//    os << "Case #"<<ti+1<<": ";
//    os<<"\n";
//    //out
//
//    s0=0;
//    s1=0;
//    set0.clear();set1.clear();
//
//    if (solve(0))
//    {
//      for (int i=0;i<set0.size();++i)
//        os<<set0[i]<<" ";
//      os<<"\n";
//      for (int i=0;i<set1.size();++i)
//        os<<set1[i]<<" ";
//    }
//    else
//      os <<"Impossible";
//
//    os<<"\n";
//  }
//}
//
//
////void main()
////{
////  ifstream is("a.in");
////  ofstream os("a.out");
////
////  int t;
////  is>>t;
////
////  int n;
////  vector<int> s;
////
////  for (int ti=0;ti<t;++ti)
////  {
////    //solve
////    is >>n;
////    s.resize(n);
////    int sum=0;
////    for (int i=0;i<n;++i)
////    {
////      is >> s[i];
////      sum+=s[i];
////      //if (s[i]<min0)
////      //  min0=s[i];
////      //else if (s[i]<min1)
////      //  min1=s[i];
////    }
////
////    os << "Case #"<<ti+1<<": ";
////
////    for (int i=0;i<n;++i)
////    {
////      double low=0,hi=1;
////      while (hi-low>1e-10)
////      {
////        double res= (hi+low)/2;
////
////        double ss=0;
////        for (int j=0;j<n;++j)
////          if (j!=i)
////          {
////            double v = double(sum*res+s[i]-s[j])/(sum);
////            if (v>0)
////              ss+=v;
////            if (ss>1-res)
////              break;
////          }
////
////        if (ss>1-res)
////          hi=res;
////        else
////          low=res;
////      }
////
////      //int min0=1000;
////      //for (int j=0;j<n;++j)
////      //  if (j!=i)
////      //    min0 = min(min0,s[j]);
////      //double res = double(sum+min0-s[i])/(2*sum)*100;
////      double res= (hi+low)/2;
////      os << res*100<< " ";
////    }
////
////
////
////    //out
////    os<<"\n";
////  }
////}
//
//
////void main()
////{
////  ifstream is("a.in");
////  ofstream os("a.out");
////
////  int t;
////  is>>t;
////
////  for (int ti=0;ti<t;++ti)
////  {
////    //solve
////
////    os << "Case #"<<ti+1<<": ";
////    //out
////    os<<"\n";
////  }
////}
////
