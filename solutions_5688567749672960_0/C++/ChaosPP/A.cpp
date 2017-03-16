#include <stdio.h>
#include <string.h>
#include <iostream>
#include <map>

using namespace std;

map<long long, int> M;

long long swap(long long val)
{
	long long temp = val;
	long long ret = 0;

	while (temp != 0) {
		ret += (temp % 10);
		temp = temp / 10;
		if (temp == 0) break;
		ret = ret * 10;
	}

	return ret;
}

long long Solve(long long val)
{
	if (val < 10)
		return val;

	if (M.find(val) != M.end())
		return M[val];

	long long temp2 = 987654321;
	if (val % 10 != 0 && val != swap(val) && val > swap(val))
		temp2 = Solve(swap(val));

	long long temp1 = Solve(val - 1);


	if (temp1 < temp2) {
		M[val] = temp1 + 1;
		return temp1 + 1;
	}
	else {
		M[val] = temp2 + 1;
		return temp2 + 1;
	}
}

int main()
{
	int T;

	scanf("%d", &T);
	for (int w = 0; w < T; w++) {
		long long N;
		scanf("%lld", &N);

		printf("Case #%d: %lld\n", w+1, Solve(N));
	}

	return 0;
}