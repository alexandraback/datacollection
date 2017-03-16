#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#define lol long long
using namespace std;

string filename = "C-small-attempt1.in";
ifstream in(filename);
ofstream out(filename + "_out.txt");

#define cin in
#define cout out

struct zalupa
{
	int j, p, s;
	zalupa(int j, int p, int s) : j(j), p(p), s(s) {}
};

vector<zalupa> cp;

vector<zalupa> fuck(int nxt, map<pair<int, int>, int> & jp, map<pair<int, int>, int> & ps, map<pair<int, int>, int> & js, int k)
{
	if (nxt >= cp.size())
		return vector<zalupa>();

	vector<zalupa> ans1 = fuck(nxt + 1, jp, ps, js, k);

	vector<zalupa> ans2;

	bool fail2 = 0;

	++jp[make_pair(cp[nxt].j, cp[nxt].p)];
	if (jp[make_pair(cp[nxt].j, cp[nxt].p)] > k)
		fail2 = 1;
	
	++ps[make_pair(cp[nxt].p, cp[nxt].s)];
	if (ps[make_pair(cp[nxt].p, cp[nxt].s)] > k)
		fail2 = 1;

	++js[make_pair(cp[nxt].j, cp[nxt].s)];
	if (js[make_pair(cp[nxt].j, cp[nxt].s)] > k)
		fail2 = 1;

	if (!fail2)
		ans2 = fuck(nxt + 1, jp, ps, js, k);

	--jp[make_pair(cp[nxt].j, cp[nxt].p)];
	--ps[make_pair(cp[nxt].p, cp[nxt].s)];
	--js[make_pair(cp[nxt].j, cp[nxt].s)];

	if (fail2 || ans1.size() > ans2.size() + 1)
		return ans1;

	ans2.push_back(cp[nxt]);
	return ans2;
}

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		int j, p, s, k;
		cin >> j >> p >> s >> k;

		cout << "Case #" << i + 1 << ": ";
		
		cp.clear();
		for (int _j = 0; _j < j; ++_j)
			for (int _p = 0; _p < p; ++_p)
				for (int _s = 0; _s < s; ++_s)
					cp.push_back(zalupa(_j, _p, _s));

		map<pair<int, int>, int> m1, m2, m3;
		vector<zalupa> zz = fuck(0, m1, m2, m3, k);
		cout << zz.size() << endl;
		for (auto _ : zz)
			cout << _.j + 1 << " " << _.p + 1 << " " << _.s + 1 << endl;

	}
	return 0;
}
