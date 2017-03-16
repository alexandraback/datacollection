
#define PROBLEM_NAME "B"
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

	int T;
	fin >> T;
	for (int cases=1; cases<=T; ++cases)
	{
		double C_FarmPrice, F_Gain, X_Goal;
		fin >> C_FarmPrice >> F_Gain >> X_Goal;

		int FarmCount = 0;
		double GainPerSec = 2;
		double TimeLastFarmBuying = 0;
		double TimeTotal = 0;

		while (true)
		{
			double TimeTotalWithNoBuying
				= TimeLastFarmBuying
				+ X_Goal / GainPerSec; // maintain current gain to reach goal

			double TimeTotalWithBuying
				= TimeLastFarmBuying
				+ C_FarmPrice / GainPerSec // time to gather cookie to buy farm
				+ X_Goal / (GainPerSec + F_Gain); // time to gather with new gain

			// no need to buy farm
			if (TimeTotalWithNoBuying <= TimeTotalWithBuying)
			{
				TimeTotal = TimeTotalWithNoBuying;
				break;
			}
			// it's better to buy farm
			else
			{
				FarmCount++;
				TimeLastFarmBuying += C_FarmPrice/GainPerSec;
				GainPerSec += F_Gain;
			}
		}

		fout << "Case #" << cases << ": " << std::fixed << std::setprecision(7) << TimeTotal << endl;
	}

	return 0;
}
