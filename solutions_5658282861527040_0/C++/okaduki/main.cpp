#include <iostream>

using namespace std;

int main(){
  int TestCase;
  cin >> TestCase;
  for(int test=1;test<=TestCase;++test){
	int A, B, K;
	cin >> A >> B >> K;

	int res = 0;
	for(int a=0;a<A;++a){
	  for(int b=0;b<B;++b){
		if((a & b)<K) ++res;
	  }
	}

	cout << "Case #" << test << ": " << res << endl;
  }

  return 0;
}
