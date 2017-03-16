#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;


class CaseInfo
{
public:
	int n;
	vector<int> s;
	vector<double> m;

	friend istream & operator>>(istream & is, CaseInfo & info)
	{
		is >> info.n;

		string line;
		getline(is, line);
		info.s.clear();
		copy(istream_iterator<int>(stringstream(line)), istream_iterator<int>(), back_inserter(info.s));

		return is;
	}

	friend ostream & operator<<(ostream & os, const CaseInfo & info)
	{
		os.precision(6);
		os.setf(ios::fixed, ios::floatfield);
		copy(info.m.begin(), info.m.end(), ostream_iterator<double>(os, " "));
		return os;
	}

	void ProcessCase()
	{
		m.clear();
		m.resize(n);
		int sums = accumulate(s.begin(), s.end(), 0);
		int mins = *min_element(s.begin(), s.end());


		for (size_t i=0; i<n; i++)
			m[i] = (2.0 / n - 1.0 * s[i] / sums) * 100;

		bool needrecal = false;
		int newn = n;
		int total = sums;
		for (size_t i=0; i<n; i++)
		{
			if (m[i] < 0.0000001)
			{
				m[i] = 0;
				newn--;
				needrecal = true;
			}
			else
				total += s[i];
		}

		if (!needrecal)
			return;

		for (size_t i=0; i<n; i++)
		{
			if (m[i] > 0)
				m[i] = (1.0 * total / newn - 1.0 * s[i]) / sums * 100;
		}

		needrecal = false;
		total = sums;
		for (size_t i=0; i<n; i++)
		{
			if (m[i] < 0.0000001)
			{
				m[i] = 0;
				newn--;
				needrecal = true;
			}
			else
				total += s[i];
		}

		if (!needrecal)
			return;

		for (size_t i=0; i<n; i++)
		{
			if (m[i] > 0)
				m[i] = (1.0 * total / newn - 1.0 * s[i]) / sums * 100;
		}
	}
};


int main()
{
	ifstream ifs("A-large.in");
	ofstream ofs("A-large.out");

	string line;
	getline(ifs, line);

	int number = 1;
	CaseInfo case_info;
	while (ifs >> case_info)
	{
		case_info.ProcessCase();

		ofs << "Case #" << number++ << ": " << case_info << "\n";
	}

	return 0;
}
