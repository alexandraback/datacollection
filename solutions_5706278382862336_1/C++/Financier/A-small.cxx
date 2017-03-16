// This file was compiled using clang-503.0.40
// clang++ -o run.bin -std=c++11 task.cxx
// ./run.bin < data.in > data.out

# include <iostream>
# include <string>
# include <sstream>
# include <iomanip>

# include <algorithm>
# include <vector>
# include <map>
# include <set>
# include <queue>
# include <deque>
# include <stack>
# include <bitset>

# include <cstdio>
# include <cstdlib>
# include <ctime>
# include <climits>
# include <limits>
# include <cstring>
# include <cmath>

using namespace std;

int main()
{
	int T_inp; cin >> T_inp;
	for(int T=1; T<=T_inp; ++T)
	{
		int64_t A, B; scanf("%lld/%lld", &A, &B);
		
		int64_t GCD = __gcd(A, B);
		A /= GCD;
		B /= GCD;
		
		if (B & (B-1)) {
			printf("Case #%d: impossible\n", T);
		}
		else {
			int gen = 0;
			while (A < B) {
				A *= 2;
				++gen;
			}
			printf("Case #%d: %d\n", T, gen);
		}
	}
	return 0;
}