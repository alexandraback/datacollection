
#include <stdio.h>

#include <vector>

#include <algorithm>

using namespace std;

main() {


  int T;

  scanf("%d",&T);

  for (int t = 1; t <= T; t++) {
    vector <long long int> motes;
    long long int A;
    int N;

    scanf("%lld %d", &A,&N);

    for (int i = 0; i < N; i++) {
      long long int x;
      scanf("%lld", &x);
      motes.push_back(x);      
    }
    
    sort(motes.begin(),motes.end());

    int count = 0;
    
    int min = N;
    
    if (A != 1) {
      for (int i = 0; i < N; i++) {
	
	//printf("mote %d = %lld\n",i,motes[i]);
	
	while (motes[i] >= A)  {
	  // printf("%lld , %lld\n",A,motes[i]);
	  A = A + A - 1;
	  count++;
	}
	
	if (motes[i] < A) {
	  A += motes[i];
	}
	
	if (N-i + count -1 < min) {
	  min = N - i + count - 1;
	}
      }
    }
    printf("Case #%d: %d\n",t,min);

  }


}
