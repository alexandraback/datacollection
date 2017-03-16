#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>


using namespace std;

int p[100000];

string toBase2(long long x) {
	string ans = "";
	while (x > 0) {
		int y = x % 2;
		x = x / 2;
		ans = (char)(y + 48) + ans;
	}
	return ans;
}

int findDiv(long long coin, int base) {
	long long x = 0;
	long long mm = 1;
	while (coin > 0) {
		x += mm * (coin % 2);
		coin /= 2;
		mm *= base;
	}
	//cout << x << endl;
	int dd = 0;
	for (int i = 0; i < 100000; ++i) {
		if (p[i] >= x) {
			break;
		}
		if (x % p[i] == 0) {
			dd = p[i];
			break;
			//cout << dd << endl;
		}

	}
	return dd;

}

int main() {
	int tests, n, jj;
	int sMax;

	long long coin;
	cin >> tests;
	cin >> n >> jj;
	cout << "Case #" << 1 << ":" << endl;

	ifstream file;
	file.open("prime.txt");
	for (int i = 0; i < 100000; ++i) {
		file >> p[i];
		//if ( i < 10 ) { cout << p[i] << endl;}
	}
	file.close();

	long long maxn = 1;
	for (int i = 1; i <= n - 2; ++i) {
		maxn *= 2;
	}
	int count = 0;
	int ans[11];

	for (long long i = 0; i < maxn; ++i) {
		coin = maxn * 2 + i * 2 + 1;
		//cout << coin << endl;
		bool flag = true;
		for (int j = 2; j <= 10; ++j) {
			int d = findDiv(coin, j);
			if (d == 0) {
				flag = false;
				break;
			}
			ans[j] = d;
		}
		if (flag) {
			cout << toBase2(coin);
			for (int i = 2; i <= 10; ++i) {
				cout << " " << ans[i];
			}
			cout << endl;
			++count;
		    if (count == jj) {
		    	break;
		    }
		}
	}
	return 0;
}