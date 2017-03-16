#include <iostream>

using namespace std;

int high[10];
int low[10];

int main(){
	int t; cin >> t;
	for (int zz = 1; zz <= t; zz++){
		int a, b;
		cin >> a >> b;
		int at = a, bt = b;
		int pow10 = 1;
		int nd = 0;
		while (a != 0){
			high[nd] = b % 10;
			b /= 10;
			low[nd] = a % 10;
			a /= 10;
			pow10 *= 10;
			nd++;
		}
		a = at, b = bt;
		pow10 /= 10;
		int cnt = 0;
		for (int i = a; i <= b; i++){
			int j = i;
			bool done = false;
			while (!done){
				int last = j % 10;
				j = (j/10) + last * pow10;
				if (i < j && j <= b) cnt++;
				if (i == j) done = true;
			}
		}
		cout << "Case #" << zz << ": " << cnt << endl;
	}

	return 0;
}
