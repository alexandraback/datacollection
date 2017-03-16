#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int main() {
  int T;
  cin>>T;
  for (int t=1;t<=T;t++) {
    int D;
    cin>>D;
    vector<int> nums(D);
    for (int i=0;i<D;i++){
      cin>>nums[i];
    }
    int best = 1000;
    for (int i=1;i<1000;i++) {
      if (best<=i) break;
      int cur = i;
      for (int j=0;j<D;j++) {
	cur+=(nums[j]-1)/i;
      }
      if (cur<best) best = cur;
    }
    printf("Case #%d: %d\n", t, best);
  }
}
