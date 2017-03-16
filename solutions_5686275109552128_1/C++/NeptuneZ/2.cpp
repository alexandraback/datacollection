#include<iostream>
using namespace std;

int runtime, n, a[2000];

int calc(int x){
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += (a[i] - 1) / x;
	return sum + x;
}

int main(){
//	freopen("2.in", "r", stdin);
//	freopen("2.out", "w", stdout);
	cin >> runtime;
	for (int run = 1; run <= runtime; run++){
		cin >> n;
		int max = 0;
		for (int i = 0; i < n; i++){
			cin >> a[i];
			if (a[i] > max) max = a[i];
		}
		for (int i = 1; i <= max; i++){
			int temp = calc(i);
			if (temp < max) max = temp;
		}
		cout << "Case #" << run << ": " << max << endl;
	}
}
