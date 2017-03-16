#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ABS(A,B)  (((A) >= (B)) ? ((A)-(B)) : ((B)-(A)))
#define UP(X,Y)  ((X)*10 + (Y))
using namespace std;
typedef unsigned long long ull;
string A, B;
ull a1, b1, ans;

void go(ull pos, ull a, ull b) {
  if (pos == A.size()) {
    //    cout << a << " " << b << endl;
    if (ABS(a,b) < ans) {
      a1 = a;
      b1 = b;
      ans = ABS(a,b);
      return;
    } else if (ABS(a,b) == ans) {
      if (a < a1) {
	a1 = a;
	b1 = b;
	ans = ABS(a,b);
      } else if (a == a1 && b < b1) {
	a1 = a;
	b1 = b;
	ans = ABS(a,b);
      }
    }
    return;
  }
  if (A[pos] == '?' && B[pos] == '?') {
    go(pos+1, UP(a,0), UP(b,9));
    go(pos+1, UP(a,9), UP(b,0));
    go(pos+1, UP(a,0), UP(b,0));
    if (A.size() != pos+1) {
      if(A[pos+1] == '9'){
	go(pos+1, UP(a,0), UP(b,1));
      }
      if(B[pos+1] == '9'){
	go(pos+1, UP(a,1), UP(b,0));
      }
    }
  }
  if (A[pos] == '?' && B[pos] != '?') {
    if (a>b)
      go(pos+1, UP(a,0), UP(b,B[pos]-'0'));
    if (a<b)
      go(pos+1, UP(a,9), UP(b,B[pos]-'0'));
    if (a==b) {
      go(pos+1, UP(a,B[pos]-'0'), UP(b,B[pos]-'0'));
      if (B[pos] != '9')
	go(pos+1, UP(a,B[pos]-'0'+1), UP(b,B[pos]-'0'));
      if (B[pos] != '0')
	go(pos+1, UP(a,B[pos]-'0'-1), UP(b,B[pos]-'0'));
    }
  }
  if (A[pos] != '?' && B[pos] == '?') {
    if (b>a)
      go(pos+1, UP(a,A[pos]-'0'), UP(b,0));
    if (b<a)
      go(pos+1, UP(a,A[pos]-'0'), UP(b,9));
    if (a==b) {
      go(pos+1, UP(a,A[pos]-'0'), UP(b,A[pos]-'0'));
      if (A[pos] != '9')
	go(pos+1, UP(a,A[pos]-'0'), UP(b,A[pos]-'0'+1));
      if (A[pos] != '0')
	go(pos+1, UP(a,A[pos]-'0'), UP(b,A[pos]-'0'-1));
    }
  }
  if (A[pos] != '?' && B[pos] != '?') {
    go(pos+1, UP(a,A[pos]-'0'), UP(b,B[pos]-'0'));
  }
}

int main() {_;
  int T;
  cin >> T;
  
  for (int t=1; t<=T; t++) {
    cin >> A >> B;
    a1 = b1 = 0;
    ans = ULLONG_MAX;
    go(0,0,0);
    cout << "Case #" << t << ": ";
    cout << setfill('0') << setw(A.size()) << a1;
    cout << " ";
    cout << setfill('0') << setw(A.size()) << b1;
    cout << endl;
  }
  return 0;
}
