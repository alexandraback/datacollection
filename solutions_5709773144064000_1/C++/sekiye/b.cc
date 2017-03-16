#include <iostream>
#include <algorithm>
#include <array>
#include <climits>
#include <cmath>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>

typedef long long          ll;
typedef unsigned int       uint;
typedef unsigned long long ull;

using namespace std;

ostream& operator<<(ostream &s, vector<string> v)
{
  int cnt = v.size();
  s << "[ ";
  for (int i=0; i<cnt; i++) {
	if (i > 0) s << ", ";
	s << '"' << v[i] << '"';
  }
  return s << " ]  // " << cnt << " item" << (cnt >= 2 ? "s" : "");
}

template <typename T> ostream& operator<<(ostream &s, vector<T> v)
{
  int cnt = v.size();
  s << "[ ";
  for (int i=0; i<cnt; i++) {
	if (i > 0) s << ", ";
	s << v[i];
  }
  return s << " ]  // " << cnt << " item" << (cnt >= 2 ? "s" : "");
}

template <typename T> ostream& operator<<(ostream &s, list<T> ls)
{
  int cnt = 0;
  s << "( ";
  for (auto it=ls.begin(); it!=ls.end(); it++) {
	if (it != it.begin()) s << ", ";
	s << *it;
	cnt++;
  }
  return s << " )  // " << cnt << " item" << (cnt >= 2 ? "s" : "");
}

template <typename T> ostream& operator<<(ostream &s, deque<T> st)
{
  int cnt = st.size();
  s << "[ ";
  for (auto it=st.begin(); it!=st.end(); it++) {
	if (it != st.begin()) s << ", ";
	s << *it;
  }
  return s << " ]  // " << cnt << " item" << (cnt >= 2 ? "s" : "");
}

template <typename T1, typename T2> ostream& operator<<(ostream &s, map<T1,T2> m)
{
  int cnt = m.size();
  s << "{ ";
  for (auto it=m.begin(); it!=m.end(); it++) {
	if (it != m.begin()) s << ", ";
	s << it->first << " => " << it->second;
  }
  return s << " }  // " << cnt << " item" << (cnt >= 2 ? "s" : "");
}

template <typename T> ostream& operator<<(ostream &s, set<T> st)
{
  int cnt = st.size();
  s << "[ ";
  for (auto it=st.begin(); it!=st.end(); it++) {
	if (it != st.begin()) s << ", ";
	s << *it;
  }
  return s << " ]  // " << cnt << " item" << (cnt >= 2 ? "s" : "");
}

template <typename T1, typename T2> ostream& operator<<(ostream &s, pair<T1,T2> p)
{
  return s << "(" << p.first << "," << p.second << ")";
}

double Solve() {
  double C;
  double F;
  double X;
  cin >> C >> F >> X;
  double sum = 0;
  double v = 2;
  double best_time = X / v;
  while (true) {
    sum += C / v;
    v += F;
    double time = sum + X / v;
    if (time > best_time) {
      return best_time;
    }
    best_time = time;
  }
}

int main() {
  int T;
  cin >> T;
  for (int x = 0; x < T; x++) {
    printf("Case #%d: %.7f\n", x + 1, Solve());
  }
}
