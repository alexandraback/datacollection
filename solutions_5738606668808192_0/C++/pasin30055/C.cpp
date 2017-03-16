#include <iostream>
#include <cstdio>
#include <iomanip> 

using namespace std;

int tests;
int n, j;
long long div[11];

int main() {
    cin >> tests;
    for (int t = 0 ; t < tests ; t ++) {
	cin >> n >> j;
	cout << "Case #" << t + 1 << ":" << endl;
	for (int i = 2 ; i <= 10 ; i ++) {
	    div[i] = 1;
	    for (int k = 0 ; k < n/2 ; k ++) div[i] *= i;
	    div[i] += 1;
	}
	for (int i = 0 ; i < j ; i ++) {
	    int tmp = (1<<(n/2 - 1)) + (i<<1) + 1;
	    for (int k = 0 ; k < 2 ; k ++) {
		for (int l = n/2 - 1 ; l >= 0 ; l --) {
		    cout << (((1<<l)&tmp) != 0) ? '1' : '0';
		}
	    }
	    for (int k = 2 ; k <= 10 ; k ++) cout << " " << div[k];
	    cout << endl;
	}
    }
    return 0;
}
