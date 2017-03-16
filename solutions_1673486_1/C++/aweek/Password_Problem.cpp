#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;


class CaseInfo
{
public:
	int typed_count;
	int password_count;
	vector<double> correct_probability;
	double expected_type;

	friend istream & operator>>(istream & is, CaseInfo & info)
	{
		is >> info.typed_count >> info.password_count;
		info.correct_probability.clear();
		string line;
		getline(is, line);
		getline(is, line);
		copy(istream_iterator<double>(stringstream(line)), istream_iterator<double>(), back_inserter(info.correct_probability));
		return is;
	}

	friend ostream & operator<<(ostream & os, const CaseInfo & info)
	{
		os.precision(6);
		os.setf(ios::fixed,ios::floatfield);
		return os << info.expected_type;
	}

	void ProcessCase()
	{
		vector<double> option_expected;
		option_expected.push_back(typed_count + password_count + 1);

		double all_right_probability = 1;
		for (size_t i=0; i<typed_count; i++)
		{
			all_right_probability *= correct_probability[i];
			option_expected.push_back(all_right_probability * (typed_count - i - 1 + password_count - i)
				+ (1 - all_right_probability) * (typed_count - i - 1 + password_count - i + password_count + 1));
		}

		option_expected.push_back(1 + password_count + 1);

		expected_type = *min_element(option_expected.begin(), option_expected.end());
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
