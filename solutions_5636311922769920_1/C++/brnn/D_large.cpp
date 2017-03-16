#include <iostream> 
using namespace std;

void solve_case(int T){
	unsigned long long K, C, S, rem, d1, d2, out;
	cin >> K >> C >> S;

	cout << "Case #" << T << ": ";

	if (S * C < K){
		cout << "IMPOSSIBLE" << endl;
		return;
	} if (C >= K){
		out = 0;
		for (int i = 1; i < K; i++){
			out = K * out + i;
		}
		out++;
		cout << out << endl;
		return;
	}

	rem = K % C;
	d1 = 1;
	d2 = 1;
	out = 0;
	for (int i = 1; i < C; i++){
		d1 = K * d1 + 1;
		out = K * out + i;
		if (i < rem){
			d2 = K * d2 + 1;
		} else {
			d2 *= K;
		}
	}
	d1 *= C;
	d2 *= C;
	out++;

	for (int i = 1; i * C < K; i++){
		if (i > 1){
			out += d1;
		}
		cout << out << " ";
	}
	out += d2;
	cout << out << " ";

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