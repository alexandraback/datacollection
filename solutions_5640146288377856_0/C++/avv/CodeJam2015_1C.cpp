// CodeJam2015_1B.cpp : Defines the entry point for the console application.
//

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
	fstream cout("out.txt", fstream::out);
	cin >> T;
	

	for (int t = 0; t < T; ++t)
	{
		std::cout << t << endl;

		int r, c, w;
		cin >> r >> c >> w;

		int res = c / w;
		res = res * r;
		if (c % w != 0)
		{
			res++;
		}
		res += (w - 1);
		cout <<  "Case #" << t + 1 << ": " << res << endl;
	}
	return 0;
}