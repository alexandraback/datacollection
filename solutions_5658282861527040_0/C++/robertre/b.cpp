#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solve() {
  int A, B, K;
  cin>>A>>B>>K;
  long long int res = 0;
  for(int a=0;a<A;++a) {
    for(int b=0;b<B;++b) {
      if((a&b)<K) {
        res++;
      }
    }
  }
  return res;
}

int main(int argc, char** argv) {
  int ntc = 0;
  cin>>ntc;

  for(int n=1;n<=ntc;++n) {
    long long int r = solve();
    cout<<"Case #"<<n<<": ";
    cout<<r;
    cout<<endl;
  }
}
