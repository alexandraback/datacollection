#include <iostream> 
using namespace std;

void solve_case(int T){
	unsigned long long K, C, S, p, out = 1;
	cin >> K >> C >> S;

	p = 1;
	for (int i = 0; i < C - 1; i++){
		p *= K;
	}
	cout << "Case #" << T << ": ";
	for (int i = 0; i < K; i++){
		cout << out << " ";
		out += p;
	}
	cout << endl;
}

int main() {
  int t;
  cin >> t; 
  for (int i = 1; i <= t; i++) {
    solve_case(i);
  }
  return 0;
}