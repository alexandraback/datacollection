#include <fstream>
using namespace std;

int main()
{
	ifstream in ("2014round1BB.in");
	ofstream out ("2014round1BB.out");

	int T;
	in >> T;

	for (int t = 1; t <= T; t++)
	{
		int A, B, K;
		in >> A >> B >> K;

		int total = 0;
		for (int i = 0; i < A; i++)
			for (int j = 0; j < B; j++)
				if ((i & j) < K)
					total++;

		out << "Case #" << t << ": " << total << "\n";
	}

	in.close();
	out.close();
	return 0;
}