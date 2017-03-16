#include <cstdio>
#include <vector>

using namespace std;

int main() {
  int T;
  scanf("%d",&T);
  for (int n=1;n<=T;++n) {
    int Smax;
    scanf("%d",&Smax);
    char c;
    do {
      scanf("%c",&c);
    } while (c<'0' || c>'9');
    int sol=0,sum=0;
    for (int k=0;k<Smax;++k) {
      int level=c-'0';
      sum+=level;
      if (sum<k+1) { sol+=k+1-sum; sum=k+1; }
      scanf("%c",&c);
    }
    printf("Case #%d: %d\n",n,sol);
  }
  return 0;
}

