#include <iostream>

using namespace std;

int T;
int J;
int P;
int S;
int K;
int main()
{
	cin >> T;

	for (int n = 1; n <= T; n++) {
		cin >> J >> P >> S >> K;

		if (K > S) {
			cout << "Case #" << n << ": " << J * P * S << endl;
			for (int i = 1; i <= S; i++)
				for (int j = 1; j <= P; j++)
					for (int k = 1; k <= J; k++)
						cout << k << " " << j << " " << i << endl;
		}
		else {
			cout << "Case #" << n << ": " << J * P * K << endl;
			for (int i = 1; i <= K; i++)
				for (int j = 1; j <= P; j++)
					for (int k = 1; k <= J; k++)
						cout << k << " " << j << " " << i << endl;
		}
	}
}
