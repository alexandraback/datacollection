#include <cstdio>
#include <cassert>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

int compute(int r, int c, int w)
{
	int count=0;

	if ((r == 1) && (c == w))
		return w;

	count += c/w;	// before initial hit
	count *= r;
	count += w;

	if ((c % w) == 0)
		count--;

	return count;
}

int main(void)
{
	int T;
	int R, C, W;
	int result;

	assert(scanf("%d", &T));

	for (int i = 0; i < T; i++) {
		assert(scanf("%d %d %d", &R, &C, &W));
		result = compute(R, C, W);
		cout << "Case #" << i + 1 << ": " << result << endl;
	}
	return 0;
}
