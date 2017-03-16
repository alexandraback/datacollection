#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>

using namespace std;

long min(long a, long b) {return (a < b) ? a : b;}

struct P
{
	long amount, type;
};

long checkMatch(vector<P>& a, long aleft, long apos, 
	vector<P>& b, long bleft, long bpos)
{
	long total = 0;

	while (a[apos].type == b[bpos].type)
	{
		long matched = min(aleft, bleft);
		total += matched;
		aleft -= matched;
		bleft -= matched;

		if (aleft == 0) 
		{
			apos++;
			if (apos == a.size()) return total;
			aleft = a[apos].amount;
		}

		if (bleft == 0) 
		{
			bpos++;
			if (bpos == b.size()) return total;
			bleft = b[bpos].amount;
		}

	}

	long best = 0;

	if (apos < a.size() - 1)
		best = checkMatch(a, a[apos + 1].amount, apos + 1, b, bleft, bpos);

	if (bpos < b.size() - 1)
	{
		long opt = checkMatch(a, aleft, apos, b, b[bpos + 1].amount, bpos + 1);
		if (opt > best) best = opt;
	}

	return total + best;	
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		int N, M;

		cin >> N >> M;

		vector<P> a;

		for (int i = 0; i < N; i++)
		{
			long x, y;
			cin >> x >> y;
			a.push_back({x, y});
		}

		vector<P> b;

		for (int i = 0; i < M; i++)
		{
			long x, y;
			cin >> x >> y;
			b.push_back({x, y});
		}

		cout << "Case #" << t << ": " << checkMatch(a, a[0].amount, 0, b, b[0].amount, 0) << endl;
	}
}
