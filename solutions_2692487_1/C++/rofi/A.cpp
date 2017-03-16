#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

#define	For(i, a, b)	for(int i = (a) ; i < (b) ; ++i)
#define	rep(i, n)		For(i, 0, n)

int I_MAX = 1 << 28;

pair<int, long long> operator+(const pair<int, long long> &a, const pair<int, long long> &b)
{
	return make_pair(a.first + b.first, a.second + b.second);
}

pair<int, long long> mm(const pair<int, long long> &a, const pair<int, long long> &b)
{
	if(a.first < b.first)
		return a;
	if(a.first > b.first)
		return b;
	return a.second > b.second ? a : b;
}

int solve()
{
	long long			A, N;

	cin >> A >> N;
	vector<long long>	motes(N);

	rep(i, N)
		cin >> motes[i];
	sort(motes.begin(), motes.end());

	++N;
	vector<vector<pair<int, long long>>>		res(N, vector<pair<int, long long>>(2 * N + 3, make_pair(I_MAX, (long long)0)));
	rep(i, N)
		res[i][0] = make_pair(i, (long long)0);
	res[0][0] = make_pair(0, A);
	For(i, 1, 2 * N + 3)
		res[0][i] = make_pair(i, 2 * res[0][i-1].second - 1);

	For(i, 1, N) {
		For(j, 1, 2 * N + 3) {
			int		x;
			if(motes[i-1] < res[i-1][j-1].second)
				x = 0;
			else
				x = 1;
			res[i][j] = mm(x ? make_pair(I_MAX, (long long)0) : (res[i-1][j-1] + make_pair(0, motes[i-1])), mm(res[i-1][j] + make_pair(1, (long long)0), res[i][j-1] + make_pair(1, res[i][j-1].second - 1)));
		}
	}
	return min_element(res[N-1].begin(), res[N-1].end())->first;
}

int main()
{
	int	T;
	cin >> T;
	rep(i, T)
		cout << "Case #" << (i + 1) << ": " << solve() << endl;
}

