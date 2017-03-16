#include <iostream>
#include <cmath>

#define MIN(a,b) a<b?a:b
#define MAX(a,b) a>b?a:b
using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int A, B;
		cin >> A >> B;
		int cnt = 0;

		for (int n = A; n < B; n++) {
			int s = (int)(log10(n)+1);
			int buf[s];
			int index = 0;
			for (int i = 1; i < s; i++) {
				int p = pow(10, i);
				int d = n / p;
				int r = n % p;

				int m = r * pow(10, s-i) + d;
				if (m > n && m <= B) {
					int f = 1;
					for (int j = 0; j < index; j++)
						if (buf[j] == m)
							f = 0;
					if (f == 1) {
						buf[index++] = m;
						cnt++;
					}
				}

			}
		}
		cout << "Case #" << t << ": " << cnt << endl;
	}
	return 0;
}
