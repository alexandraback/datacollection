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
		int64 n;
		cin >> n;

		if (n == 1 || n == 0)
		{
			cout << "Case #" << t + 1 << ": " << 0 << endl;
			continue;
		}

		int64 d, h, m;
		cin >> d >> h >> m;
		int64 d2, h2, m2;
		cin >> d2 >> h2 >> m2;

		if (m == m2)
		{
			cout << "Case #" << t + 1 << ": " << 0 << endl;
			continue;
		}

		if (m < m2)
		{
			swap(m, m2);
			swap(d, d2);
		}
		int rD1 =  360 - d;
		int rD2 =  360 - d2;

		
		int enc = rD1 / m2;
		int enc2 = rD2 / m;

		if (rD1 >= rD2)
		{
			enc++;
		}
		if (rD1 <= rD2)
		{
			enc2++;
		}
		

		cout << "Case #" << t + 1 << ": " << min(enc, enc2) << endl;
	}
	return 0;
}