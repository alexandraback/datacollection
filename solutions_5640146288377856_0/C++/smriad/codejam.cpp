#include<iostream>
#include<algorithm>


using namespace std;

int main() {
	long long t, a, b, c, i;
	cin >> t;
	for (i = 0; i < t; i++) {
		cin >> a >> b >> c;
		if (b == c)
			cout << "Case #" << i + 1 << ": " << a - 1 + c << endl;
		else if (c == 1)
			cout << "Case #" << i + 1 << ": " << a * b << endl;
		else
			cout << "Case #" << i + 1 << ": " << (a * (b - 1)) / c + c << endl;
	}
}
