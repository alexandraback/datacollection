#include <iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int case_num = 1; case_num <= T; ++case_num)
	{
		int A, B, K;
		cin >> A >> B >> K;

		int num = 0;
		for (int a = 0; a < A; ++a)
			for (int b = 0; b < B; ++b)
				if ((a & b) < K)
					++num;

		cout << "Case #" << case_num << ": " << num << endl;
	}
	return 0;
}