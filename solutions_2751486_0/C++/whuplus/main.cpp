#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int T;
	char buf[1024];
	int n;
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cout << "Case #" << t << ": ";

		cin >>  buf >> n;
		int count = 0;

		int len = strlen(buf);
		for (int i = 0; i < len; i++) {
			for (int j = i + n; j <= len; j++) {
				//cerr << i << ", " << j << ", "<< count << endl;
				int cons = 0;
				bool ok = false;
				for (int k = i; k < j; k++) {
					if (buf[k] == 'a' || buf[k] == 'e' || buf[k] == 'i' || buf[k] == 'o' || buf[k] == 'u') {
						cons = 0;
					} else {
						cons++;
						if (cons >= n) {
							ok = true;
							break;
						}
					}
				}

				if (ok) {
					count++;
				}
			}
		}
		cout << count << endl;
	}

	return 0;
}