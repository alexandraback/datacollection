#include <fstream>
#include <string>
using namespace std;

string FILENAME = "B-large";

const int NORMAL_OFFSETS[] = { 0, 1, 1 };
const int SURPRISE_OFFSETS[] = { 1, 1, 2 };

int main()
{
	ifstream in;
	ofstream out;

	int T, N, S, P, Ti;
	int count, R, Q;

	in.open(FILENAME + ".in");
	out.open(FILENAME + ".out");

	in >> T;

	for (int i = 0; i < T; i++)
	{
		in >> N;
		in >> S;
		in >> P;

		count = 0;

		out << "Case #" << i + 1 << ": ";

		for (int j = 0; j < N; j++)
		{
			in >> Ti;

			Q = Ti / 3;
			R = Ti % 3;

			if (Q + NORMAL_OFFSETS[R] >= P)
				count++;
			else if (S > 0 && Q + SURPRISE_OFFSETS[R] >= P && (Q > 0 || R == 2))
			{
				count++;
				S--;
			}
		}

		out << count << endl;
	}

	in.close();
	out.close();

	return 0;
}