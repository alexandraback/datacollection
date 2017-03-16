#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <set>

using namespace std;


class CaseInfo
{
public:
	int n;
	vector<vector<int>> m;
	bool result;

	friend istream & operator>>(istream & is, CaseInfo & info)
	{
		is >> info.n;

		string line;
		getline(is, line);
		info.m.clear();
		info.m.resize(info.n);
		for (size_t i=0; i<info.n; i++)
		{
			int t;
			is >> t;
			getline(is, line);
			copy(istream_iterator<int>(stringstream(line)), istream_iterator<int>(), back_inserter(info.m[i]));
		}

		return is;
	}

	friend ostream & operator<<(ostream & os, const CaseInfo & info)
	{
		string s = info.result ? "Yes": "No";
		return os << s;
	}

	void ProcessCase()
	{
		result = false;

		vector<set<int>> p(n);

		set<int> r;
		for (size_t i=0; i<n; i++)
			r.insert(i);

		while (!r.empty())
		{
			int current = *r.begin();

			r.erase(r.begin());

			for (size_t i =0; i<m[current].size(); i++)
			{
				p[m[current][i] - 1].insert(current);

				for (set<int>::iterator it=p[current].begin(); it!=p[current].end(); ++it)
					p[m[current][i] - 1].insert(*it);

				r.insert(m[current][i] - 1);
			}
		}

		vector<int> pc(n);
		for (size_t i=0; i<n; i++)
		{
			for (size_t j=0; j<m[i].size(); j++)
			{
				pc[m[i][j] - 1] += p[i].size() + 1;
			}
		}

		for (size_t i=0; i<n; i++)
		{
			if (pc[i] != p[i].size())
			{
				result = true;
				return;
			}
		}
	}
};


int main()
{
	ifstream ifs("A-small-attempt2.in");
	ofstream ofs("A-small-attempt2.out");

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
