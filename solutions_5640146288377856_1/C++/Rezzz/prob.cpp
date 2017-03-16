#include <iostream>
#include <sstream>
#include <climits>
#include <cstring>

using namespace std;

int main()
{
	int T = 0;
	string line;
	getline(std::cin, line);
	std::istringstream stream(line);
	stream >> T;

	for(int i = 1; i <= T; i++)
	{
		int R;
		int C;
		int W;
		getline(std::cin, line);
		std::istringstream stream1(line);
		stream1 >> R >> C >> W;

		int count = 0;

		int rem = C % W;
		int perRow = C / W;

		count = perRow * R;

		if(rem == 0)
		{
			count += (W - 1);
		}
		else
		{
			count += W;
		}

		cout << "Case #" << i << ": " << count << endl;
	}
}