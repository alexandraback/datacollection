#include<iostream>
#include<cstdlib>
using namespace::std;

int main()
{
	int test_case, N, hei;
	cin >> test_case;
	for (int i = 1;i <= test_case;i++) {
		cin >> N;
		int count[2501] = { 0 };
		for (int j = 0;j < (2 * N - 1)*N;j++) {
			cin >> hei;
			count[hei]++;
		}
		cout << "Case #" << i << ": ";
		for (int j = 1;j <= 2500;j++) {
			if (count[j] % 2 != 0) {
				cout << j << " ";
			}
		}
		cout << endl;
	}
	system("pause");
	return 0;
}