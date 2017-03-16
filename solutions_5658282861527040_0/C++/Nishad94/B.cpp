#include<string>
#include<vector>
#include<iostream>

using namespace std;

int main()
{
  int T;
  cin >> T;
  for(int t = 1; t <= T; ++t){
    int A, B, K;
    cin >> A >> B >> K;
    long long ans = 0;
    for(int a = 0; a < A; ++a){
      for(int b = 0; b < B; ++b){
	if((a & b) < K){
	  //cout << a << " " << b << " " << (a & b) <<  endl;
	  ++ans;
	}
      }
    }
    cout << "Case #" << t << ": " << ans << endl;
  }
  return 0;
}
