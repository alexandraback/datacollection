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

//int n, k;
vector < vector<int> > g;
vector<int> mt;
vector<char> used;

bool try_kuhn (int v) {
  if (used[v]) 
    return false;
  used[v] = true;

  for (size_t i=0; i<g[v].size(); ++i) {
    int to = g[v][i];
    if (mt[to] == -1 || try_kuhn (mt[to])) {
      mt[to] = v;
      return true;
    }
  }
  return false;
}

//c
void main()
{
  //ifstream is("GoogleCodeJam/C-small-attempt0.in");
  ifstream is("GoogleCodeJam/C-large.in");
  //ifstream is("GoogleCodeJam/input.txt");
  ofstream os("GoogleCodeJam/output.txt");

  int t;
  is>>t;

  for (int ti=0;ti<t;++ti)
  {
    int n;
    is>>n;

    vector<pair<string,string>> ws(n);
    map<string,set<string>> v1;
    set<string> v2;
    FOR (i,0,n)
    {
      is>>ws[i].first>>ws[i].second;
      v1[ws[i].first].insert(ws[i].second);
      v2.insert(ws[i].second);
    }

    map<string,int> v2i;
    {
      int i=0;
      for (set<string>::iterator it=v2.begin();it!=v2.end();++it,++i)
        v2i[*it]=i;
    }

    g.clear();
    g.resize(v1.size());
    int i=0;
    for (map<string,set<string>>::iterator it=v1.begin();it!=v1.end();++it,++i)
    {
      for (set<string>::iterator it1=it->second.begin();it1!=it->second.end();++it1)
      {
        g[i].push_back(v2i[*it1]);
      }
    }

    int nn=0;
    {
      int n=v1.size();
      int k=v2.size();
      mt.assign (k, -1);
      for (int v=0; v<n; ++v) {
        used.assign (n, false);
        try_kuhn (v);
      }
      for (int v=0; v<k; ++v) 
      if (mt[v]>=0)
        ++nn;
    }



    int res=n-(nn+v1.size()+v2.size()-2*nn);

    os << "Case #"<<ti+1<<": "<<res;
    //out
    os<<"\n";
  }
}


////c-small
//void main()
//{
//  ifstream is("GoogleCodeJam/C-small-attempt0.in");
//  //ifstream is("GoogleCodeJam/C-large.in");
//  //ifstream is("GoogleCodeJam/input.txt");
//  ofstream os("GoogleCodeJam/output.txt");
//
//  int t;
//  is>>t;
//
//  for (int ti=0;ti<t;++ti)
//  {
//    int n;
//    is>>n;
//
//    vector<pair<string,string>> ws(n);
//
//    FOR (i,0,n)
//      is>>ws[i].first>>ws[i].second;
//
//    int res=0;
//    FOR (m,0,1<<n)
//    {
//      set<string> f,s;
//      FOR (i,0,n)
//        if (get_bit(m,i))
//        {
//          f.insert(ws[i].first);
//          s.insert(ws[i].second);
//        }
//
//      int k=0;
//      FOR (i,0,n)
//        if (!get_bit(m,i))
//        {
//          if (f.find(ws[i].first)!=f.end() && s.find(ws[i].second)!=s.end())
//          {
//            ++k;
//          }
//        }
//      res=max(res,k);
//    }
//
//    os << "Case #"<<ti+1<<": "<<res;
//    //out
//    os<<"\n";
//  }
//}


