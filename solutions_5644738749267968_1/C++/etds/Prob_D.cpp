
#define PROBLEM_NAME "D"
#define PROBLEM_SMALL_INPUT "-small-attempt0"
#define PROBLEM_LARGE_INPUT "-large"

#include <set>

int main(int argc, char* argv[])
{
//	set_fio(PROBLEM_NAME ".txt");
//	set_fio(PROBLEM_NAME PROBLEM_SMALL_INPUT ".in");
//	set_fio(PROBLEM_NAME PROBLEM_SMALL_INPUT ".in", PROBLEM_NAME PROBLEM_SMALL_INPUT ".out.txt");
//	set_fio(PROBLEM_NAME PROBLEM_LARGE_INPUT ".in");
	set_fio(PROBLEM_NAME PROBLEM_LARGE_INPUT ".in", PROBLEM_NAME PROBLEM_LARGE_INPUT ".out.txt");

	const int CELL_NULL = 0;
	const int CELL_BOMB = 100;

	int T;
	fin >> T;
	for (int cases=1; cases<=T; ++cases)
	{
		int N;
		fin >> N;

		std::set<double> naomi1, ken1, naomi2, ken2;
		for (int i=0; i<N; ++i)
		{
			double d;
			fin >> d;
			naomi1.insert(d);
			naomi2.insert(d);
		}
		for (int i=0; i<N; ++i)
		{
			double d;
			fin >> d;
			ken1.insert(d);
			ken2.insert(d);
		}

		// for deceitful war : naomi1, ken1
		// kill ken's biggest with naomi's smallest
		int score1 = 0;
		for (int i=0; i<N; ++i)
		{
			double naomi_min = *naomi1.begin();
			double ken_max = *ken1.rbegin();
			double ken_min = *ken1.begin();

			if (naomi_min > ken_min)
			{
				score1++;
				naomi1.erase(naomi_min);
				ken1.erase(ken_min);
			}
			else
			{
				naomi1.erase(naomi_min);
				ken1.erase(ken_max);
			}
		}

		// for normal war : naomi2, ken2
		// kill naomi's by using a ken's block just a little bit larger than naomi's
		int score2 = 0;
		for (int i=0; i<N; ++i)
		{
			double naomi_min = *naomi2.begin();
			std::set<double>::iterator it = ken2.upper_bound(naomi_min);
			if (it == ken2.end())
			{
				double ken_min = *ken2.begin();
				if (naomi_min > ken_min)
					score2++;
				naomi2.erase(naomi_min);
				ken2.erase(ken_min);
			}
			else
			{
				double ken_larger = *it;
				if (naomi_min > ken_larger)
					score2++;
				naomi2.erase(naomi_min);
				ken2.erase(ken_larger);
			}
		}

		fout << "Case #" << cases << ": " << score1 << " " << score2 << endl;
	}

	return 0;
}
