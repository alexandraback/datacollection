#include <bits/stdc++.h>
using namespace std;

namespace topl
{
	typedef pair<int, int> pi;
	typedef long long LL;
	// 0 - 1, 1 - i, 2 - j, 3 - k
#define Px first
#define Py second
	pi mult (pi a, pi b)
	{
		int tbl[4][4] = {{0, 1, 2, 3},
						 {1, 0, 3, 2},
						 {2, 3, 0, 1},
						 {3, 2, 1, 0}};
		int sgn[4][4] = {{0, 0, 0, 0},
		 				 {0, 1, 0, 1},
						 {0, 1, 1, 0},
						 {0, 0, 1, 1}};
		return pi(tbl[a.Px][b.Px], (a.Py + b.Py + sgn[a.Px][b.Px]) & 1);
	}
	const int N = 10023;

	set<pair<pi, pi>> able2;
	set<tuple<pi, pi, pi>> able3;
	string buff;
	pi entireValue;
	LL repeatTime;

	pi get (char c)
	{
		return pi(c - 'i' + 1, 0);
	}

	void init ()
	{
		static pi pref[N], suff[N];
		int len = buff.length();
		suff[len] = pi(0, 0);
		for (int i = len - 1; i >= 0; --i)
		{
			suff[i] = mult(get(buff[i]), suff[i + 1]);
		}
		pref[0] = get(buff[0]);
		able2.clear();
		able2.insert(make_pair(pi(0, 0), suff[0]));
		able3.clear();
		set<pair<pi, pi>> curAble{make_pair(pi(0, 0), get(buff[0]))};
		for (int i = 1; i <= len; ++i)
		{
			able2.insert(make_pair(pref[i - 1], suff[i]));	

			for (auto p: curAble)
			{
				able3.insert(make_tuple(p.Px, p.Py, suff[i]));
			}

			set<pair<pi, pi>> curAble1{};
			auto curChar = i == len ? pi(0, 0) : get(buff[i]);
			for (auto p: curAble)
			{
				curAble1.insert(make_pair(p.Px, mult(p.Py, curChar)));
			}
			curAble.swap(curAble1);
			pref[i] = mult(pref[i - 1], curChar);
			curAble.insert(make_pair(pref[i - 1], curChar));
		}
		entireValue = pref[len - 1];
	}

	pi pow (pi a, int t)
	{
		pi ret(0, 0);
		while (t--) ret = mult(ret, a);
		return ret;
	}

	bool solve ()
	{
	// Case 1
		
		for (int len0 = 0; len0 < 4; ++len0)
			for (auto split0: able2)
			{
				pi fst = pow(entireValue, len0);
				fst = mult(fst, split0.first);
				if (fst != pi(1, 0)) // i
				{
					continue;
				}
				for (int len1 = 0; len1 < 4; ++len1)
				{
					if (len0 + len1 + 2 > repeatTime)
					{
						continue;
					}
					for (auto split1: able2)
					{
						pi snd = split0.second;
						snd = mult(snd, pow(entireValue, len1));
						snd = mult(snd, split1.first);
						if (snd != pi(2, 0)) // k
						{
							continue;
						}
						int len2 = (repeatTime - len0 - len1 - 2) % 4;
						pi _3rd = split1.second;
						_3rd = mult(_3rd, pow(entireValue, len2));
						if (_3rd == pi(3, 0))
						{
							return true;
						}
					}
				}
			}

		// Case 2
		
		for (int len0 = 0; len0 < 4; ++len0)
		{
			if (len0 + 1 > repeatTime)
			{
				continue;
			}
			int len1 = (repeatTime - len0 - 1) % 4;
			for (auto split: able3)
			{
				pi _1st = pow(entireValue, len0);
				_1st = mult(_1st, std::get<0>(split));
				auto _2nd = std::get<1>(split);
				auto _3rd = mult(std::get<2>(split), pow(entireValue, len1));
				if (_1st == pi(1, 0) && _2nd == pi(2, 0) && _3rd == pi(3, 0))
				{
					return true;
				}
			}
		}
		return false;
	}

	void handle ()
	{
		int tmp;
		cin >> tmp >> repeatTime;
		cin >> buff;
		assert((int)buff.length() == tmp);
		init();
		static int ncase = 0;
		cout << "Case #" << ++ncase << ": " << (solve() ? "YES" : "NO") << endl;
	}
}

int main ()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int ncase = 0;
	cin >> ncase;
	while (ncase--) topl::handle();
	return 0;
}

