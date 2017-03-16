#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
using namespace std;

int length;
long long ans;
long long n;
long long p(int k) {
	int ans = 1;
	for (int i = 0; i<k; i++)
		ans *= 10;
	return ans;
}

int getlen(long long temp)
{
	int length = 0;
	while (temp!=0) {
		length++;
		temp /= 10;
	}
	return length;
}
void add(int k) {
	int now1, now2;
	if (k == 1) {
		ans += n;
		return;
	}
	if (n % 10 == 0) {
		int huhu = 1;
		n -= huhu;
		ans += huhu;
		length = 0;
		long long tempp = n;
		length = getlen(tempp);
		if (length != k) {
			add(k - 1);
			return;
		}
	}
	long long temp = n, temp2;
	for (int i = 0; i<k / 2; i++) {
		now1 = temp % 10;
		if (!i) {
			n -= (now1 - 1);
			ans += (now1 - 1);
		}
		else {
			n -= (now1*p(i));
			ans += (now1*p(i));
		}
		temp /= 10;
	}
	temp = p(k - 1);
	temp2 = 0;
	for (int i = 0; i<k / 2; i++) {
		temp += ((n / p(k - i - 1)) % 10)*p(i);
		temp2 += ((n / p(k - i - 1)) % 10)*p(i);
	}
	if (k % 2) {
		temp += ((n / p(k - k / 2 - 1)) % 10)*p(k - k / 2 - 1);
		temp2 += ((n / p(k - k / 2 - 1)) % 10)*p(k - k / 2 - 1);
	}
	if (temp != n) ans += 1;
	ans += (temp2 + 1);
	n = p(k - 1) - 1;
	add(k - 1);

}
#define cin fin
#define cout fout


int main() {
	ifstream fin("haha.in");
	ofstream fout("output.out");
	int T;
	cin >> T;
	for (int k = 0; k<T; k++) {
		cin >> n;
		ans = 0;
		length = 0;
		long long temp = n;
		while (temp!=0) {
			length++;
			temp /= 10;
		}
		add(length);
		cout << "Case #" << k + 1 << ": " << ans << endl;
	}
	fin.close();
	fout.close();
	system("pause");
	return 0;
}
