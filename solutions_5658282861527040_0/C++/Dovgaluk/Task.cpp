#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

int main()
{
	int T;
	std::cin >> T;
	for (int t = 1 ; t <= T ; ++t)
	{
        int A, B, K;
        std::cin >> A >> B >> K;
        long long res = 0;
        for (int i = 0 ; i < A ; ++i)
            for (int j = 0 ; j < B ; ++j)
                if ((i & j) < K)
                    ++res;
        std::cout << "Case #" << t << ": " << res << "\n";
	}
	return 0;
}

