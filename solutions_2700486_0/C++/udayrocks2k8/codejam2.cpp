#include <iostream>
#include <algorithm>
using namespace std;

void getResult() {
    int n, x, y;
    cin >> n >> x >> y;
    int pile = (abs(x) + y) / 2;
    int temp = n;
    int a = 1;
    int pos = -1;
    while (temp >= a) {
        temp -= a;
        a += 4;
        pos++;
    }
    if (pile <= pos) {
        cout << 1.0 << endl;
        return;
    }
    if (pile > (pos + 1)) {
        cout << 0.0 << endl;
        return;
    }
    if (x == 0) {
        cout << 0.0 << endl;
        return;
    }
    
    if (a / 2 + y < temp) {
        cout << 1.0 << endl;
        return;
    }
    if (y > temp) {
        cout << 0.0 << endl;
        return;
    }
    double prob = 0, p = 1, ar = 1;
    for (int i = 1; i <= y; i++) {
        p *= 0.5;
    }
    for (int i = y + 1; i <= temp; i++) {
        p *= 0.5;
        prob += ar * p;
        ar *= (i / (double)(i - y));
    }
    cout << prob << endl;
}



int main() {
	int testCases;
	cin >> testCases;
	for (int i = 1; i <= testCases; i++) {
		cout << "Case #" << i << ": ";
		getResult();
	}
	return 0;
}