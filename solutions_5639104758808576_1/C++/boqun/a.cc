#include <iostream>

using namespace std;

int S[1000];
int main()
{
	int T, Smax;
	char num;
	cin >> T;
	for (int n = 1; n <= T; n++) {
		int count = 0;
		int stand_up = 0;
		cin >> Smax;
		for (int i = 0; i <= Smax; i++) {
			cin >> num;
			S[i] = num - '0';
		}

		for (int i = 0; i <= Smax; i++) {
			if (S[i] == 0)
				continue;
			if (stand_up >= i)
				stand_up += S[i];
			else {
				count += (i - stand_up);
				stand_up = i + S[i];
			}
		}

		cout << "Case #" << n << ": " << count << endl;
	}
	return 0;
}
