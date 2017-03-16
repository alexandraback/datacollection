#include <iostream>

using namespace std;

main() {
  int T;
  cin >> T;
  for (int t=1; t<=T; t++) {
    int N, M, K;

    cin >> N >> M >> K;
    int MAX=1<<(N*M);

    int answer=N*M;
    for (int s=0; s<MAX; s++) {
      int size=0;
      for (int S=s; S>0; S>>=1)	if (S&1) size++;

      //            cout << "set=" << s << " size=" << size << endl;

      int stones=0;
      if (size>=K) {
	for (int i=0; i<N; i++)
	  for (int j=0; j<M; j++)
	    if (s&(1<<(i*M+j))) // set at i,j?
	      { 
		if (i==0 || i==N-1 || j==0 || j==M-1 
		    || ((s&(1<<((i-1)*M+j)))==0)
		    || ((s&(1<<((i+1)*M+j)))==0)
		    || ((s&(1<<(i*M+j+1)))==0)
		    || ((s&(1<<(i*M+j-1)))==0))
		  stones++;
	      }
	answer=min(answer,stones);
      }
    };
    
    cout << "Case #" << t << ": " << answer << endl;
  };
};
