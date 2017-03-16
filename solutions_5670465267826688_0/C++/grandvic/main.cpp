#include <algorithm>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

#pragma comment(linker, "/STACK:16777216")

using namespace std;

const char v_e = 0;
const char v_i = 1;
const char v_j = 2;
const char v_k = 3;
const char v_E = 4;
const char v_I = 5;
const char v_J = 6;
const char v_K = 7;

const char mulPrecalc[8][8] = 
{
	{ v_e, v_i, v_j, v_k, v_E, v_I, v_J, v_K },
	{ v_i, v_E, v_k, v_J, v_I, v_e, v_K, v_j },
	{ v_j, v_K, v_E, v_i, v_J, v_k, v_e, v_I },
	{ v_k, v_j, v_I, v_E, v_K, v_J, v_i, v_e },
	{ v_E, v_I, v_J, v_K, v_e, v_i, v_j, v_k },
	{ v_I, v_e, v_K, v_j, v_i, v_E, v_k, v_J },
	{ v_J, v_k, v_e, v_I, v_j, v_K, v_E, v_i },
	{ v_K, v_J, v_i, v_e, v_k, v_j, v_I, v_E }
};

char c2i[256];

void prepare()
{
	c2i['1'] = v_e;
	c2i['i'] = v_i;
	c2i['j'] = v_j;
	c2i['k'] = v_k;
}

char mul(char a, char b)
{
	return mulPrecalc[a][b];
}
char power(char x, long long y)
{
	char res = v_e;
	while (y)
	{
		if (y & 1ll) 
		{
			res = mul(res, x); --y;
		}
		else 
		{
			x = mul(x, x); y >>= 1;
		}
	}
	return res;
}

const char ijk = mul(v_i, mul(v_j, v_k));

bool good(const string & s, long long N)
{
	const int iterations = 40;
	N = min((long long)iterations, N);
	int n = (int)N;
	vector<char> a;
	a.reserve(n * s.length() + 1);
	for (int i = 0; i < n; ++i)
	{
		a.insert(a.end(), s.begin(), s.end());
	}
	size_t i = 0;
	char res = v_e;

	char res1 = v_e;
	for (size_t j = 0; j < a.size(); ++j)
	{
		res1 = mul(res1, c2i[a[j]]);
	}

	for (; (i < a.size()) && (res != v_i); ++i)
	{
		res = mul(res, c2i[a[i]]);
	}
	if (res != v_i)return false;
	res = v_e;
	for (; (i < a.size()) && (res != v_j); ++i)
	{
		res = mul(res, c2i[a[i]]);
	}
	if (res != v_j)return false;
	return true;
}

void solve()
{
	long long X, N;
	cin >> X >> N;
	string s; cin >> s;
	char m = v_e;
	for (int i = 0; i < X; ++i)
	{
		m = mul(m, c2i[s[i]]);
	}

	m = power(m, N);
	if (m != ijk)
	{
		cout << "NO" << endl;
		return;
	}

	if (good(s, N))
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
}

int main() 
{
	std::ios_base::sync_with_stdio(0);
#ifdef GRANDVIC_DEBUG
	//freopen("d:/input.txt", "rt", stdin);
#endif
	prepare();
	int T; cin >> T;
	for (int t = 1; t <= T; ++t)
	{
		cout << "Case #" << t << ": ";
		solve();
	}
}


