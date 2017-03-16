#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int T;
  scanf("%d",&T);
  for (int n=1;n<=T;++n) {
    int D;
    scanf("%d",&D);
    vector<int> P(D);
    int maxv=0;
    for (int i=0;i<D;++i) {
      scanf("%d",&P[i]);
      if (P[i]>maxv) {
	maxv=P[i];
      }
    }
    int minv=0x7fffffff;
    for (int i=1;i<=maxv;++i) {
      int sum=i;
      for (int j=0;j<P.size();++j) sum+=(P[j]+i-1)/i-1;
      if (sum<minv) minv=sum;
    }
    printf("Case #%d: %d\n",n,minv);
  }
  return 0;
}

