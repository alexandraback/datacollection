#include <iostream>

using namespace std;

int main()
{
	int cases;

	cin >> cases;

	for (int i = 1; i <= cases; i++) {
		int a, b, k;

		cin >> a >> b >> k;

		int kminus = k - 1;

		long long count = 0;

		for (int j = 0; j < a; j++) {
			if (j < kminus)
				count += b;
			else {
				for (int m = 0; m < b; m++) {
					if (m < kminus)
						count++;
					else {
						int x = j & m;

						if (x < k)
							count++;
					}
				}
			}
		}

		cout << "Case #" << i << ": " << count << endl;
	}

	return 0;
}
