#include <cstdio>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long i64;

int main(int argc, char *argv[]){
  int T;
  cin >> T;

  for(int t=1;t<=T;t++) {
    printf("Case #%d: ", t);
    
    int N, S, p;
    cin >> N >> S >> p;

    int s1, s2;
    s1 = s2 = 0;
    for(int i=0;i<N;i++) {
      int total;
      cin >> total;
      if(total == 0) {
	if(p == 0)
	  s1++;
      }
      else if(total == 1) {
	if(p <= 1)
	  s1++;
      }
      else if(3 * p <= total + 2)
	s1++;
      else if(3 * p <= total + 4)
	s2++;
    }

    cout << (s1 + min(s2, S)) << endl;
  }

  return 0;
}
