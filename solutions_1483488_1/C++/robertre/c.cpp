#include <iostream>
#include <set>

using namespace std;

int POWERS[] = {
  1,
  10,
  100,
  1000,
  10000,
  100000,
  1000000,
  10000000,
  100000000,
  1000000000
};

int sizeA(int A) {
  for(int i=0;i<8;++i) {
    if(A<POWERS[i]) {
      return i;
    }
  }
}

int acceptable(int n, int m, int A, int B) {
  return (A <= n && n < m && m <= B);
}

int cycle(int n, int digits, int szA) {
  int low = n / POWERS[digits];
  int high = n % POWERS[digits];
  int res = high * POWERS[szA-digits] + low;
  return res;
}

int nrecy(int n, int A, int B, int szA) {
  set<int> res;
  for(int i=1;i<szA;++i) {
    int m = cycle(n, i, szA);
    if (acceptable(n, m, A, B)) {
      res.insert(m);
    }
  }
  return res.size();
}

int solve(int A, int B) {
  int n = 0;
  int szA = sizeA(A);
  for(int i=A;i<=B;++i) {
    n += nrecy(i, A, B, szA);
  }
  return n;
}

int main(int argc, char** argv) {
  int ntc;
  cin>>ntc;
  for(int tc=0;tc<ntc;++tc) {
    int low, high;
    cin>>low>>high;
    int res = solve(low, high);
    cout<<"Case #"<<tc+1<<": "<<res<<endl;
  }
  return 0;
}
