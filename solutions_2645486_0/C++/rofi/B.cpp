#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define	rep(i, n)	for(int i = 0 ; i < (n) ; ++i)

long long E, R, N;
vector<long long>	v;

long long check(int index, long long remE)
{
	if(index == N)
		return 0;

	long long	res = 0;
	rep(i, remE + 1)
		res = max(res, v[index] * i + check(index + 1, min(E, remE - i + R)));

	return res;
}

long long solve()
{
	cin >> E >> R >> N;
	vector<long long>(N).swap(v);
	rep(i, N)
		cin >> v[i];

	v.clear();
	return check(0, E);
}

int main()
{
	int		T;

	cin >> T;
	rep(i, T)
		cout << "Case #" << (i + 1) << ": " << solve() << endl;
}

