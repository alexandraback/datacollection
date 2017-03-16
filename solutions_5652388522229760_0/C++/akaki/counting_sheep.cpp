#include <bits/stdc++.h> 

using namespace std;

int i, j, k, l, m, n, t;
int digits[10];

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> t;
	for (int test = 0; test < t; test++){
		cin >> n;
		cout << "Case #" << test + 1 << ": ";
		if (n == 0){
			cout << "INSOMNIA\n";
			continue;
		} 
		memset(digits, 0, sizeof(digits));
		for (i = 1; i < 1000; i++){
			int tmp = i * n;
			while (tmp){
				int digit = tmp % 10;
				tmp /= 10;
				digits[digit]++;
			}
			int d = 1;
			for (j = 0; j < 10; j++){
				if (digits[j] == 0) {
					d = 0;
					break;
				}
			}
			if (d){
				cout << i * n <<"\n";
				break;
			}
		} 
	}
	return 0;
}