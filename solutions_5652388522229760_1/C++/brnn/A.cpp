#include <iostream> 
using namespace std;

void solve_case(int T){
	int N;
	cin >> N;

	bool dig[10] = {0};
	int num = 0, tmp;
	bool insomnia = true, done = true;
	for (int i = 0; i < 100; i++){
		num += N;
		tmp = num;
		while (tmp > 0){
			dig[tmp % 10] = true;
			tmp = tmp/10;
		}

		done = true;
		for (int j = 0; j < 10; j++){
			if (!dig[j]){
				done = false;
			}
		}
		if (done){
			insomnia = false;
			break;
		}
	}

	if (insomnia){
		cout << "Case #" << T << ": " << "INSOMNIA" << endl;
	} else {
		cout << "Case #" << T << ": " << num << endl;
	}
}

int main() {
  int t;
  cin >> t; 
  for (int i = 1; i <= t; i++) {
    solve_case(i);
  }
  return 0;
}