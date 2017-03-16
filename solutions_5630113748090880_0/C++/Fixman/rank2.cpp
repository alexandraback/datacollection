#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cassert>
#include <set>

using namespace std;

#define forsn(i, s, n) for (int i = s; i < n; i++)
#define forn(i, n) forsn(i, 0, n)
#define fore(i, n) forn(i, n.size())
#define all(n) n.begin(), n.end()

vector <vector <int>> A;
vector <vector <int>> C;

bool lower(const vector <int> &a, const vector <int> &b)
{
	fore(i, a)
	{
		if (a[i] >= b[i])
			return false;
	}

	return true;
}

vector <int> missing()
{
	multiset <vector <int>> V(all(A));

	for (auto& k : C)
		V.erase(V.find(k));

	vector <int> r;
	fore(j, C[0])
	{
		vector <int> y(C.size());
		fore(i, C)
			y[i] = C[i][j];

		auto h = V.find(y);
		if (h != V.end())
			V.erase(h);
		else if (r.empty())
			r = y;
		else
			return vector <int> ();
	}

	return r;
}

vector <int> go(int w, int n)
{
	// cerr << w << ' ' << n << endl;
	if (n == 1)
		return missing();
	
	forsn(i, w + 1, A.size())
	{
		if (lower(A[w], A[i]))
		{
			C.push_back(A[i]);
			vector <int> r = go(i, n - 1);
			C.pop_back();

			if (!r.empty())
				return r;
		}
	}

	return vector <int> ();
}

vector <int> solve()
{

	int n = A[0].size();
	for (int i = 0; i < A.size(); i++)
	{
		C = vector <vector <int>> (1, A[i]);
		vector <int> r = go(i, n);
		if (!r.empty())
			return r;
	}

	assert(false);
}

int main()
{
	int t; cin >> t;
	forsn(z, 1, t + 1)
	{
		int n; cin >> n;
		int m = 2 * n - 1;

		A = vector <vector <int>> (m, vector <int> (n));
		for (auto& k : A)
		{
			for (auto& l : k)
				cin >> l;
		}

		sort(all(A));

		vector <int> r = solve();
		printf("Case #%d: ", z);
		fore(i, r)
			cout << r[i] << (i == r.size() - 1 ? '\n' : ' ');
	}

	return 0;
}
