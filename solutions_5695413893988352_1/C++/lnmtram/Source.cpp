#include <iostream>
#include <string>
using namespace std;
string A, B;
long long bestA, bestB;
bool ok = 0;

long long value(string A) {
	long long v = 0;
	for (int i = 0; i < A.length(); ++i) {
		v = v * 10 + A[i] - '0';
	}

	return v;
}

string toString(long long n) {
	string str = "";
	for (int i = 0; i < A.length(); ++i) {
		char ch = n % 10 + '0';
		str = ch + str;
		n /= 10;
	}

	return str;
}

void attemp(int k, int i, string AA, string BB) {
	if (i == A.length()) {
		long long a = value(AA);
		long long b = value(BB);
		if (ok == 0 || abs(bestA - bestB) > abs(a - b)) {
			bestA = a;
			bestB = b;
			ok = 1;
		}
		else if (abs(bestA - bestB) == abs(a - b)) {
			if (bestA > a) {
				bestA = a;
				bestB = b;
			}
			else if (bestA == a && bestB > b) bestB = b;
		}
		return;
	}

	if (k == 0) {
		if (A[i] == '?' && B[i] == '?') {
			AA[i] = BB[i] = '0';
			attemp(0, i + 1, AA, BB);

			AA[i] = '1';  BB[i] = '0';
			attemp(1, i + 1, AA, BB);

			AA[i] = '0';  BB[i] = '1';
			attemp(-1, i + 1, AA, BB);
			return;
		}
		else
			if (A[i] == '?') {
				AA[i] = BB[i];
				attemp(0, i + 1, AA, BB);

				if (BB[i] != '9') {
					AA[i] = BB[i] + 1;
					attemp(1, i + 1, AA, BB);
				}

				if (BB[i] != '0') {
					AA[i] = BB[i] - 1;
					attemp(-1, i + 1, AA, BB);
				}

				return;
			}
			else if (B[i] == '?')
			{
				BB[i] = AA[i];
				attemp(0, i + 1, AA, BB);

				if (AA[i] != '9') {
					BB[i] = AA[i] + 1;
					attemp(-1, i + 1, AA, BB);
				}

				if (AA[i] != '0') {
					BB[i] = AA[i] - 1;
					attemp(1, i + 1, AA, BB);
				}

				return;
			}
			else if (A[i] > B[i]) k = 1;
			else if (A[i] < B[i]) k = -1;
	}
	else if (k == 1) {
		if (A[i] == '?') AA[i] = '0';
		if (B[i] == '?') BB[i] = '9';
			}
	else if (k == -1) {
		if (A[i] == '?') AA[i] = '9';
		if (B[i] == '?') BB[i] = '0';
	}

	attemp(k, i + 1, AA, BB);

}

int main() {
	freopen("A.in", "r", stdin);
	freopen("A1.out", "w", stdout);
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		cin >> A >> B;
		string AA, BB;
		AA = A;
		BB = B;
		ok = 0;

		attemp(0, 0, AA, BB);

		cout << "Case #" << t + 1 << ": " << toString(bestA) << " " << toString(bestB) << endl;
	}
}