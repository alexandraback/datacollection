#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Player
{
	int J;
	int index;
	double share;

	Player() : J(0), index(0), share(0) {}
};

int main()
{
	int T;
	cin >> T;

	for (int nTestCase = 1; nTestCase <= T; nTestCase++)
	{
		int N;
		cin >> N;

		vector<Player> s(N);
		int Jsum = 0;
		for (int i = 0; i < N; i++)
		{
			cin >> s[i].J;
			s[i].index = i;
			Jsum += s[i].J;
		}

		sort(s.begin(), s.end(), [](const Player & p1, const Player & p2) { return p1.J < p2.J; });
		
		double share = 1;
		for (int i = 0; i < N - 1; i++)
		{
			int delta = s[i + 1].J - s[i].J;
			double cost = double(delta) / Jsum;
			double totalCost = cost * (i + 1);

			if (totalCost <= share)
			{
				s[i].share = cost;
				share -= totalCost;
			}
			else
			{
				s[i].share = share / (i + 1);
				share = 0;
				break;
			}
		}

		if (share > 0)
			s[N - 1].share = share / N;

		for (int i = N - 2; i >= 0; i--)
			s[i].share += s[i + 1].share;

		sort(s.begin(), s.end(), [](const Player & p1, const Player & p2) { return p1.index < p2.index; });

		cout << "Case #" << nTestCase << ':';
		for (int i = 0; i < N; i++)
			cout << ' ' << fixed << setprecision(6) << (s[i].share * 100);
		cout << endl;
	}
}
