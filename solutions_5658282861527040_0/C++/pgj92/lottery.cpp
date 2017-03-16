#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int T, N, A, B, K;

int solve(int tc) {
	cin >> A >> B >> K;
	long long result = 0;
	for (int a = 0; a < A; a++)
		for (int b = 0; b < B; b++)
			result += ((a&b) < K);
	cout << result << endl;
}

int main() 
{
	cin >> T;
	for (int i=1; i<=T; i++) {
		cout << "Case #" << i << ": ";
		solve(i);
	}
	return 0;
}