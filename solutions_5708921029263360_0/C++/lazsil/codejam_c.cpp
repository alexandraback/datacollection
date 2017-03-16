#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>

using namespace std;

struct Suit
{
	int a;
	int b;
	int c;
	
};

struct suitcomapre {
	bool operator()(const Suit &a, const Suit &b)
	{
		if (a.a < b.a)
			return true;
		if (a.a == b.a)
		{
			if (a.b < b.b)
				return true;
			if (a.b == b.b)
			{
				if (a.c < b.c)
					return true;
			}
		}
		return false;
	}
};

int main()
{
	
	int num_of_testcases;
	cin >> num_of_testcases;
	for (int t = 1; t <= num_of_testcases; ++t){
		int a, b, c, k;
		cin >> a >> b >> c >> k;

		set < Suit, suitcomapre> alreadyWorn;
		map<pair<int, int>, int> ab, bc, ca;

		if (a == b && b == c)
		{
			for (int i = a; i > 0; --i)
			{
				Suit s;
				s.a = i;
				s.b = i;
				s.c = i;
				pair<int, int> pab = make_pair(i, i);
				pair<int, int> pbc = make_pair(i,i);
				pair<int, int> pca = make_pair(i, i);

				if (ab[pab] < k && bc[pbc] < k && ca[pca] < k)
				{
					ab[pab]++;
					bc[pbc]++;
					ca[pca]++;

					alreadyWorn.insert(s);
				}
			}
		}
		for (int i = a; i > 0; --i)
		{
			for (int j = b; j > 0; --j)
			{
				for (int w = c; w > 0; --w)
				{
					Suit s;
					s.a = i;
					s.b = j;
					s.c = w;
					if (alreadyWorn.find(s) == alreadyWorn.end())
					{
						pair<int, int> pab = make_pair(i, j);
						pair<int, int> pbc = make_pair(j, w);
						pair<int, int> pca = make_pair(w, i);

						if (ab[pab] < k && bc[pbc] < k && ca[pca] < k)
						{
							ab[pab]++;
							bc[pbc]++;
							ca[pca]++;

							alreadyWorn.insert(s);
						}

					}
				}
			}
		}


		for (int i = a; i > 0; --i)
		{
			for (int j = b; j > 0; --j)
			{
				for (int w = c; w > 0; --w)
				{
					Suit s;
					s.a = i;
					s.b = j;
					s.c = w;
					if (alreadyWorn.find(s) == alreadyWorn.end())
					{
						pair<int, int> pab = make_pair(i, j);
						pair<int, int> pbc = make_pair(j, w);
						pair<int, int> pca = make_pair(w, i);

						if (ab[pab] < k && bc[pbc] < k && ca[pca] < k)
						{
							ab[pab]++;
							bc[pbc]++;
							ca[pca]++;

							alreadyWorn.insert(s);
						}

					}
				}
			}
		}




		cout << "Case #" << t << ": " << alreadyWorn.size() << endl;
		for (auto& w : alreadyWorn)
		{
			cout << w.a << " " << w.b << " " << w.c << endl;
		}
	}

    return 0;
}

