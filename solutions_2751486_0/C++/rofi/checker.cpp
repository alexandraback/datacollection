#include <string>
#include <iostream>
#include <vector>
#include <deque>
#include <numeric>

using namespace std;

typedef long long	LL;

#define	For(i, a, b)	for(int i = (a) ; i < (b) ; ++i)
#define	rep(i, n)		For(i, 0, n)

inline bool vowel(const char c)
{
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

LL C(int n)
{
	if(n < 2)
		return 0;
	return ((LL)n) * (n - 1) / 2;
}

LL solve()
{
	string	str;
	int		n;
	int		res = 0;

	cin >> str >> n;

	rep(i, str.size()) {
		For(j, i, str.size()) {
			int		num = 0;
			For(k, i, j + 1) {
				if(vowel(str[k]))
					num = 0;
				else
					++num;
				if(num == n) {
					++res;
					break;
				}
			}
		}
	}
	return res;
}

int main()
{
	int		T;
	cin >> T;
	rep(i, T)
		cout << "Case #" << (i + 1) << ": " << solve() << endl;
}

