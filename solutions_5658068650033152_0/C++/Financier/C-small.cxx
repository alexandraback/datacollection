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
		int N, M, K; cin >> N >> M >> K;
		
		int ans = 0;
		if (N < 3 || M < 3) ans = K;
		else {
			if (N > M) swap(N, M);
			if (N == 3)
			{
				if (M == 3) 
				{
					if (K < 5) ans = K;
					else ans = K-1;
				}
				else if (M == 4)
				{
					if (K < 5) ans = K;
					else if (K < 8) ans = K-1;
					else ans = K -2;
				}
				else if (M == 5)
				{
					if (K < 5) ans = K;
					else if (K < 8) ans = K-1;
					else if (K < 11) ans = K-2;
					else ans = K-3;
				}
				else if (M == 6)
				{
					if (K < 5) ans = K;
					else if (K < 8) ans = K-1;
					else if (K < 11) ans = K-2;
					else if (K < 14) ans = K-3;
					else ans = K-4;
				}
			}
			else if (N == 4)
			{
				if (M == 4)
				{
					if (K < 5) ans = K;
					else if (K < 8) ans = K-1;
					else if (K < 10) ans = K-2;
					else if (K < 12) ans = K-3;
					else ans = K-4;
				}
				else if (M == 5)
				{
					if (K < 5) ans = K;
					else if (K < 8) ans = K-1;
					else if (K < 10) ans = K-2;
					else if (K < 12) ans = K-3;
					else if (K < 14) ans = K-4;
					else if (K < 16) ans = K-5;
					else ans = K-6;
				}
			}
			else {
				cout << " UNEXPE!!! " << endl;
			}
		}
		
		printf("Case #%d: %d\n", T, ans);
	}
	return 0;
}