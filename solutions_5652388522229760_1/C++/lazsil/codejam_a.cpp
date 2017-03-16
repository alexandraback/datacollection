#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;


int main()
{
	int num_of_testcases;
	cin >> num_of_testcases;
	for (int t = 1; t <= num_of_testcases; ++t){
		int n;
		cin >> n;

		if (n == 0) {
			cout << "Case #" << t << ": INSOMNIA" << "\n";
		}
		else {
			set<int> missing{ 0,1,2,3,4,5,6,7,8,9 };

			int newvalue = n;
			bool found = false;
			do {
				int tmp = newvalue;
				do
				{
					int digit = tmp % 10;
					missing.erase(digit);
					if (missing.size() == 0)
					{
						found = true;
						break;
					}

					tmp /= 10;
				} while (tmp > 0);

				if (found)
					break;
				newvalue += n;;
			} while (true);

			cout << "Case #" << t << ": " << newvalue << "\n";
		}
	}

    return 0;
}

