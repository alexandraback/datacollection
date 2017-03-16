#include "Precomp.h"
using namespace std;

int getNumOfFails(vector<bool>& fits)
{
	int result = 0;
	for (auto i = 0; i < fits.size(); ++i)
	{
		if (fits[i] == false)
		{
			result++;
		}
	}
	return result;
}

void checkFits(vector<int>& vec, vector<bool>& fits, int V)
{
	for (auto i = 0; i < vec.size(); ++i)
	{
		fits[vec[i] - 1] = true;
	}

	for (auto i = 0; i < vec.size(); ++i)
	{
		for (auto j = i + 1; j < vec.size(); ++j)
		{
			int sum = vec[i] + vec[j];
			if (sum <= V)
			{
				fits[sum - 1] = true;
			}
		}
	}

	for (auto i = 0; i < vec.size(); ++i)
	{
		for (auto j = i + 1; j < vec.size(); ++j)
		{
			for (auto k = j + 1; k < vec.size(); ++k)
			{
				int sum = vec[i] + vec[j] + vec[k];
				if (sum <= V)
				{
					fits[sum - 1] = true;
				}
			}
		}
	}

	for (auto i = 0; i < vec.size(); ++i)
	{
		for (auto j = i + 1; j < vec.size(); ++j)
		{
			for (auto k = j + 1; k < vec.size(); ++k)
			{
				for (auto l = k + 1; l < vec.size(); ++l)
				{
					int sum = vec[i] + vec[j] + vec[k] + vec[l];
					if (sum <= V)
					{
						fits[sum - 1] = true;
					}
				}
			}
		}
	}

	for (auto i = 0; i < vec.size(); ++i)
	{
		for (auto j = i + 1; j < vec.size(); ++j)
		{
			for (auto k = j + 1; k < vec.size(); ++k)
			{
				for (auto l = k + 1; l < vec.size(); ++l)
				{
					for (auto m = l + 1; m < vec.size(); ++m)
					{
						int sum = vec[i] + vec[j] + vec[k] + vec[l] + vec[m];
						if (sum <= V)
						{
							fits[sum - 1] = true;
						}
					}
				}
			}
		}
	}
}

int getMinResult(vector<int>& results)
{
	int result = 99999;
	for (auto i = 0; i < results.size(); ++i)
	{
		if (results[i] < result)
		{
			result = results[i];
		}
	}
	if (result == 99999)
	{
		result = 0;
	}
	return result;
}

int MIN_RESULT = 99999;

void tryToAdd(vector<int> vec, vector<bool> fits, int value, int V, int result, vector<int>& results)
{
	result++;
	if (result < MIN_RESULT)
	{
		vec.push_back(value);
		checkFits(vec, fits, V);
		if ((getNumOfFails(fits) > 0))
		{
			for (auto i = 0; i < fits.size(); ++i)
			{
				if (!fits[i])
				{
					tryToAdd(vec, fits, i + 1, V, result, results);
				}
			}
		}
		else
		{
			results.push_back(result);
			MIN_RESULT = getMinResult(results);
		}
	}
}

int main()
{
	ifstream src("Output.txt");
	string currentDate = currentDateTime();
	replace(currentDate.begin(), currentDate.end(), ':', '.');
	ofstream dst((string("Output") + currentDate + string(".txt")).c_str());
	dst << src.rdbuf();
	src.close();
	dst.close();

	ifstream in("Input.txt");
	ofstream out("Output.txt");

	int T;
	in >> T;

	for (auto t = 0; t < T; ++t)
	{
		MIN_RESULT = 99999;
		int C, D, V;
		in >> C >> D >> V;
		vector<int> vec;
		for (auto i = 0; i < D; ++i)
		{
			int tmp;
			in >> tmp;
			vec.push_back(tmp);
		}

		vector<bool> fits(V);
		checkFits(vec, fits, V);
		vector<bool> orig = fits;
		int fails = getNumOfFails(fits);

		vector<int> results;
		int extraResult = 0;
		if (getNumOfFails(fits) > 0 && fits[0] == false)
		{
			vec.push_back(1);
			checkFits(vec, fits, V);
			extraResult++;
		}
		if (getNumOfFails(fits) > 0 && fits[1] == false)
		{
			vec.push_back(2);
			checkFits(vec, fits, V);
			extraResult++;
		}

		if ((getNumOfFails(fits) > 0))
		{
			for (auto i = 0; i < fits.size(); ++i)
			{
				if (!fits[i])
				{
					tryToAdd(vec, fits, i + 1, V, 0, results);
				}
			}
		}

		int result = getMinResult(results);
		result += extraResult;

		out << "Case #" << (t + 1) << ": " << result << endl;
		cout << "Done " << (t + 1) << " out of " << T << endl;
	}

	return 0;
}