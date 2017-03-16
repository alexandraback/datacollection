#include<iostream>
#include<map>;
using namespace std;

int main() {
  int T;
  scanf("%d",&T);
  for(int kase=0;kase<T;kase++) {
    map<int,int> sums;
    int N;
    scanf("%d",&N);
    int num[N];
    sums.clear();
    for(int i=0;i<N;i++) scanf("%d",&num[i]);
    cout << "Case #" << kase + 1 << ": ";
    bool done = false;
    for(int mask = 1; mask < (1<<N) ; mask ++) {
      int sumO = 0;
      for(int j=0;j<N;j++)
      {
        if (mask&(1<<j)) {
          sumO += num[j];
        }
      }
      if (sums.count(sumO) != 0) {
        cout << "\n";
        done = true;
        for(int j=0;j<N;j++) {
          if (mask & (1<<j)) {
            cout << num[j] << " ";
          }
        }
        cout << "\n";
        int mask2 = sums[sumO];
        for (int j = 0;j< N; j++) {
          if ( (1<<j) & mask2) {
            cout << num[j] << " ";
          }
        }
        cout << "\n";
      }
      if (done) break;
      sums[sumO] = mask;
    }
    if (!done) cout << "Impossible\n";
  }
}
