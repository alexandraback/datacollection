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

int N;
double Naomi[1001];
double Ken[1001];

pair<int, int> Solve() {
  sort(Ken, Ken + N);
  list<double> l;
  for (int i = 0; i < N; i++) {
    l.push_back(Ken[i]);
  }
  int count = 0;
  for (int i = 0; i < N; i++) {
    auto it = l.begin();
    while (it != l.end()) {
      if (*it > Naomi[i]) {
        l.erase(it);
        break;
      }
      it++;
    }
    if (it == l.end()) {
      count++;
      l.erase(l.begin());
    }
  }
  sort(Naomi, Naomi + N);
  sort(Ken, Ken + N, greater<double>());
  int count2 = 0;
  for (int i = 0; i < N; i++) {
    double Ken2[N - i];
    copy(Ken + i, Ken + N, Ken2);
    sort(Ken2, Ken2 + N - i);
    int c = 0;
    for (int j = 0; j < N - i; j++) {
      if (Naomi[i + j] > Ken2[j]) {
        c++;
      }
    }
    count2 = max(c, count2);
  }
  return make_pair(count2, count);
}

int main() {
  int T;
  cin >> T;
  for (int x = 0; x < T; x++) {
    printf("Case #%d: ", x + 1);
    cin >> N;
    for (int i = 0; i < N; i++) {
      cin >> Naomi[i];
    }
    for (int i = 0; i < N; i++) {
      cin >> Ken[i];
    }
    auto ans = Solve();
    cout << ans.first << " " << ans.second << std::endl;
  }
}
