

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




int main(int argc, char* argv[])
{
	int T;
	fstream cin("input.txt");
	fstream cout("result.txt",fstream::out);
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int x, r, c;
		cin >> x >> r >> c;

		if (c > r) swap(r, c);
		if (r * c % x != 0)
		{
			cout << "Case #" << t << ": " << "RICHARD" << endl;continue;
		}
		if (x >= 7)
		{
			cout << "Case #" << t << ": " << "RICHARD" << endl;continue;
		}
		if (x > r)
		{
			cout << "Case #" << t << ": " << "RICHARD" << endl;continue;
		}
		
		int firstAxe;
		int secondAxe;
		if (x % 2 == 0)
		{
			firstAxe = 1 + x / 2;
			secondAxe = x / 2;
		}
		else
		{
			firstAxe = 1 + x / 2;
			secondAxe = 1 + x / 2;
		}

		if (secondAxe > c)
		{
			cout << "Case #" << t << ": " << "RICHARD" << endl;continue;
		}
		if (secondAxe == c && secondAxe > 1 && firstAxe > 2 && firstAxe > secondAxe)
		{
			cout << "Case #" << t << ": " << "RICHARD" << endl;continue;
		}


		cout << "Case #" << t << ": " << "GABRIEL" << endl;
	}

	return 0;
}
