#include <cstdio>
#include <algorithm>

using namespace std;

int size[100];

int run(int a, int n) {
  unsigned long long int mote = a;
  int result = n;
  int ops = 0;
  int i=0;
  sort(size, size+n);
  while (i<n) {
    //    printf("%d %llu\n",i,mote);
    if (size[i] < mote) {
      mote += size[i++];
    } else {
      ops++;
      if (mote == 1)
	return result;
      mote += mote-1;
    }
    result = min(result,ops+n-i); 
  }
  return result;
}

int main()
{
  int T,A,N;
  scanf("%d",&T);
  for (int i=1; i<=T; i++) {
    scanf("%d%d",&A, &N);
    for (int j=0; j<N; j++)
      scanf("%d",&size[j]);
    printf("Case #%d: %d\n",i, run(A, N));
  }
}
