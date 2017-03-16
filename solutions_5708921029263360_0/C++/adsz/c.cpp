#include <bits/stdc++.h>
using namespace std;

struct FirstGreater
{
	template<class X, class Y>
	bool operator()(const pair<X, Y>& p1, const pair<X, Y>& p2) const
	{
		return p1.first > p2.first;
	} 
};

void test()
{
	int J, P, S, K;
	cin >> J >> P >> S >> K;
	
	vector<pair<int, char>> dim ({ {J, 'J'}, {P, 'P'}, {S, 'S'}});
	sort(dim.rbegin(), dim.rend());
	
	ostringstream sol;
	size_t sol_size = 0;
	
	size_t j, p, s;
	for (size_t z = 0; z < dim[2].first; ++z)
	{
		if (dim[2].second == 'J') j = z;
		if (dim[2].second == 'P') p = z;
		if (dim[2].second == 'S') s = z;
		
		for (size_t y = 0; y < dim[1].first; ++y)
		{
			if (dim[1].second == 'J') j = y;
			if (dim[1].second == 'P') p = y;
			if (dim[1].second == 'S') s = y;
		
			vector<bool> row(dim[0].first);
			size_t start = (y+z);
			for (size_t i = 0; i < K; ++i)
			{
				row[(start+i) % dim[0].first] = true;
			}
			
			for (size_t x = 0; x < dim[0].first; ++x)
			{
				if (dim[0].second == 'J') j = x;
				if (dim[0].second == 'P') p = x;
				if (dim[0].second == 'S') s = x;
		
				if (row[x])
				{
					sol << (j+1) << " " << (p+1) << " " << (s+1) << endl;
					sol_size++;
				}
			}
		}
	}
	
	cout << sol_size << endl << sol.str();
}

int main()
{
	size_t c;
	std::cin >> c;
	for (size_t i = 1; i<=c; ++i)
	{
		std::cout << "Case #" << i << ": ";
		test();
		//std::cout << std::endl;
	}
}
