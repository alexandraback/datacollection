// gj.cpp
//

#include <assert.h>

#include <fstream>
#include <sstream>
#include <stack>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <algorithm>
#include <utility>

using namespace std;

typedef unsigned char uchar;
typedef unsigned int uint;
typedef unsigned __int64 uint64;

#define EPS (1E-10)
#define PI 3.1415926535897932384626433832795

vector<string> v,
			   vi;
vector<uint64> vq,
			   vqi;

vector<bool> vo,
		     voi;

uint64 mod =  1000000007;

bool al[26];

uint64 fmd(uint64 x)
{
	uint64 y = 1;
	for (uint64 i = 2; i <= x; ++i)
	{
		y *= i;
		y %= mod;
	}

	return y;
}

int main(int argc, char* argv[])
{
	uint64 cases;
	cin >> cases;

	for (uint64 cs = 1; cs <= cases; ++cs)
	{
		uint64 n;
		cin >> n;

		v.clear();
		vi.clear();
		vq.clear();
		vq.clear();
		vqi.clear();

		v.resize(n);
		vi.resize(n);
		vq.resize(n);
		vqi.resize(n);

		vo.resize(n);
		voi.resize(n);

		fill(vo.begin(), vo.end(), false);
		fill(voi.begin(), voi.end(), false);

		for (uint i = 0; i < n; ++i)
		{
			cin >> v[i];
			vq[i] = 1;
		}

		for (char c = 'a'; c <= 'z'; ++c)
		{
			uint q = 0;
			string a;
			uint vin = 0;
			for (uint i = 0; i < n; ++i)
			{
				uint l = v[i].size();
				bool h = true;
				for (uint j = 0; j < l; ++j)
				{
					if (v[i][j] != c)
					{
						h = false;
						break;
					}
				}

				if (h)
				{
					++q;
					a += v[i];
				}
				else
				{
					vqi[vin] = vq[i];
					voi[vin] = vo[i];
					vi[vin++] = v[i];
				}
			}

			if (q)
			{
				vqi[vin] = fmd(q);
				voi[vin] = true;
				vi[vin++] = a;
			}

			v = vi;
			vq = vqi;
			vo = voi;
			n = vin;
		}

		for (uint i = 0; i < n; ++i)
		{
			if (vo[i] && !v[i].empty())
			{
				for (uint j = 0; j < n; ++j)
				{
					if (i != j && !v[j].empty())
					{
						if (v[j][0] == v[i][0])
						{
							v[j] = v[i] + v[j];
							v[i].clear();
							break;
						}
						else if (*v[j].rbegin() == v[i][0])
						{
							v[j] += v[i];
							v[i].clear();
							break;
						}
					}
				}
			}
		}

		uint vin = 0;
		for (uint i = 0; i < n; ++i)
		{
			if (!v[i].empty())
			{
				vi[vin] = v[i];
				vqi[vin++] = vq[i];
			}
		}

		v = vi;
		vq = vqi;
		n = vin;

		uint64 r = 1;

		for (uint i = 0; r && i < n; ++i)
		{
			if (!v[i].empty())
			{
				bool after = false,
					 before = false;

				uint ib = 0,
					 ia = 0;

				for (uint j = 0; j < n; ++j)
				{
					if (i != j && !v[j].empty())
					{
						if (*v[j].rbegin() == v[i][0])
						{
							if (!before)
							{
								before = true;
								ib = j;
							}
							else
							{
								r = 0;
								break;
							}
						}
						else if (v[j][0] == *v[i].rbegin())
						{
							if (!after)
							{
								after = true;
								ia = j;
							}
							else
							{
								r = 0;
								break;
							}
						}
					}
				}

				if (r)
				{
					if (before)
					{
						v[ib] += v[i];
						v[i].clear();
					}
					else if (after)
					{
						v[i] += v[ia];
						v[ia].clear();
					}
				}
			}
		}

		if (r)
		{
			uint vin = 0;
			for (uint i = 0; i < n; ++i)
			{
				if (!v[i].empty())
				{
					vi[vin] = v[i];
					vqi[vin++] = vq[i];
				}
			}

			v = vi;
			vq = vqi;
			n = vin;

			r = fmd(vin);

			string a;
			for (uint i = 0; i < n; ++i)
			{
				r *= vq[i];
				r %= mod;
				a += v[i];
			}

			uint l = a.size();
			char pr = a[0];
			fill(al, al + 26, false);
			al[pr - 'a'] = true;
			for (uint i = 1; r && i < l; ++i)
			{
				if (a[i] != pr)
				{
					pr = a[i];
					if (al[pr - 'a'])
						r = 0;
					al[pr - 'a'] = true;
				}
			}
		}

		cout << "Case #" << cs << ": " << r << "\n";
	}

	return 0;
}
