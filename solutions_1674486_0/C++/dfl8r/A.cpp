#include <fstream>
#include <string>
#include <set>
using namespace std;

//string FILENAME = "A-test";
string FILENAME = "A-small-attempt1";
//string FILENAME = "A-large";

int main()
{
	ifstream in;
	ofstream out;

	int T, M, N, A;
	bool diamond;

	set<int> mySet[1000];
	set<int>::iterator it, it2;
	pair<set<int>::iterator, bool> ret;

	in.open(FILENAME + ".in");
	out.open(FILENAME + ".out");

	in >> T;

	for (int i = 0; i < T; i++)
	{
		in >> N;
		diamond = false;

		out << "Case #" << i + 1 << ": ";

		for (int j = 0; j < N; j++)
		{
			mySet[j].clear();
			in >> M;

			for (int k = 0; k < M; k++)
			{
				in >> A;
				mySet[j].insert(A);
			}
		}

		for (int j = 0; j < N; j++)
		{
			int replace;

			do
			{
				replace = false;

				set<int> newSet;

				for (it = mySet[j].begin(); it != mySet[j].end(); ++it)
				{
					int k = *it - 1;
					for (it2 = mySet[k].begin(); it2 != mySet[k].end(); ++it2)
					{
						replace = true;

						ret = newSet.insert(*it2);

						if (!ret.second)
						{
							diamond = true;
							break;
						}
					}

					if (mySet[k].empty())
					{
						ret = newSet.insert(k + 1);

						if (!ret.second)
							diamond = true;
					}

					if (diamond)
						break;
				}

				if (diamond)
					break;

				mySet[j].clear();
				mySet[j].swap(newSet);
			}
			while (replace);

			if (diamond)
				break;
		}

		out << (diamond ? "Yes" : "No") << endl;
	}

	in.close();
	out.close();

	return 0;
}