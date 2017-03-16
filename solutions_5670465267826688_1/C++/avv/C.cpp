

#include "vector"
#include "string"
#include "set"
#include "map"
#include "sstream"
#include "algorithm"
#include "cmath"
#include "cassert"
#include "iostream"
#include "numeric"
#include "fstream"
#include "queue"
#include <functional>
#include  <climits>

#ifdef __GNUC__
#include  <tr1/unordered_map>
#define unordered_map tr1::unordered_map
#else
#include <unordered_map>
#endif

using namespace std;

#define int64 long long
#define F(vec, index) for (int index = 0; index  < vec.size(); ++index)
#define F2(index, vec) for (int index = 0; index  < vec.size(); ++index)
#define F3(index, from, vec) for (int index = from + 1; index  < vec.size(); ++index)


int GetPos(char c)
{
	if (c == '1') return 0;
	if (c == 'i') return 1;
	if (c == 'j') return 2;
	if (c == 'k') return 3;
	assert(false);
	//return 3;
}



char table[4][4] = 
	{
		{1, 'i', 'j', 'k'}, 
		{'i', '1', 'k', 'j'},
		{'j', 'k', '1', 'i'},
		{'k', 'j', 'i', '1'}
	};
bool tableSign[4][4] = {
	{true, true, true, true}, 
	{true, false, true, false},
	{true, false, false, true},
	{true, true, false, false}
};



bool Solve1(string str, int64 x)
{
	if (x == 1 && str == "ijk")
	{
		return true;
	}
	if (x * str.size() <= 3)
	{
		return false;
	}

	bool plus = true;
	char c = str[0];
	
	for (int i = 1; i < str.size(); ++i)
	{
		int pos = GetPos(c);
		int pos2 = GetPos(str[i]);
		c = table[pos][pos2];
		if (!tableSign[pos][pos2]) plus = !plus;
	}
	if (c != '1')
	{
		if (x % 2 == 0)
		{
			plus = true;

			c = '1';
			x = x / 2;
			if (x % 2 != 0)
			{
				plus = !plus;
			}
		}
		else
		{
			x = x / 2;
			if (x % 2 != 0)
			{
				plus = !plus;
			}
		}
	}
	else
	{
		if (x % 2 == 0)
		{
			plus = true;
		}
	}



	

	if (!(c == '1' && !plus))
	{
		return false;
	}

	bool wasI = false;
	bool wasNotI = false;
	c = str[0];
	string concat;
	for (int i = 0; i < min(x, (int64)30); ++i)
	{
		concat.append(str);
	}
	
	for (int i = 1; i < concat.size(); ++i)
	{
		int pos = GetPos(c);
		int pos2 = GetPos(concat[i]);
		c = table[pos][pos2];
		if (c == 'i') 
		{
			wasI = true;
			continue;
		};
		if (concat[i] != 'i' && wasI) wasNotI = true;
	}
	if (!wasNotI || !wasI) return false;
	return true;
}

int S = 10001;
vector<char> cache1;
vector<int> cache2;
void Calc(string& str, int from, int to, char& c, int& plus)
{
	assert(to > from);
	assert(to <= str.size());
	if (cache1[S * from + to] != 'x')
	{
		c = cache1[S * from + to];
		plus = cache2[S * from + to];
		return;
	}
	int start;
	if (to > 0 && cache1[S * from + to - 1] != 'x')
	{
		c = cache1[S * from + to - 1];
		plus = cache2[S * from + to - 1];
		start = to - 1;
		
	}
	else
	{
		c = str[from];
		plus = 1;
		start = from + 1;
	}
	
	for (int i = start; i < to; ++i)
	{
		int pos = GetPos(c);
		int pos2 = GetPos(str[i]);
		c = table[pos][pos2];
		if (!tableSign[pos][pos2]) plus = plus * -1;
	}
	cache1[S * from + to] = c;
	cache2[S * from + to] = plus;
	
}

bool Solve2(string strOr, int64 x)
{
	/*if (x == 1 && strOr == "ijk")
	{
		return false;
	}
	if (x * strOr.size() <= 3)
	{
		return false;
	}*/

	string str;
	for (int i = 0; i < x; ++i)
		str.append(strOr);

	cache1.clear();
	cache1.resize(S *  S, 'x');
	cache2.clear();
	cache2.resize(S *  S, 0);
	//if (str == "ijk") return true;
	//if (3 >= str.size()) return false;


	for (int i = 0; i < str.size() - 1; ++i)
	{
		for (int j = i + 1; j <= str.size(); ++j)
		{
			char c;
			int plus;
			Calc(str, i, j, c, plus);
		}
	}

	std::cout << "created cache" << endl;

	for (int i = 1; i < str.size() - 1; ++i)
	{
		for (int j = i + 1; j < str.size(); ++j)
		{
			char c1;
			int plus1;
			Calc(str, 0, i, c1, plus1);

			char c2;
			int plus2;
			Calc(str, i, j, c2, plus2);

			char c3;
			int plus3;
			Calc(str, j, str.size(), c3, plus3);
			assert(plus1 * plus2 * plus3 != 0);
			if (c1 == 'i' && c2 == 'j' && c3 == 'k' && plus1 * plus2 * plus3 > 0)
			{
				return true;
			}
		}
	}
	return false;
}





int main(int argc, char* argv[])
{
	int T;
	fstream cin("input.txt");
	fstream cout("result.txt",fstream::out);
	cin >> T;
	
	for (int t = 1; t <= T; ++t)
	{
		std::cout << t << endl; 
		int64 x, l;
		cin >> l >> x;

		string str;
		cin >> str;

		//str.resize(1000);
		//if (x * l > 1000) continue;
		bool res1 = Solve1(str, x);
		//bool res2 = Solve2(str, x);
		//assert(res1 == res2);
		//if (res1 != res2) std::cout << "error" << endl; 
		if (res1)
		{
			cout << "Case #" << t << ": " << "YES" << endl;
		}
		else
		{
			cout << "Case #" << t << ": " << "NO" << endl;
		}


		

	}

	return 0;
}
