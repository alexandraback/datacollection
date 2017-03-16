#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	ifstream 	f("in.txt");
	ofstream 	g("out.txt");
	int 		T, N;

	f >> T;
	for (int test = 1; test <= T; test++)
	{
		f >> N;
		vector<string> a(N), b(N);

		for (int i = 0; i < N; i++)
			f >> a[i] >> b[i];

		int maxFakers = 0;
		for (int mask = 0; mask < (1 << N); mask++)
		{
			int fakers = __builtin_popcount(mask);
			if (fakers <= maxFakers) continue;

			bool isValid = true;
			for (int i = 0; i < N && isValid; i++)
				if (mask & (1 << i))
				{
					int cnt1 = 0;
					int cnt2 = 0;
					for (int j = 0; j < N; j++)
						if (!(mask & (1 << j)))
						{
							if (a[i] == a[j]) cnt1++;
							if (b[i] == b[j]) cnt2++;
							if (cnt1 * cnt2) break;
						}
					if (!(cnt1 * cnt2)) isValid = false;
				}

			if (isValid) maxFakers = fakers;
		}

		g << "Case #" << test << ": " << maxFakers << endl;
	}

	return 0;
}
