#include <cstdio>
#include <iostream>

using namespace std;

void solve()
{
	int N, J;
	cin >> N >> J;

	int k = (N/2) - 2;

	cout << endl;
	for(int i = 0; i < J; ++i) {
		int x = i;
		cout << "11";

		for(int j = 0; j < k; ++j) {
			cout << (x % 2 == 0 ? "00" : "11");
			x /= 2;
		}

		cout << "11";

		for(int j = 2; j <= 10; ++j) {
			cout << " " << (j+1);
		}
		cout << endl;
	}


	

}

int main()
{
	int t;
	cin >> t;
	for(int i = 1; i <= t; ++i) {
		cout << "Case #" << i << ": ";
		solve();
	}

	return 0;
}