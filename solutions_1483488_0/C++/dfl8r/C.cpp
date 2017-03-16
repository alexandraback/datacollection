#include <fstream>
#include <set>
#include <sstream>
#include <string>
using namespace std;

string FILENAME = "C-small-attempt0";
//string FILENAME = "C-large";

int main()
{
	ifstream in;
	ofstream out;

	int T, A, B;
	int count, pairs, len, num;
	char temp;
	char perm[20];

	set<int> perms;
	set<int>::iterator it;

	in.open(FILENAME + ".in");
	out.open(FILENAME + ".out");

	in >> T;

	for (int i = 0; i < T; i++)
	{
		in >> A;
		in >> B;

		count = 0;
		perms.clear();

		out << "Case #" << i + 1 << ": ";

		for (int j = A; j <= B; j++)
		{
			pairs = perms.size();

			if (perms.insert(j).second)
			{
				itoa(j, perm, 10);
				len = strlen(perm);

				for (int k = 0; k < len - 1; k++)
				{
					// Get the next permutation
					temp = perm[0];
					for (int l = 0; l < len - 1; l++)
						perm[l] = perm[l + 1];
					perm[len - 1] = temp;

					if (perm[0] == '0')
						continue;
					
					num = atoi(perm);

					if (num < A || num > B)
						continue;

					perms.insert(num);
				}
			}

			pairs = perms.size() - pairs;
			pairs = (pairs - 1) * pairs / 2; // (pairs - 1) choose 2; 

			count += pairs;
		}

		out << count << endl;
	}

	in.close();
	out.close();

	return 0;
}