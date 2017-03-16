#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define REP(i, to) for(int i=0; i<to; ++i)

typedef double LD; 

int main()
{
    int T;
    cin >> T;
    REP(cas, T){
      int A, B;
      cin >> A >> B;
      LD p = 1.0;
      LD pbest = min(A+B+1, 1+B+1);
      
      for(int i=1; i<=A; i++){
        LD d;
        cin >> d;
        p *= d;
        LD fin = A-i+B-i+1;
        pbest = min(pbest, p*(fin) + (1-p)*(LD)(fin + B + 1));
      }
      printf("Case #%d: %.8lf\n", cas+1, pbest);
    }

  	return 0;
}
