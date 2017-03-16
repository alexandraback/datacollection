// Sheep
// 9:07

#include <iostream>



using namespace std;

int main() {
  int T;
  cin >>T;
  for(int i = 1; i <= T; i++) {
    long long n;
    cin >> n;
    long long m = 0;
    if (n==0) {
      cout << "Case #" << i << ": " << "INSOMNIA" << endl;
    }
    else {
      bool seen[10];
      for(int j = 0; j < 10; j++) {
	seen[j]=false;
      }
      bool done=false;
      while (!done) {
	m+=n;
	long long k = m;
	while (k>0) {
	  seen[k%10] = true;
	  k/=10;
	}
	done = true;
	for(int j = 0; j<10; j++) {
	  done = done && seen[j];
	}
      }
      cout << "Case #" << i << ": " << m << endl;
    }
  }
  return 0;
}
    
