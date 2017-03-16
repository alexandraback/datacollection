#include <math.h>
#include <iostream>

using namespace std;

const double pi = 3.14159265358979323846;

int main(int argc, char* argv[])
{
	int T, r, t;
	cin >> T;
	for (int t_ = 0; t_ != T; ++t_) {
		cin >> r >> t;
		int count = 0;
		long paintSheHas = t;
		while (true) {
			long paintSheNeeds = 2 * r + 1;
			if (paintSheHas < paintSheNeeds)
				break;
			count++;
			paintSheHas -= paintSheNeeds;
			r += 2;
		}
		cout << "Case #" << (t_ + 1) << ": " << count << "\n";
	}	
	return 0;
}

