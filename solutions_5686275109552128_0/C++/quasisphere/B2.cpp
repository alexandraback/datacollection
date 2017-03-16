#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include<utility>

using namespace std;

int main(void) {
  int64_t T;
  cin >> T;
  for(int64_t t=1;t<=T;t++) {
    int64_t D;
    cin >> D;
    vector<int64_t> a(D);
    for(int64_t i=0;i<D;i++) {
      cin >> a[i];
    }
    int64_t m=1001;
    for(int64_t b=1;b<=1000;b++) {
      int64_t moves=b;
      for(int64_t i=0;i<D;i++) {
        if(a[i] > b) {
          moves+=(a[i]+b-1)/b - 1;
        }
      }
      m=min(moves,m);
    }
    cout << "Case #" << t << ": " << m << "\n";
  }
  return 0;
}

