#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

#define	For(i,a,b)				for(int i=(a);i<(b);++i)
#define	rep(i,n)				For(i,0,(n))


inline bool check(const string &c, int n)
{
	for(int i = c.size() - 1 ; 0 <= i ; --i) {
		if(c[i] != '?' && c[i] != '0' + (n % 10)) {
			return false;
		}
		n /= 10;
	}
	if(n)
		return false;
	return true;
}

string solve()
{
	string C, J;
	cin >> C >> J;

	int result_c = 999999, result_j = 9999999;
	rep(i, 1000) {
		rep(j, 1000) {
			if(check(C, i) && check(J, j)) {
				if(abs(i - j) < abs(result_c - result_j)) {
					result_c = i;
					result_j = j;
				} else if(abs(i - j) == abs(result_c - result_j)) {
					if(i < result_c) {
						result_c = i;
						result_j = j;
					} else if(i == result_c && j < result_j) {
						result_c = i;
						result_j = j;
					}
				}
			}
		}
	}

	stringstream ss;
	ss << setfill('0') << setw(C.size()) << result_c << " "
	   << setfill('0') << setw(J.size()) << result_j;

	return ss.str();
}

int main()
{
	int T;

	cin >> T;
	rep(i, T)
		cout << "Case #" << (i + 1) << ": " << solve() << endl;
}

