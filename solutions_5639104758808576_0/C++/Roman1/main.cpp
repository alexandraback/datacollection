#include <cassert>
#include <fstream>
#include <string>
#include <vector>

int
main(int argc, char **argv)
{
	std::ifstream in("input.txt");
	std::ofstream out("output.txt");

	int T;
	in >> T;
	for (int t = 0; t < T; t++)
	{
		int Smax;
		in >> Smax;

		std::string people;
		in >> people;

		assert(people.length() == Smax + 1);

		int add_people = 0;
		int people_clapping = 0;

		for (int i = 0; i <= Smax; i++)
		{
			int cnt = people[i] - '0';

			if (cnt > 0
				&& people_clapping < i)
			{
				int diff = (i - people_clapping);

				add_people += diff;
				people_clapping += diff;
			}

			people_clapping += cnt;
		}

		out << "Case #" << (t + 1) << ": " << add_people << std::endl;
	}

	in.close();
	out.close();

	return 0;
}