//b
//void main()
//{
//  //ifstream is("GoogleCodeJam/B-small-attempt0.in");
//  ifstream is("GoogleCodeJam/B-large.in");
//  //ifstream is("GoogleCodeJam/input.txt");
//  ofstream os("GoogleCodeJam/output.txt");
//
//  int t;
//  is>>t;
//
//  for (int ti=0;ti<t;++ti)
//  {
//    //solve
//    string s[2];
//    is>>s[0]>>s[1];
//    int l=s[0].size();
//
//    ll res1,res2;
//    bool res_inited=false;
//
//    FOR (n1,0,2)
//      FOR (i,0,l+1)
//      {
//        ll c1=0,c2=0;
//        ll c = 1;
//        FOR (i1,0,l-1)
//          c*=10;
//
//        int n2=1-n1;
//        bool ok=true;
//        FOR (j,0,i)
//        {
//          if (s[n1][j]==s[n2][j]||s[n1][j]=='?'||s[n2][j]=='?')
//          {
//            int k=(s[n1][j]!='?'?s[n1][j]-'0':(s[n2][j]!='?'?s[n2][j]-'0':0));
//            c1+=k*c;
//            c2+=k*c;
//          }
//          else
//            ok=false;
//          c/=10;
//        }
//
//        if (ok)
//        {
//          if (i<l)
//          {
//            if (s[n1][i]=='?'||s[n2][i]=='?')
//            {
//              int k1,k2;
//              if (s[n1][i]=='?')
//              {
//                if (s[n2][i]=='?')
//                {
//                  k1=1;
//                  k2=0;
//                }
//                else
//                {
//                  k2=s[n2][i]-'0';
//                  k1=min(k2+1,9);
//                }
//              }
//              else
//              {
//                k1=s[n1][i]-'0';
//                k2=max(k1-1,0);
//              }
//              c1+=k1*c;
//              c2+=k2*c;
//            }
//            else
//            {
//              c1+=(s[n1][i]-'0')*c;
//              c2+=(s[n2][i]-'0')*c;
//            }
//            c/=10;
//
//            for (int i1=i+1;i1<l;++i1)
//            {
//              int k1=s[n1][i1]=='?'?0:s[n1][i1]-'0';
//              int k2=s[n2][i1]=='?'?9:s[n2][i1]-'0';
//
//              c1+=k1*c;
//              c2+=k2*c;
//              c/=10;
//            }
//          }
//
//          //TODO:
//          ll cc1=n1==0?c1:c2;
//          ll cc2=n2==0?c1:c2;
//          if (!res_inited || abs(c1-c2)<abs(res1-res2) || (abs(c1-c2)==abs(res1-res2) && (cc1<res1 || (cc1==res1&&cc2<res2))))
//          {
//            res1=cc1;
//            res2=cc2;
//            res_inited=true;
//          }
//        }
//      }
//
//    os << "Case #"<<ti+1<<": ";
//
//    for (int i=l-1;i>=0;--i)
//    {
//      s[0][i]=res1%10+'0';
//      s[1][i]=res2%10+'0';
//      res1/=10;
//      res2/=10;
//    }
//
//    os << s[0]<< " " << s[1];
//    //out
//    os<<"\n";
//  }
//}
//



////a
//void main()
//{
//  //ifstream is("GoogleCodeJam/A-small-attempt0.in");
//  ifstream is("GoogleCodeJam/A-large.in");
//  //ifstream is("GoogleCodeJam/input.txt");
//  ofstream os("GoogleCodeJam/output.txt");
//
//  string num[10] = 
//  {"ZERO", 
//  "ONE", 
//  "TWO", 
//  "THREE", 
//  "FOUR", 
//  "FIVE", 
//  "SIX", 
//  "SEVEN", 
//  "EIGHT", 
//  "NINE"};
//  //z - 0
//  //w - 2
//  //u-4
//  //x-6
//  //g - 8
//  //////////////////////////////////////////////////////////////////////////
//  //f - 5
//  //h-3
//  //o-1
//  //r-3
//  //s-7
//  string nn("ZOWHUFXSG");
//
//  int t;
//  is>>t;
//
//  for (int ti=0;ti<t;++ti)
//  {
//    //solve
//    string s;
//    is>>s;
//
//    map<char,int> m;
//    FOR (j,'A','Z'+1)
//      m[j]=0;
//    FOR (i,0,s.size())
//      ++m[s[i]];
//
//    multiset<int> res;
//    for (int i=0;i<9;i+=2)
//      while(m[nn[i]])
//    {
//      res.insert(i);
//      FOR (j1,0,num[i].size())
//        --m[num[i][j1]];
//    }
//
//    for (int i=1;i<9;i+=2)
//      while(m[nn[i]])
//    {
//      res.insert(i);
//      FOR (j1,0,num[i].size())
//        --m[num[i][j1]];
//    }
//
//    FOR (j,0,m['I'])
//      res.insert(9);
//
//    os << "Case #"<<ti+1<<": ";
//    for (multiset<int>::iterator it=res.begin();it!=res.end();++it)
//      os<<*it;
//    //out
//    os<<"\n";
//  }
//}



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


