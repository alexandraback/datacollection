#include <fstream>

using namespace std;

struct level
{
	int stars_obt;
	int stars_for1;
	int stars_for2;
};

int main (void)
{
	int T, N, i, j, count, stars;
	level levels[1100];
	fstream fin, fout;
	bool done;

	fin.open ("B-small-attempt1.in", ios::in);
	fout.open ("output.txt", ios::out);

	fin >> T;
	for (i = 1; i <= T; i++)
	{
		fin >> N;
		for (j = 0; j < N; j++)
		{
			levels[j].stars_obt = 0;
			fin >> levels[j].stars_for1;
			fin >> levels[j].stars_for2;
		}

		count = 0;
		done = false;
		stars = 0;
		while (!done)
		{
			for (j = 0; j < N; j++)
			{
				if (levels[j].stars_obt == 0 && levels[j].stars_for2 <= stars)
				{
					stars += 2;
					levels[j].stars_obt = 2;
					count++;
					break;
				}
			}

			if (j == N)
			{
				for (j = 0; j < N; j++)
				{
					if (levels[j].stars_obt == 1 && levels[j].stars_for2 <= stars)
					{
						stars += 1;
						levels[j].stars_obt = 2;
						count++;
						break;
					}
				}
				
				if (j == N)
				{
					for (j = 0; j < N; j++)
					{
						if (levels[j].stars_obt < 1 && levels[j].stars_for1 <= stars)
						{
							levels[j].stars_obt = 1;
							count++;
							stars++;
							break;
						}
					}

					if (j == N)
						break;
				}
			}

			for (j = 0; j < N; j++)
				if (levels[j].stars_obt < 2)
					break;

			if (j == N)
				done = true;
		}

		if (done)
			fout << "Case #" << i << ": " << count << "\n";
		else
			fout << "Case #" << i << ": Too Bad\n";
	}

	return 0;
}