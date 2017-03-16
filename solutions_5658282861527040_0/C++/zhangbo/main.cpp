#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <cmath>
#include <stack>

#define max(a,b) (a) > (b) ? (a) : (b)
#define min(a,b) (a) < (b) ? (a) : (b)

using namespace std;

vector<unsigned int> p(32, 0);

vector<vector<int>> getarray(unsigned int k)
{
	vector<bool> b(32, false);
	vector<vector<int>> vv;
	vector<int> v;

	bool changed = true;
	while (k > 0 || changed)
	{
		v = vector<int>(32, 0);
		changed = false;
		for (int i = 0; i < 31; i++)
		{
			if (k >= p[i + 1])
				v[i] = 2;
			else if (k >= p[i])
			{
				v[i] = 0;
				b[i] = true;
				k = k - p[i];
				changed = true;
			}
			else if (b[i])
			{
				v[i] = 1;
			}
		}
		vv.push_back(v);
	}
	return vv;
}

void calc()
{
	static int caseno = 0;
	caseno++;
	cerr << "Case #" << caseno << endl;

	// code begin

	unsigned int a, b, k;

	cin >> a >> b >> k;

	a--;
	b--;
	k--;
	
	vector<vector<int>> vva = getarray(a);
	vector<vector<int>> vvb = getarray(b);
	vector<vector<int>> vvk = getarray(k);

	long long total = 0;
	for (int ia = 0; ia < vva.size(); ia++)
	{
		for (int ib = 0; ib < vvb.size(); ib++)
		{
			for (int ik = 0; ik < vvk.size(); ik++)
			{
				long long cur = 1;
				for (int i = 0; i < 31; i++)
				{
					int ta = vva[ia][i];
					int tb = vvb[ib][i];
					int tk = vvk[ik][i];
					int times = 0;
					if (tk == 1 || tk == 2)
					{
						if (ta != 0 && tb != 0)
						{
							times += 1;
						}
					}
					if (tk == 0 || tk == 2)
					{
						if (!(ta == 1 && tb == 1))
						{
							if (ta == 1 || tb == 1)
							{
								times += 1;
							}
							else if (ta == 2 && tb == 2)
							{
								times += 3;
							}
							else if (ta == 2 || tb == 2)
							{
								times += 2;
							}
							else // 0,0
							{
								times += 1;
							}
						}						
					}
					cur *= times;
				}
				total += cur;
			}
		}
	}

	// code end

	cout << "Case #" << caseno << ": ";
	cout << total;
	cout << endl;
}

int main()
{
	p[0] = 1;
	for (int i = 1; i <= 31; i++) p[i] = p[i - 1] * 2;


	int k = 1;
	cin >> k;
	while (k-- > 0)
	{
		calc();
	}

	return 0;
}

