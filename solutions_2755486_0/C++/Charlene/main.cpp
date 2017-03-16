#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <set>
#include <algorithm>
#include <queue>
#include <utility>
#include <sstream>
#include <bitset>
#include <stdio.h>
#include <fstream>
using namespace std;

#define DEBUG 0
#define debug1(x) if (DEBUG) cout << #x" = " << x << endl;
#define debug2(x, y) if (DEBUG) cout << #x" = " << x << " " << #y" = " << y << endl;
#define debug3(x, y, z) if (DEBUG) cout << #x" = " << x << " " << #y" = " << y << " " << #z" = " << z << endl;
#define debug4(x, y, z, w) if (DEBUG) cout << #x" = " << x << " " << #y" = " << y << " " << #z" = " << z << " " << #w" = " << w << endl;

template <class T>
ostream & operator << (ostream & out, const vector<T> & data)
{ out << "["; for (int i = 0; i < data.size(); ++i) out << data[i] << (i == data.size() - 1 ? "" : ","); out << "]"; return out; }

template <class T>
ostream & operator << (ostream & out, const set<T> & s)
{ out << "{"; for (typename set<T>::iterator itr = s.begin(); itr != s.end(); ++itr) out << *itr << " "; out << "}"; return out; }

template <class T>
ostream & operator << (ostream & out, const multiset<T> & s)
{ out << "{"; for (typename multiset<T>::iterator itr = s.begin(); itr != s.end(); ++itr) out << *itr << " "; out << "}"; return out; }

template <class T1, class T2>
ostream & operator << (ostream & out, const pair<T1, T2> & p)
{ out << "(" << p.first << "," << p.second << ")"; return out; }

template <class T1, class T2>
ostream & operator << (ostream & out, const map<T1, T2> & m)
{
  for (typename map<T1, T2>::const_iterator itr = m.begin(); itr != m.end(); ++itr)
    out << itr->first << "->" << itr->second << " ";
  return out;
}


void globalinit()
{
  
}

struct Att
{
  int d;
  int n;
  int w, e;
  int s;
  int deltad;
  int deltap;
  int deltas;
};

int N;
vector<Att> atts;

void init()
{
  cin >> N;
  atts.resize(N);
  
  for (int i = 0; i < N; ++i)
    cin >> atts[i].d >> atts[i].n >> atts[i].w >> atts[i].e >> atts[i].s >> atts[i].deltad >> atts[i].deltap >> atts[i].deltas;
}

string deal()
{
  int ans = 0;
  map<int, int> hei;
  
  for (int nowd = 0; ; nowd++)
  {
    int remain = 0;
    for (int i = 0; i < N; ++i)
      if (atts[i].n > 0) remain++;
    if (remain == 0) break;
    
    for (int i = 0; i < N; ++i)
      if (atts[i].d == nowd && atts[i].n > 0)
      {
        bool succ = false;
        for (int x = atts[i].w * 2; x <= atts[i].e * 2; ++x)
          if (hei[x] < atts[i].s) succ = true;
        if (succ) ans++;
        //if (succ) { cout << nowd << " " << i << endl; }
      }
    
    for (int i = 0; i < N; ++i)
      if (atts[i].d == nowd && atts[i].n > 0)
      {
        for (int x = atts[i].w * 2; x <= atts[i].e * 2; ++x)
          if (hei[x] < atts[i].s) hei[x] = atts[i].s;
        atts[i].n--;
        atts[i].s += atts[i].deltas;
        atts[i].d += atts[i].deltad;
        atts[i].w += atts[i].deltap;
        atts[i].e += atts[i].deltap;
      }
  }
  
  ostringstream ostr;
  ostr << ans;
  return ostr.str();
}

int main()
{
  freopen("/Users/yingjiang/Downloads/C-small-attempt0-1.in.txt", "r", stdin);
  freopen("/Users/yingjiang/TopCoder/Codejam/3C-small.out", "w", stdout);

  globalinit();
  
  int T;
  cin >> T;
  for (int test = 1; test <= T; ++test)
  {
    init();
    cout << "Case #" << test << ": " << deal() << endl;
  }
  return 0;
}
