#include <iostream>
using namespace std;

int main(){
	int t, tt = 1;
	for(cin >> t; t; t--, tt++){
		long long int n, m;
		cin >> n;
		m = n;
		if(n == 0){
			cout << "Case #" << tt << ": INSOMNIA\n";
			continue;
		}
		bool v[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
		int i = 1;
		while(1){
			m = i++ * n;
			long long int p = m;
			while(p){
				v[p % 10] = 1;
				p /= 10;
			}
			bool res = 1;
			for(int j = 0; j < 10; j++)
				res = res && v[j];
			if(res)
				break;
		}
		cout << "Case #" << tt << ": " << m << endl;
	}

	return 0;
}