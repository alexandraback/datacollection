#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

long long gcd(long long a, long long b)
{
    if (a == 0 || b == 0)
        return a + b;
    return gcd(b % a, a);
}

int main()
{
	int T;
	std::cin >> T;
	for (int t = 1 ; t <= T ; ++t)
	{
        char c;
        long long p, q;
        std::cin >> p >> c >> q;
        long long g = gcd(p, q);
        p /= g;
        q /= g;
        int v = 1;
        while (q > (1LL << v))
            ++v;
        if (q != (1LL << v))
            std::cout << "Case #" << t << ": impossible\n";
        else
        {
            int y = 0;
            while (p < q)
            {
                p *= 2;
                ++y;
            }
            std::cout << "Case #" << t << ": " << y << "\n";
        }
	}
	return 0;
}

