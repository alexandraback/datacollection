#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>

using namespace std;

typedef unsigned int u32;
typedef unsigned long long u64;


u64 bcd(u64 a, u64 b)
{
	for (u64 tmp = b; b > 0; a = tmp)
	{
		tmp = b;
		b = a % b;
	}
	return a;
}

bool log2(u64 x, u32 & log)
{
	log = 0;
	while (!(x & 1) && x > 1) { x >>= 1; ++log; }
	return 1 == x;
}

int main()
{
	ifstream in("input.in");
	ofstream out("output.out");

	u32 T;
	in >> T;
	++T;

	for (u32 i = 1; i < T; ++i)
	{
		u64 P, Q;
		in >> P;
		in.ignore(1, '/');
		in >> Q;
		
		u64 mod = bcd(P, Q);
		P /= mod;
		Q /= mod;

		u32 log;
		bool hasSolution = log2(Q, log);

		cout << "Case #" << i << ": ";
		out << "Case #" << i << ": ";
		if (!hasSolution)
		{
			cout << "impossible";
			out << "impossible";
		}
		else
		{
			u32 count = 0;
			for (; P < Q; ++count)
			{
				P *= 2;
			}
			if (count <= log)
			{
				cout << count;
				out << count;
			}
			else
			{
				cout << "impossible";
				out << "impossible";
			}
		}

		cout << endl;
		out << endl;

		
	}

	out.close();
	in.close();
	getchar();
	return 0;
}
