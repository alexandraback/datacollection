//C.cpp

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <deque>
#include <set>

using namespace std;

int main(int argc, char const *argv[])
{
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t)
	{
		int N;
		cin >> N;
		int bffs[N+1] = {0};

		for (int i = 1; i <= N; ++i)
		{
			cin >> bffs[i];
		}

		int longest = 0;
		for (int i = 1; i <= N; ++i)
		{
			set<int> count;
			count.insert(i);
			int bf = bffs[i];
			int lastbf = 0;
			while (count.find(bf) == count.end()) {
				count.insert(bf);
				lastbf = bf;
				bf = bffs[bf];
			}
			
			for (int i = 1; i < N; ++i)
			{
				if (bffs[i] == lastbf && count.find(i) == count.end()) {
					count.insert(i);
					break;
				}
			}

			int len = count.size();
			if (len > longest) {
				longest = len;
			}
		}

		cout << "Case #" << t+1 << ": " << longest << endl;

	}

	return 0;
}