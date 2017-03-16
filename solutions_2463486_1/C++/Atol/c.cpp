#include<algorithm>
#include<cstring>
#include<cstdio>
#include<iostream>
#include<vector>

#define FOR(A, B) for(long long A = 0; A < (B); A++)

using namespace std;

long long N = 10000000;
vector<long long> pals;
long long A, B;

int pal(long long x) {
  long long y = x;
  long long rev = 0;
  while(y) {
    rev *= 10ll;
    rev += y % 10;
    y /= 10;
  }
  return rev == x;
}

void pre() {
  pals.clear();
  for(long long i = 1; i <= N; i++) {
    if(pal(i) && pal(i*i)) pals.push_back(i*i);
  }
}

void solve() {
  cin >> A >> B;
  // cout << "TENHO = " << pals.size() << endl;
  long long cnt = 0;
  for(vector<long long>::iterator it = pals.begin(); it != pals.end(); it++) {
    if(A <= *it && *it <= B) cnt++;
  }
  cout << cnt << endl;
}

int main() {
  pre();
  int num_testes;
  scanf("%d", &num_testes);
  for(int t = 1; t <= num_testes; t++) {
    printf("Case #%d: ", t);
    solve();
  }
  return 0;
}
