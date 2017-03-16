#include <iostream>
using namespace std;

void test(int t)
{
	unsigned a, b, k, result = 0;
	cin >> a >> b >> k;
	for (unsigned i = 0; i < a; i++)
		for (unsigned j = 0; j < b; j++)
			if ((i & j) < k)
				result++;
	cout << "Case #" << t << ": " << result << endl;
}

int main()
{
	int t; cin >> t;
	for (int i = 1; i <= t; i++)
		test(i);
}
