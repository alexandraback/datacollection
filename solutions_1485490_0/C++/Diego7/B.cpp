#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;

ull solve(vector<ull> vn, vector<ull> vm, int in, int im)
{
	if (in >= vn.size()) return 0;
	if (im >= vm.size()) return 0;
	if (vn[in+1] == vm[im+1])
	{
		ull sum = 0;
		if (vn[in] > vm[im])
		{
			sum += vm[im];
			vn[in] -= sum;

			sum += solve(vn, vm, in, im+2);
		}
		else if (vn[in] < vm[im])
		{
			sum += vn[in];
			vm[im] -= sum;
			sum += solve(vn, vm, in+2, im);
		}
		else
		{
			sum += vm[im];
			sum += solve(vn, vm, in+2, im+2);
		}
		return sum;
	}

	ull sum1 = 0;
	ull sum2 = 0;
	sum1 = solve(vn, vm, in+2, im);
	sum2 = solve(vn, vm, in, im+2);
	//cout << sum1 << ", " << sum2 << endl;
	return max(sum1, sum2);
}

int main(int argc, const char *argv[])
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i ++)
	{
		int N, M;
		cin >> N >> M;
		vector<ull> vn(N*2), vm(M*2);
		for (int j = 0; j < N*2; j ++)
		{
			cin >> vn[j];
		}
		for (int j = 0; j < M*2; j ++)
		{
			cin >> vm[j];
		}

		cout << "Case #" << i+1 << ": " << solve(vn, vm, 0, 0) << endl;
	}
	return 0;
}
