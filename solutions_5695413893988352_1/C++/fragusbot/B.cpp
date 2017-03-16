#include <bits/stdc++.h>

using namespace std;

int n;
int d;
string ansa, ansb;
long long diff;
string a, b;

void work(int j) {
  string cura = "", curb = "";
  for (int i = 0; i < j; ++i) {
    cura += a[i];
    curb += b[i];
  }
  for (int i = j; i < n; ++i) {
    if (d == -1) {
      if (a[i] == '?') {
        cura += "9";
      } else {
        cura += a[i];
      }
      if (b[i] == '?') {
        curb += "0";
      } else {
        curb += b[i];
      }
    } else {
      if (a[i] == '?') {
        cura += "0";
      } else {
        cura += a[i];
      }
      if (b[i] == '?') {
        curb += "9";
      } else {
        curb += b[i];
      }
    }
  }
 //printf("\n");
  //cout << cura << " " << curb << endl;
  /*if (j == n) {
    printf("aa = %s\n", cura.c_str());
    printf("bb = %s\n", curb.c_str());
  }*/
  assert(cura.length() == n);
  assert(curb.length() == n);
  long long aa = 0, bb = 0;
  for (int i = 0; i < n; ++i) {
    aa = aa * 10 + cura[i] - '0';
    bb = bb * 10 + curb[i] - '0';
  }
  /*
  if (j == n) {
    printf("aa = %lld\n", aa);
    printf("bb = %lld\n", bb);
  }
  */
  long long curdiff = aa - bb;
  if (curdiff < 0) curdiff = -curdiff;
  /*cout << "aa = " << aa << endl;
 cout << "bb = " << bb << endl;
 cout << "dd = " << curdiff << endl;
 printf("\n");
 */
  if (curdiff < diff) {
    diff = curdiff;
    ansa = cura;
    ansb = curb;
  } else
  if (curdiff == diff) {
    if (cura < ansa) {
      diff = curdiff;
      ansa = cura;
      ansb = curb;
    } else
    if (curb < ansb) {
      diff = curdiff;
      ansa = cura;
      ansb = curb;
    }
  }
}

int main() {
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  freopen("log", "w", stderr);
  int tt;
  scanf("%d", &tt);
  for (int cc = 1; cc <= tt; ++cc) {
    printf("Case #%d: ", cc);
    cin >> a >> b;
    n = a.length();
    d = 0;
    diff = 9223372036854775807LL;
    ansa = "@";
    ansb = "@";
    for (int i = 0; i < n; ++i) {
      if (a[i] != '?' && b[i] != '?') {
        if (a[i] < b[i]) {
          d = -1;
        } else {
          d = 1;
        }
      }
      if (d != 0) {
        work(i + 1);
        break;
      }
      if (a[i] == '?' && b[i] == '?') {
        a[i] = '0';
        b[i] = '1';
        d = -1;
        work(i + 1);
        a[i] = '1';
        b[i] = '0';
        d = 1;
        work(i + 1);
        a[i] = b[i] = '0';
        d = 0;
      } else
      if (a[i] == '?') {
        if (b[i] - '0' + 1 <= 9) {
          a[i] = b[i] + 1;
          d = 1;
          work(i + 1);
        }
        if (b[i] - '0' - 1 >= 0) {
          a[i] = b[i] - 1;
          d = -1;
          work(i + 1);
        }
        a[i] = b[i];
        d = 0;
      } else
      if (b[i] == '?') {
        if (a[i] - '0' + 1 <= 9) {
          b[i] = a[i] + 1;
          d = -1;
          work(i + 1);
        }
        if (a[i] - '0' - 1 >= 0) {
          b[i] = a[i] - 1;
          d = 1;
          work(i + 1);
        }
        b[i] = a[i];
        d = 0;
      }
      //cout << "a = " << a << endl;
      //cout << "b = " << b << endl;
    }
    //printf("d = %d\n", d);
    if (d == 0) {
      //cout << "diff = " << diff << endl;
      work(n);
    }
    cout << ansa << " " << ansb << endl;
  }
  return 0;
}