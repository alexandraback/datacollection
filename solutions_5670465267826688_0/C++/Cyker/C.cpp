#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define OINT(i,b,e) for(int (i)=(b);(i)<(int)(e);(i)++)
#define CINT(i,b,e) for(int (i)=(b);(i)<=(int)(e);(i)++)
#define FOREACH(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define PI 3.1415926535897932384626433832795
#define INF 0x7FFFFFFF

typedef pair<int, char> qual;

int T;
int L, X;
vector<qual> buf;

qual mult(qual a, qual b)
{
  int first = a.first * b.first;
  char second = 'x';

  if (a.second == '1' && b.second == '1') { second = '1'; };
  if (a.second == '1' && b.second == 'i') { second = 'i'; };
  if (a.second == '1' && b.second == 'j') { second = 'j'; };
  if (a.second == '1' && b.second == 'k') { second = 'k'; };
  if (a.second == 'i' && b.second == '1') { second = 'i'; };
  if (a.second == 'i' && b.second == 'i') { second = '1'; first = -first; };
  if (a.second == 'i' && b.second == 'j') { second = 'k'; };
  if (a.second == 'i' && b.second == 'k') { second = 'j'; first = -first; };
  if (a.second == 'j' && b.second == '1') { second = 'j'; };
  if (a.second == 'j' && b.second == 'i') { second = 'k'; first = -first; };
  if (a.second == 'j' && b.second == 'j') { second = '1'; first = -first; };
  if (a.second == 'j' && b.second == 'k') { second = 'i'; };
  if (a.second == 'k' && b.second == '1') { second = 'k'; };
  if (a.second == 'k' && b.second == 'i') { second = 'j'; };
  if (a.second == 'k' && b.second == 'j') { second = 'i'; first = -first; };
  if (a.second == 'k' && b.second == 'k') { second = '1'; first = -first; };

  return make_pair(first, second);
}

qual mult_all(const vector<qual> &buf)
{
  qual res = make_pair(1, '1');
  FOREACH(buf, it) {
    res = mult(res, *it);
  }
  return res;
}

int solve_i(const vector<qual> &buf)
{
  qual res = make_pair(1, '1');
  int i = 0;
  for (i = 0;i < buf.size();i++) {
    res = mult(res, buf[i]);
    if (res.first == 1 && res.second == 'i') {
      return i;
    }
  }
  return -1;
}

int solve_k(const vector<qual> &buf)
{
  qual res = make_pair(1, '1');
  int k = 0;
  for (k = buf.size() - 1;k >= 0;k--) {
    res = mult(buf[k], res);
    if (res.first == 1 && res.second == 'k') {
      return k;
    }
  }
  return -1;
}

int main(int argc, char **argv)
{
  cin >> T;
  for (int t = 0;t < T;t++) {
    cin >> L >> X;
    string strbuf;
    cin >> strbuf;
    buf.clear();
    FOREACH(strbuf, it) {
      buf.push_back(make_pair(1, *it));
    }

    string res;

    qual prod = mult_all(buf);
    qual temp = make_pair(1, '1');
    REP(i, X % 4) {
      temp = mult(temp, prod);
    }
    if (!(temp.first == -1 && temp.second == '1')) {
      res = "NO";
    } else {
      if (X <= 8) {
        // find i and k and verify i + 1 < k
        vector<qual> buf_copy = buf;
        REP(i, X - 1) {
          buf.insert(buf.begin(), buf_copy.begin(), buf_copy.end());
        }
        int ii = solve_i(buf);
        int kk = solve_k(buf);
        if (ii != -1 && kk != -1 && ii + 1 < kk) {
          res = "YES";
        } else {
          res = "NO";
        }
      } else {
        // find i and k
        vector<qual> buf_copy = buf;
        REP(i, 4 - 1) {
          buf.insert(buf.begin(), buf_copy.begin(), buf_copy.end());
        }
        int ii = solve_i(buf);
        int kk = solve_k(buf);
        if (ii != -1 && kk != -1) {
          res = "YES";
        } else {
          res = "NO";
        }
      }
    }

    cout << "Case #" << t + 1 << ": ";
    cout << res;
    cout << endl;
  }

  return 0;
}
