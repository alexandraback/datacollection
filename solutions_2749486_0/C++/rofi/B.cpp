#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

#define	rep(i, n)	for(int i = 0 ; i < (n) ; ++i)

const int	dx[] = {0, 1, 0, -1};
const int	dy[] = {1, 0, -1, 0};
const int	N = 0;
const int	E = 1;
const int	S = 2;
const int	W = 3;

string solve()
{
	string	res = "";
	int		X, Y;

	cin >> X >> Y;
	int		pos = 0;
	int		count = 1;

	while(pos != X) {
		res.push_back('E');
		pos += count;
		++count;
		if(pos == X)
			break;
		res.push_back('W');
		pos -= count;
		++count;
	}
	pos = 0;
	if(Y > 0) {
		res.push_back('S');
		pos -= count;
		++count;
	}
	while(pos != Y) {
		res.push_back('N');
		pos += count;
		++count;
		if(pos == Y)
			break;
		res.push_back('S');
		pos -= count;
		++count;
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


