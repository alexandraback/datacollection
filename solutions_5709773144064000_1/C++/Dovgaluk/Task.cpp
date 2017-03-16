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
        double c, f, x;
        std::cin >> c >> f >> x;
        double t0 = 0;
        double ff = 2;
        double tmin = x / ff;
        while (1)
        {
            double tt = x / ff + t0;
            if (tt > tmin)
                break;
            tmin = tt;
            t0 += c / ff;
            ff += f;
        }
        std::cout << "Case #" << t << ": ";
        std::cout.setf(std::ios::fixed);
        std::cout.precision(7);
        std::cout << tmin << "\n";
	}
	return 0;
}

