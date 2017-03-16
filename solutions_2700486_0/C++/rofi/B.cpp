#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

#define	For(i, a, b)	for(int i = (a) ; i < (b) ; ++i)
#define	rep(i, n)		For(i, 0, n)

pair<int, int> operator+(const pair<int, int> &a, const pair<int, int> &b)
{
	return make_pair(a.first + b.first, a.second + b.second);
}

pair<int, int> rec(int l, int r, int N, int h, int mh)
{
	if(!N) {
		if(r >= h)
			return make_pair(1, 1);
		return make_pair(0, 1);
	}

	pair<int, int>	res = make_pair(0, 0);
	if(l + 1 <= mh)
		res = res + rec(l + 1, r, N - 1, h, mh);
	if(r + 1 <= mh)
		res = res + rec(l, r + 1, N - 1, h, mh);
	return res;
}

double check(int N, int h, int mh)
{
	pair<int, int>	res = rec(0, 0, N, h + 1, mh);
	return (double)res.first / (double)res.second;
}

double solve()
{
	int		N, X, Y;
	cin >> N >> X >> Y;
	if(X < 0)
		X = -X;

	if(N == 1) {
		if(X == 0 && Y == 0)
			return 1.0;
		return 0.0;
	} else if(N < 5) {
		if((X + Y) / 2 > 1)
			return 0.0;
		if((X + Y) / 2 < 1)
			return 1.0;
		return check(N - 1, Y, 2);
	} else if(N == 5) {
		if((X + Y) / 2 <= 1 && Y != 2)
			return 1.0;
		return 0.0;
	} else if(N == 6) {
		if((X + Y) / 2 <= 1)
			return 1.0;
		return 0.0;
	} else if(N < 14) {
		if((X + Y) / 2 > 2)
			return 0.0;
		if((X + Y) / 2 < 2)
			return 1.0;
		return check(N - 6, Y, 4);
	} else if(N == 14) {
		if((X + Y) / 2 <= 2 && Y != 4)
			return 1.0;
		return 0.0;
	} else if(N == 15) {
		if((X + Y) / 2 <= 2)
			return 1.0;
		return 0.0;
	} else {
		if((X + Y) / 2 > 3)
			return 0.0;
		if((X + Y) / 2 < 3)
			return 1.0;
		return check(N - 15, Y, 6);
	}
}

int main()
{
	int	T;
	cin >> T;
	rep(i, T)
		printf("Case #%d: %0.8f\n", i + 1, solve());
}


