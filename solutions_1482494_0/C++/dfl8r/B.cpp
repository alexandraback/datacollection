#include <fstream>
#include <list>
#include <string>
#include <algorithm>
using namespace std;

//string FILENAME = "B-test";
string FILENAME = "B-small-attempt1";
//string FILENAME = "B-large";

struct sort_pred
{
    bool operator()(const pair<int, int> &left, const pair<int, int> &right)
	{
		if (left.second != right.second)
			return (left.second < right.second);
		else
			return (left.first > right.first);
    }
};

int main()
{
	ifstream in;
	ofstream out;

	int T, N, A, B;
	int count;
	int stars;
	bool first, second;

	in.open(FILENAME + ".in");
	out.open(FILENAME + ".out");

	in >> T;

	for (int i = 0; i < T; i++)
	{
		in >> N;

		count = 0;
		stars = 0;

		out << "Case #" << i + 1 << ": ";

		list<pair<int, int> > myList;
		list<pair<int, int> >::iterator it;
		list<pair<int, int> >::reverse_iterator rit;

		for (int j = 0; j < N; j++)
		{
			in >> A;
			in >> B;

			myList.push_back(make_pair(A, B));
		}

		myList.sort(sort_pred());

		while (!myList.empty())
		{
			second = false;

			for (it = myList.begin(); it != myList.end(); ++it)
			{
				if (stars >= it->second)
				{
					if (it->first >= 0)
						stars += 2;
					else
						stars++;
					second = true;
					count++;
				}
				break;
			}

			if (!second)
			{
				first = false;

				for (rit = myList.rbegin(); rit != myList.rend(); ++rit)
				{
					if (rit->first >= 0 && stars >= rit->first)
					{
						stars++;
						rit->first = -1;
						first = true;
						count++;
						break;
					}
				}

				if (!first)
				{
					count = 0;
					break;
				}
			}
			else
				myList.erase(it);
		}

		if (count > 0)
			out << count << endl;
		else
			out << "Too Bad\n";
	}

	in.close();
	out.close();

	return 0;
}