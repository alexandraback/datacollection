#include <iostream>

using namespace std;

double freq[100001];


double keep_typing (int a, int b) {
	double correct = 1;
	for (int i = 0; i < a; ++i) {
		correct *= freq[i];
	}
	return correct * (b - a + 1) + (1 - correct) * (b - a + b + 2);
}

double retry_typing (int a, int b) {
	return b + 2;
}

double backn_typing (int a, int b, int n) {
	double pre = 1,
		   pos = 0;
	int    i   = 0;
	for (; i < a - n; ++i) {
		pre *= freq[i];
	}
	if (n < b) {
		pos = 1 - pre;
	}
	return   (n + b - a + n + 1) * pre
		   + (n + b - a + n + 1 + b + 1) * pos;
}

void Problem_1 () {
	int cases;
	cin >> cases;

	cout.precision(6);
	cout.setf(ios::fixed);
	for (int c = 1; c <= cases; ++c) {
		int a, b;
		cin >> a >> b;
		for (int i = 0; i < a; ++i) {
			cin >> freq[i];
		}
		double result, temp;
		result = retry_typing(a, b);
		temp   = keep_typing (a, b);
//		cout << "	** " << result << " - " << temp << endl;
		if (result > temp)
			result = temp;
		for (int i = 1; i < a; ++i) {
			temp = backn_typing(a, b, i);
//			cout << "	** " << temp << endl;
			if (result > temp)
				result = temp;
		}
		cout << "Case #" << c << ": " << result << endl;
	}
}


int main () {
	Problem_1();
	return 0;
}