#pragma comment(linker, "/stack:32000000")
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <sstream>
#include <stack>
#include <cassert>
#include <string.h>
#include <ctime>

#define pb push_back
#define mp make_pair
#define PI 3.1415926535897932384626433832795
#define sqr(x) (x)*(x)
#define forn(i, n) for(int i = 0; i < n; ++i)
#define ALL(x) x.begin(), x.end()
#define sz(x) int((x).size())
#define X first
#define Y second
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;
typedef pair<int,int> pii;
const int INF = 2147483647;
const ll LLINF = 9223372036854775807LL;

pair<string, string> solvestupid(string s1, string s2) {
  int n = sz(s1);
  int pos = 0;
  while (pos < sz(s1)) {
    if (s1[pos] == '?' && s2[pos] == '?') s1[pos] = s2[pos] = '0';
    else if (s1[pos] == '?') s1[pos] = s2[pos];
    else if (s2[pos] == '?') s2[pos] = s1[pos];
    
    if (s1[pos] != s2[pos]) break;
    ++pos;
  }
  for (int i = pos; i < n; ++i) {
    if (s1[pos] < s2[pos]) {
      if (s1[i] == '?') s1[i] = '9';
      if (s2[i] == '?') s2[i] = '0';
    } else {
      if (s1[i] == '?') s1[i] = '0';
      if (s2[i] == '?') s2[i] = '9';
    }
  }
  return mp(s1,s2);
}

ll strtoint(string& s) {
  ll res = 0;
  forn(i, sz(s)) res = res * 10 + s[i] - '0';
  return res;
}

ll ABS(ll x) {
  if (x < 0) return -x;
  return x;
}

bool cmp(pair<string, string> p1, pair<string, string> p2) {
  ll d1 = ABS(strtoint(p1.X) - strtoint(p1.Y));
  ll d2 = ABS(strtoint(p2.X) - strtoint(p2.Y));
  if (d1 != d2) return d1 < d2;
  return p1 < p2;
}


pair<string, string> bestres;

void rec(string& s1, string& s2, int pos) {
  if (pos == sz(s1) * 2) {
    if (cmp(mp(s1, s2), bestres)) bestres = mp(s1, s2);
    return;
  }
  if (pos < sz(s1)) {
    if (s1[pos] == '?') {
      forn(i, 10) {
        s1[pos] = i + '0';
        rec(s1,s2,pos+1);
      }
      s1[pos] = '?';
    } else rec(s1, s2, pos+1);
  } else {
    int rpos = pos - sz(s1);
    if (s2[rpos] == '?') {
      forn(i, 10) {
        s2[rpos] = i + '0';
        rec(s1, s2, pos + 1);
      }
      s2[rpos] = '?';
    } else rec(s1,s2,pos+1);
  }
}

pair<string, string> solvebrute(string s1, string s2) {
  bestres = mp("0000", "9999");
  rec(s1, s2, 0);
  return bestres;
}

void solve() {
  string s1, s2; cin >> s1 >> s2;
  pair<string, string> best = solvestupid(s1, s2);
  forn(i, sz(s1)) {
    for (int tt = -1; tt <= 1; tt += 2) {
      string t1 = s1;
      string t2 = s2;
      if (t1[i] == '?' && t2[i] == '?') {
        t1[i] = '0';
        t2[i] = '0' + (t1[i] - '0' + tt + 10) % 10;
        pair<string,string> curres = solvestupid(t1,t2);
        if (cmp(curres, best)) best = curres;
        t2[i] = '0';
        t1[i] = '0' + (t2[i] - '0' + tt + 10) % 10;
      } else if (t2[i] == '?') {
        t2[i] = '0' + (t1[i] - '0' + tt + 10) % 10;
      } else if (t1[i] == '?') {
        t1[i] = '0' + (t2[i] - '0' + tt + 10) % 10;
      }
      pair<string,string> curres = solvestupid(t1,t2);
      if (cmp(curres, best)) best = curres;
    }
  }
  /*pair<string,string> tres = solvebrute(s1,s2);
  if (tres != best) {
    printf("FAIL!!!\n");
    cout << s1 << " " << s2 << endl;
    cout << best.X << " " << best.Y << endl;
    cout << tres.X << " " << tres.Y << endl;
    exit(0);
  }*/
  cout << best.X << " " << best.Y << endl;
}



int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
  //pair<string, string> ttt = solvebrute("?5", "?9");
  //cout << ttt.X << " " << ttt.Y << endl;
  //return 0;
  int T; scanf("%d", &T);
  for (int tn = 1; tn <= T; ++tn) {
    printf("Case #%d: ", tn);
    solve();
  }
	return 0;
}