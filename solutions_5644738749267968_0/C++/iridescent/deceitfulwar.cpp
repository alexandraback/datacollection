#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

int main()
{
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++)
	{
		cout << "Case #" << t << ": ";
		set<double> N, K;
		{
			int n;
			cin >> n;
			for(int i = 0; i < n; i++)
			{
				double x;
				cin >> x;
				N.insert(x);
			}
			for(int i = 0; i < n; i++)
			{
				double x;
				cin >> x;
				K.insert(x);
			}
		}

		set<double> N2 = N, K2 = K;
		{
			int score = 0;
			while(!N.empty())
			{
				double n = *(N.begin());
				N.erase(n);
				if(n > *K.begin())
				{
					K.erase(K.begin());
					score++;
				}
				else
				{
					K.erase(--K.end());
				}
			}
			cout << score << ' ';
		}

		N = N2, K = K2;
		{
			int score = 0;
			while(!N.empty())
			{
				double n = *(--N.end());
				N.erase(n);
				double k = (K.upper_bound(n) == K.end() ? *K.begin() : *K.upper_bound(n));
				K.erase(k);
				score += (n > k);
			}
			cout << score << endl;
		}
	}
}
