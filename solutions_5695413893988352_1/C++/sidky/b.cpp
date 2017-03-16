#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <list>
using namespace std;
 
#define  rep(i,n)  for((i) = 0; (i) < (n); (i)++)
#define  rab(i,a,b)  for((i) = (a); (i) <= (b); (i)++)
#define all(v)    (v).begin(),(v).end()
#define  Fi(n)    rep(i,n)
#define  Fj(n)    rep(j,n)
#define  Fk(n)    rep(k,n)
#define  sz(v)    (v).size()

char s1[100], s2[100];
int len;

string minimize(char* s) {
  string n = "";

  for (int i = 0; s[i]; i++) {
    char c;

    if (s[i] == '?') c = '0';
    else c = s[i];

    n = n + (char)c;
  }
  return n;
}

string maximize(char* s) {
  string n;

  for (int i = 0; s[i]; i++) {
    char c;

    if (s[i] == '?') c = '9';
    else c = s[i];

    n = n + (char)c;
  }
  return n;
}

long long absolute(long long x) {
  return (x < 0 ? -x : x);
}

long long value(string s) {
  long long n = 0;

  for (int i = 0; i < sz(s); i++) {
    n = n * 10 + (s[i] - '0');
  }
  return n;
}

long min_diff_val[20];
string pick1[20], pick2[20];
long power[20];

void get_difference() {
  min_diff_val[len] = 0;
  pick1[len] = "";
  pick2[len] = "";

  int i,j,k;

  power[len - 1] = 1;

  for (k = len - 2; k >= 0; k--) power[k] = 10 * power[k + 1];

  for (int k = len - 1; k >= 0; k--) {
    bool flag = false;

    for (i = 0; i <= 9; i++) {
      if (s1[k] != '?' && s1[k] - '0' != i) continue;

      for (j = 0; j <= 9; j++) {
        if (s2[k] != '?' && s2[k] - '0' != j) continue;

        if (i == j) {
          long p = (i - j) * power[k] + min_diff_val[k + 1];
          long diff1 = absolute(p);
          long diff2 = absolute(min_diff_val[k]);
          string p1 = (char)(i + '0') + pick1[k + 1];
          string p2 = (char)(j + '0') + pick2[k + 1];

          if (flag == false || diff1 < diff2 || (diff1 == diff2 && p2 < pick2[k])) {
            flag = true;
            min_diff_val[k] = p;
            pick1[k] = p1;
            pick2[k] = p2;
          }
        } else {
          string p1,p2;
          if (i > j) {
            p1 = (char)(i + '0') + minimize(s1 + k + 1);
            p2 = (char)(j + '0') + maximize(s2 + k + 1);
          } else {
            p1 = (char)(i + '0') + maximize(s1 + k + 1);
            p2 = (char)(j + '0') + minimize(s2 + k + 1);
          }
          //cout << "'" << p1 << "' '" << p2 << "'" << endl;
          long d = value(p1) - value(p2);
          long diff1 = absolute(d);
          long diff2 = absolute(min_diff_val[k]);

          if (flag == false || diff1 < diff2 || (diff1 == diff2 && p2 < pick2[k])) {
            flag = true;
            min_diff_val[k] = d;
            pick1[k] = p1;
            pick2[k] = p2;
          }
        }

        //cout << k << " " << i << " " << j << " " << min_diff_val[k] << " " << pick1[k] << " " << pick2[k] << " " << flag << endl;
      }
    }
    //cout << k << ":" << min_diff_val[k] << ":" << pick1[k] << ":" << pick2[k] << endl;
  }
}

int main() {
	int T,cs;

	scanf("%d",&T);

	rab(cs,1,T) {
    scanf("%s %s",s1,s2);
    len = strlen(s1);

    get_difference();

    cout << "Case #" << cs << ": " << pick1[0] << " " << pick2[0] << endl;
	}

} 
