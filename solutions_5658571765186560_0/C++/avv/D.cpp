

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
		if (r == 4 && c == 4)
		{
			cout << "Case #" << t << ": " << "GABRIEL" << endl;continue;
		}
		if (r == 4 && c == 3)
		{
			cout << "Case #" << t << ": " << "GABRIEL" << endl;continue;
		}
		if (r == 4 && c == 2 && x <= 2)
		{
			cout << "Case #" << t << ": " << "GABRIEL" << endl;continue;
		}
		if (r == 4 && c == 1 && x <= 2)
		{
			cout << "Case #" << t << ": " << "GABRIEL" << endl;continue;
		}

		if (r == 3 && c == 3 && x <= 3)
		{
			cout << "Case #" << t << ": " << "GABRIEL" << endl;continue;
		}
		if (r == 3 && c == 2 && x <= 3)
		{
			cout << "Case #" << t << ": " << "GABRIEL" << endl;continue;
		}
		if (r == 3 && c == 1 && x <= 1)
		{
			cout << "Case #" << t << ": " << "GABRIEL" << endl;continue;
		}

		if (r == 2 && c == 2 && x <= 2)
		{
			cout << "Case #" << t << ": " << "GABRIEL" << endl;continue;
		}
		if (r == 2 && c == 1 && x <= 2)
		{
			cout << "Case #" << t << ": " << "GABRIEL" << endl;continue;
		}

		
		if (r == 1 && c == 1 && x <= 1)
		{
			cout << "Case #" << t << ": " << "GABRIEL" << endl;continue;
		}

		cout << "Case #" << t << ": " << "RICHARD" << endl;
	}

	return 0;
}
