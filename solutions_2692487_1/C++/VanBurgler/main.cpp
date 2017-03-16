#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <array>
#include <algorithm>

using namespace std;

int doit(int a, vector<int>& others, int pos)
{
	if (others.size() <= pos) return 0;

	if (a > others.at(pos))
		return doit(a + others.at(pos), others, pos + 1);

	if (a + a - 1 <= a) return others.size() - pos;

	int first = doit(a + a - 1, others, pos) + 1;
	int second = others.size() - pos;

	return std::min(first, second);
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		int A;
		int N;

		cin >> A >> N;

		vector<int>	others(N);

		for (int i = 0; i < N; i++)
			cin >> others[i];

		sort(begin(others), end(others));

		cout << "Case #" << t << ": " << doit(A, others, 0) << endl;
	}
}
