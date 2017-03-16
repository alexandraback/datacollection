#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const ll MAX=10000000000000000000ULL;
string smallest(string x) {
  stringstream s;
  for (int i=0; i < x.size(); i++) {
    if (x[i] == '?') s << '0';
    else s << x[i];
  }
  return s.str();
}
string largest(string x) {
  stringstream s;
  for (int i=0; i < x.size(); i++) {
    if (x[i] == '?') s << '9';
    else s << x[i];
  }
  return s.str();
}
ll diff(string a, string b) {
  return stoull(a)-stoull(b);
}
void solve(string C, string J, stringstream &A, stringstream &B) {
  int N = C.size();
  if (N == 0) return;
  if (N == 1) {
    if (C[0] == '?' && J[0] == '?') {
      A << '0';
      B << '0';
    } else if (C[0] == '?') {
      A << J[0];
      B << J[0];
    } else if (J[0] == '?') {
      A << C[0];
      B << C[0];
    } else {
      A << C[0];
      B << J[0];
    }
    return;
  }

  if (C[0] != '?' && J[0] != '?') {
    if (C[0] == J[0]) {
      A << C[0];
      B << J[0];
      solve(C.substr(1), J.substr(1), A, B);
    } else if (C[0] > J[0]) {
      A << smallest(C);
      B << largest(J);
    } else {
      A << largest(C);
      B << smallest(J);
    }
  } else {
    string CC = C.substr(1), JJ = J.substr(1);
    stringstream AA, BB;
    solve(CC, JJ, AA, BB);
    ll a, b; AA >> a; BB >> b;
    ll d = a > b ? a-b : b-a;
    ll x = MAX, y = MAX;
    if (C[0] != '9' && J[0] != '0') {
      char c, j;
      if (C[0] == '?' && J[0] == '?') c = '0', j = '1';
      else if (C[0] == '?') c = J[0]-1, j = J[0];
      else if (J[0] == '?') c = C[0], j = C[0]+1;
      x = diff(string(1,j)+smallest(JJ), string(1,c)+largest(CC));
    }
    if (C[0] != '0' && J[0] != '9') {
      char c, j;
      if (C[0] == '?' && J[0] == '?') c = '1', j = '0';
      else if (C[0] == '?') c = J[0]+1, j = J[0];
      else if (J[0] == '?') c = C[0], j = C[0]-1;
      y = diff(string(1,c)+smallest(CC), string(1,j)+largest(JJ));
    }
    if (C[0] == '?' && J[0] == '?' && d <= x && d <= y) {
      stringstream AA, BB;
      solve(CC, JJ, AA, BB);
      A << '0' << AA.str();
      B << '0' << BB.str();
    } else if (C[0] != '?') {
      if (y <= d && y <= x) {
        char c, j;
        if (C[0] == '?' && J[0] == '?') c = '1', j = '0';
        else if (C[0] == '?') c = J[0]+1, j = J[0];
        else if (J[0] == '?') c = C[0], j = C[0]-1;
        A << c << smallest(CC);
        B << j << largest(JJ);
      } else if (d <= x) {
        char c, j;
        if (C[0] == '?' && J[0] == '?') c = '0', j = '0';
        else if (C[0] == '?') c = J[0], j = J[0];
        else if (J[0] == '?') c = C[0], j = C[0];
        stringstream AA, BB;
        solve(CC, JJ, AA, BB);
        A << c << AA.str();
        B << j << BB.str();
      } else {
        char c, j;
        if (C[0] == '?' && J[0] == '?') c = '0', j = '1';
        else if (C[0] == '?') c = J[0]-1, j = J[0];
        else if (J[0] == '?') c = C[0], j = C[0]+1;
        A << c << largest(CC);
        B << j << smallest(JJ);
      }
    } else if (x <= d && x <= y) {
      char c, j;
      if (C[0] == '?' && J[0] == '?') c = '0', j = '1';
      else if (C[0] == '?') c = J[0]-1, j = J[0];
      else if (J[0] == '?') c = C[0], j = C[0]+1;
      A << c << largest(CC);
      B << j << smallest(JJ);
    } else if (d <= y) {
      char c, j;
      if (C[0] == '?' && J[0] == '?') c = '0', j = '0';
      else if (C[0] == '?') c = J[0], j = J[0];
      else if (J[0] == '?') c = C[0], j = C[0];
      stringstream AA, BB;
      solve(CC, JJ, AA, BB);
      A << c << AA.str();
      B << j << BB.str();
    } else {
      char c, j;
      if (C[0] == '?' && J[0] == '?') c = '1', j = '0';
      else if (C[0] == '?') c = J[0]+1, j = J[0];
      else if (J[0] == '?') c = C[0], j = C[0]-1;
      A << c << smallest(CC);
      B << j << largest(JJ);
    }
  }
}
int main() {
  int T; cin >> T;
  for (int zz=1; zz <= T; zz++) {
    cout << "Case #" << zz << ": ";
    string C, J; cin >> C >> J;
    stringstream A, B;
    solve(C, J, A, B);
    cout << A.str() << " " << B.str() << endl;
  }
  return 0;
}
