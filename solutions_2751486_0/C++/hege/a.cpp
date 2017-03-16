#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <sstream>
#include <list>
#include <numeric>

using namespace std;

class Solver
{
public:
	string Solve()
	{
		string name;
		size_t n;
		cin >> name >> n;
		const size_t L = name.length();
		vector<bool> ctypes(L);
		transform(name.begin(), name.end(), ctypes.begin(), [](char c) { return c == 'a' || c == 'e' || c == 'u' || c == 'i' || c == 'o'; } );

		// TODO: here
		size_t i, j, cnt, total = 0;
		for ( i = 0; i < L; ++i ) {
			cnt = 0;
			for ( j = i; j < L; ++j ) {
				if ( !ctypes[j] ) { 
					if ( ++cnt >= n ) {
						total += L - j;
						break;
					}
				}
				else
					cnt = 0;
			}
		}

		stringstream ss;
		ss << total;
		return ss.str();
	}
};

int main()
{
	int T;
	cin >> T;
	for ( int t = 0; t < T; ++t )
	{
		cout << "Case #" << (t+1) << ": " << Solver().Solve() << endl;
	}
	return 0;
}
