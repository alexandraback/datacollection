#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t)
	{
		int n;
		cin >> n;

		vector <double> A(n), B(n);
		
		for(int i = 0; i < n; ++i)
			cin >> A[i];
		for(int i = 0; i < n; ++i)
			cin >> B[i];

		sort(A.begin(), A.end());
		sort(B.begin(), B.end());

		set<double> copyB(B.begin(), B.end());

		int second_score = 0;
		for(int i = 0; i < n; ++i)
		{
			auto it = copyB.lower_bound(A[i]);
			if(it == copyB.end())
			{
				copyB.erase(copyB.begin());
				++second_score;
			}
			else
				copyB.erase(it);
		}

		set<double> copyA(A.begin(), A.end());
		int first_score = 0;
		for(int i = 0; i < n; ++i)
		{
			auto it = copyA.lower_bound(B[i]);
			if(it == copyA.end())
				break;
			else
			{
				copyA.erase(it);
				++first_score;
			}
		}

		cout << "Case #" << t << ": " << first_score << " " << second_score << endl;
	}

	return 0;
}