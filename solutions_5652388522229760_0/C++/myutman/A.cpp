#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	for (int i = 0; i < t; i++){
		long long n;
		cin >> n;
		if (n == 0){
			cout << "case #" << i + 1 << ": INSOMNIA\n";
			continue;
		}
		bool b[10];
		for (int i = 0; i < 10; i++) b[i] = false;
		int ct = 10;
		long long z = n;
		while (ct > 0){
			long long x = z;
			while (x > 0){
				cerr << x << "\n";
				if (!b[x % 10]){
					b[x % 10] = true;
					cerr << x % 10 << "\n";
					ct--;
				}
				x /= 10;
			}
			z += n;
		}
		cout << "case #" << i + 1 << ": " << z - n << "\n";
	}
	return 0;
}