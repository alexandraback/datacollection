#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;

int T,Cas=0;
int A,B,K,total;

int main() {
	scanf("%d",&T);
	while (T--) {
    scanf("%d%d%d",&A,&B,&K);
    total=0;
    for (int i=0;i<A;i++)
      for (int j=0;j<B;j++)
        if ((i&j)<K)
          total++;
    printf("Case #%d: %d\n", ++Cas, total);
	}
}