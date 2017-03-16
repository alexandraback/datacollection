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
	int T; cin >> T;
	for(int T_=1; T_<=T; ++T_)
	{
		int A, B, K; cin >> A >> B >> K;
		map<int, int> res;
		for(int a=0; a<A; ++a)
		{
			for(int b=0; b<B; ++b)
			{
				res[a&b] += 1;
			}
		}
		
		int ans = 0;
		for(auto it = res.begin(); it != res.end(); ++it)
		{
			if (it->first < K) ans += it->second;
		}
		
		printf("Case #%d: %d\n", T_, ans);
	}
	return 0;
}




