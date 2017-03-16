// Codejam2014_1C.cpp : Defines the entry point for the console application.
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
#ifdef __GNUC__
#include  <tr1/unordered_map>
#define unordered_map tr1::unordered_map
#else
#include <unordered_map>
#endif

using namespace std;

#define int64 long long
#define F(vec, index) for (int index = 0; index  < vec.size(); ++index)
#define F_S(vec, index, start) for (int index = start; index  < vec.size(); ++index)


int64 GCD(int64 u, int64 v) {
    while ( v != 0) {
        int64 r = u % v;
        u = v;
        v = r;
    }
    return u;
}

int main(int argc, char* argv[])
{
	ifstream cin("in.txt");
	ofstream cout("out.txt");

	int T;
	cin >> T;
	for (int t = 0; t < T; ++t)
	{
	
		int64 P, Q;
		string str;
		cin >> str;

		string strP = str.substr(0, str.find('/'));
		string strQ = str.substr(str.find('/') + 1, str.size());

		stringstream stream1;
		stream1 << strP << " " << strQ;
		stream1 >> P >> Q;
		

		int64 gcd = GCD(P, Q);
		P /= gcd;
		Q /= gcd;
		
		int64 res = -1;
		int64 currPow = 2;
		for (int i = 1; i <= 40; ++i)
		{
			if (currPow == Q)
			{
				int64 currDel = 2;
				for (int j = 1; j <= 40; ++j)
				{
					if (P - Q / currDel >= 0)
					{
						res = j;
						break;
					}
					currDel = currDel * 2;
				}
				break;
			}
			currPow = currPow * 2;
		}

		if (res == -1)
			cout << "Case #" << t + 1 << ": "  << "impossible" << endl;
		else
			cout << "Case #" << t + 1 << ": "  << res << endl;
		
		
	}

	return 0;
}
