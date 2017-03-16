//B.cpp

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <deque>

using namespace std;

int main(int argc, char const *argv[])
{
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t)
	{
		int N;
		cin >> N;

		int occupe[2500] = {0};

		for (int i = 0; i < 2*N-1; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				int v;
				cin >> v;
				occupe[v] ++;
			}
		}

		cout << "Case #" << t+1 << ": ";
		for (int i = 0; i < 2500; ++i)
		{
			if (occupe[i] %2) {
				cout << i << " ";
			}
		}
		cout << endl;
	}

	return 0;
}