#include <algorithm>
#include <array>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <forward_list>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <vector>

using namespace std;

string C;
string J;

struct Answer
{
	string r1;
	string r2;
	int isInf;
	int genPos;

	void init()
	{
		r1 = string(C.length(), '?');
		r2 = string(J.length(), '?');
		isInf = 0;
		genPos = 0;
	}

	int getAbsDiff() const
	{
		int i1 = stoi(r1, nullptr, 10);
		int i2 = stoi(r2, nullptr, 10);
		return abs(i1 - i2);
	}
};

Answer generate(Answer ans)
{
	if (ans.genPos >= C.length())
		return ans;

	int i = ans.genPos;
	ans.genPos++;
	char c1 = C[i];
	char c2 = J[i];
	if (ans.isInf == 0)
	{
		if (c1 == '?')
		{
			if (c2 == '?')
			{
				Answer best;
				bool bestFound = false;
				for (char t1 : {'0', '1', '9'})
				{
					for (char t2 : {'0', '1', '9'})
					{
						ans.r1[i] = t1;
						ans.r2[i] = t2;
						ans.isInf = (t1 == t2 ? 0 : (t1 < t2 ? 1 : -1));
						Answer test = generate(ans);
						if (!bestFound || test.getAbsDiff() < best.getAbsDiff())
						{
							best = test;
							bestFound = true;
						}
					}
				}
				return best;
			}
			else
			{
				Answer best;
				bool bestFound = false;
				for (char t1 : vector<char>({ char(c2 - 1), c2, char(c2 + 1) }))
				{
					if (t1 >= '0' && t1 <= '9')
					{
						ans.r1[i] = t1;
						ans.r2[i] = c2;
						ans.isInf = (t1 == c2 ? 0 : (t1 < c2 ? 1 : -1));
						Answer test = generate(ans);
						if (!bestFound || test.getAbsDiff() < best.getAbsDiff())
						{
							best = test;
							bestFound = true;
						}
					}
				}
				return best;
			}
		}
		else
		{
			if (c2 == '?')
			{
				Answer best;
				bool bestFound = false;
				for (char t2 : vector<char>({ char(c1 - 1), c1, char(c1 + 1) }))
				{
					if (t2 >= '0' && t2 <= '9')
					{
						ans.r1[i] = c1;
						ans.r2[i] = t2;
						ans.isInf = (c1 == t2 ? 0 : (c1 < t2 ? 1 : -1));
						Answer test = generate(ans);
						if (!bestFound || test.getAbsDiff() < best.getAbsDiff())
						{
							best = test;
							bestFound = true;
						}
					}
				}
				return best;
			}
			else
			{
				ans.r1[i] = c1;
				ans.r2[i] = c2;
				if (c1 < c2)
				{
					ans.isInf = 1;
				}
				else if (c1 > c2)
				{
					ans.isInf = -1;
				}
				return generate(ans);
			}
		}
	}
	else if (ans.isInf > 0)
	{
		if (c1 == '?')
		{
			if (c2 == '?')
			{
				ans.r1[i] = '9';
				ans.r2[i] = '0';
			}
			else
			{
				ans.r1[i] = '9';
				ans.r2[i] = c2;
			}
		}
		else
		{
			if (c2 == '?')
			{
				ans.r1[i] = c1;
				ans.r2[i] = '0';
			}
			else
			{
				ans.r1[i] = c1;
				ans.r2[i] = c2;
			}
		}
		return generate(ans);
	}
	else
	{
		if (c1 == '?')
		{
			if (c2 == '?')
			{
				ans.r1[i] = '0';
				ans.r2[i] = '9';
			}
			else
			{
				ans.r1[i] = '0';
				ans.r2[i] = c2;
			}
		}
		else
		{
			if (c2 == '?')
			{
				ans.r1[i] = c1;
				ans.r2[i] = '9';
			}
			else
			{
				ans.r1[i] = c1;
				ans.r2[i] = c2;
			}
		}
		return generate(ans);
	}
}

int main()
{
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		C.clear();
		J.clear();
		cin >> C >> J;

#if 0
		string res1(C.length(), '?');
		string res2(C.length(), '?');
		int isInf = 0;
		for (int i = 0; i < C.length(); i++)
		{
			char c1 = C[i];
			char c2 = J[i];
			if (isInf == 0)
			{
				if (c1 == '?')
				{
					if (c2 == '?')
					{
						res1[i] = '0';
						res2[i] = '0';
					}
					else
					{
						res1[i] = c2;
						res2[i] = c2;
					}
				}
				else
				{
					if (c2 == '?')
					{
						res1[i] = c1;
						res2[i] = c1;
					}
					else
					{
						res1[i] = c1;
						res2[i] = c2;
						if (c1 < c2)
						{
							isInf = 1;
						}
						else
						{
							isInf = -1;
						}
					}
				}
			}
			else if (isInf > 0)
			{
				if (c1 == '?')
				{
					if (c2 == '?')
					{
						res1[i] = '9';
						res2[i] = '0';
					}
					else
					{
						res1[i] = '9';
						res2[i] = c2;
					}
				}
				else
				{
					if (c2 == '?')
					{
						res1[i] = c1;
						res2[i] = '0';
					}
					else
					{
						res1[i] = c1;
						res2[i] = c2;
					}
				}
			}
			else
			{
				if (c1 == '?')
				{
					if (c2 == '?')
					{
						res1[i] = '0';
						res2[i] = '9';
					}
					else
					{
						res1[i] = '0';
						res2[i] = c2;
					}
				}
				else
				{
					if (c2 == '?')
					{
						res1[i] = c1;
						res2[i] = '9';
					}
					else
					{
						res1[i] = c1;
						res2[i] = c2;
					}
				}
			}
		}
#endif

		Answer a;
		a.init();
		a = generate(a);

		cout << "Case #" << t + 1 << ": " << a.r1 << ' ' << a.r2 << endl;
	}

	return 0;
}
