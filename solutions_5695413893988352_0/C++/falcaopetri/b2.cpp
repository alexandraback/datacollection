#include <bits/stdc++.h>
using namespace std;

typedef pair<string, string > ss;
typedef long long ll;
typedef pair<ll, ll> llll;
typedef unsigned long long ull;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define FOR(i,a,b) for(int (i) = (a); (i) < (b); ++(i))

#define INF 0x3f3f3f3f
#define MAX -1

#define DEBUG false
#define debug(x) if (DEBUG) cout << #x << " = (" << x << ")\n"

string str1, str2;

vector<ss> v;
bool solve(int curr) {
    if (curr == str1.size()) { v.push_back(ss(str1, str2)); return true; }

    int i = str1.size() - curr - 1;
    char &ii = str1[i];
    char &jj = str2[i];
    char ii_last = ii;
    char jj_last = jj;
    if (ii == jj && ii == '?') {
        for (int a = '0'; a <= '9'; ++a) {
            ii = a;
            for (int b = '0'; b <= '9'; ++b) {
                jj = b;
                if (solve(curr+1));
                //return true;
            }
        }
    }
    else if (ii == '?') {
        for (int a = '0'; a <= '9'; ++a) {
            ii = a;
            if (solve(curr+1));
            //  return true;
        }
    }
    else if (jj == '?') {
        for (int a = '0'; a <= '9'; ++a) {
            jj = a;
            if (solve(curr+1)) ;
            // return true;
        }
    }
    else {
        if (solve(curr+1)) ;
        // return true;
    }
    ii = ii_last;
    jj = jj_last;
    return false;
}

bool comp(const ss &pp1, const ss &pp2) {
      llll p1;
      sscanf(pp1.first.c_str(), "%ld", &p1.first);
      sscanf(pp1.second.c_str(), "%ld", &p1.second);
    //   cout <<"P:"<< abs(p1.first-p1.second) << endl;
      llll p2;
      sscanf(pp2.first.c_str(), "%ld", &p2.first);
      sscanf(pp2.second.c_str(), "%ld", &p2.second);
    //   cout <<"P2:"<< abs(p2.first-p2.second) << endl;
      if (abs(p1.first - p1.second) < abs(p2.first-p2.second)) {
          return true;
      }
      else if (abs(p1.first - p1.second) > abs(p2.first-p2.second)) {
          return false;
      }
      else {
          if (p1.first < p2.first) {
              return true;
          }
          else if (p1.first > p2.first) {
              return false;
          }
          else {
              return p1.second < p2.second;
          }
      }
}
int main() {
  ios::sync_with_stdio(false);

  int T; cin >> T;

  FOR(t,1,T+1) {
      string _str1, _str2;
      cin >> _str1 >> _str2;

      // sort str1 e str2 -> str1 tem que ser < str2
      str1 = _str1;
      str2 = _str2;
    //   ss pp1 = 0;
      v.clear();
      solve(0);
      sort(v.begin(), v.end(), comp);
    //   cout << "S: " << v.size() << endl;
    //   FOR(i,0,v.size()) {
    //       cout << v[i].first << " " << v[i].second << endl;
    //   }
    //   ss pp2 =
    //   solve(0);

    //   llll p1;
    //   sscanf(pp1.first.c_str(), "%ld", &p1.first);
    //   sscanf(pp1.second.c_str(), "%ld", &p1.second);
    // //   cout <<"P:"<< abs(p1.first-p1.second) << endl;
    //   llll p2;
    //   sscanf(pp2.first.c_str(), "%ld", &p2.first);
    //   sscanf(pp2.second.c_str(), "%ld", &p2.second);
    // //   cout <<"P2:"<< abs(p2.first-p2.second) << endl;
    //   if (abs(p1.first - p1.second) < abs(p2.first-p2.second)) {
    //       str1 = pp1.first; str2 = pp1.second;
    //   }
    //   else if (abs(p1.first - p1.second) > abs(p2.first-p2.second)) {
    //       str2 = pp2.first; str1 = pp2.second;
    //   }
    //   else {
    //       if (p1.first < p2.first) {
    //           str1 = pp1.first; str2 = pp1.second;
    //       }
    //       else {
    //           str2 = pp2.first; str1 = pp2.second;
    //       }
    //   }


      cout << "Case #"  << t << ": " << v[0].first << " " << v[0].second << endl;
    //   cout << "Case #"  << t << ": " << pp1.first << " " << pp1.second << endl;
    //   cout << "Case #"  << t << ": " << pp2.first << " " << pp2.second << endl;
    // cout << endl;
  }

  return 0;
}
