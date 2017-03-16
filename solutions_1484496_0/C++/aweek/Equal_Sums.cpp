#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <numeric>
#include <algorithm>

using namespace std;

class CaseInfo
{
public:
	int n;
	vector<int> s;
	vector<int> a1;
	vector<int> a2;

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
		if (info.a1.empty())
		{
			os << "Impossible";
			return os;
		}

		copy(info.a1.begin(), info.a1.end(), ostream_iterator<double>(os, " "));
		os << "\n";
		copy(info.a2.begin(), info.a2.end(), ostream_iterator<double>(os, " "));
		return os;
	}

	void ProcessCase()
	{
		sort(s.begin(), s.end());
		a1.clear();
		a2.clear();
		for (size_t i=0; i<n; i++)
			for (size_t j=i+1; j<n; j++)
			{
				for (size_t k=j+1; k<n; k++)
				{
					if (s[i] + s[j] == s[k])
					{
						a1.push_back(s[i]);
						a1.push_back(s[j]);
						a2.push_back(s[k]);
						return;
					}
				}

				for (size_t k=j+1; k<n; k++)
					for (size_t l=k+1; l<n; l++)
				{
					if (s[i] + s[j] == s[k] + s[l])
					{
						a1.push_back(s[i]);
						a1.push_back(s[j]);
						a2.push_back(s[k]);
						a2.push_back(s[l]);
						return;
					}
				}
			}


			for (size_t h=0; h<n; h++)
			for (size_t i=h+1; i<n; i++)
				for (size_t j=i+1; j<n; j++)
				{
					for (size_t k=j+1; k<n; k++)
					{
						if (s[h] + s[i] + s[j] == s[k])
						{
							a1.push_back(s[h]);
							a1.push_back(s[i]);
							a1.push_back(s[j]);
							a2.push_back(s[k]);
							return;
						}
					}

					for (size_t k=j+1; k<n; k++)
						for (size_t l=k+1; l<n; l++)
						{
							if (s[h] + s[i] + s[j] == s[k] + s[l])
							{
								a1.push_back(s[h]);
								a1.push_back(s[i]);
								a1.push_back(s[j]);
								a2.push_back(s[k]);
								a2.push_back(s[l]);
								return;
							}
						}

						for (size_t p=j+1; p<n; p++)

						for (size_t k=p+1; k<n; k++)
							for (size_t l=k+1; l<n; l++)
							{
								if (s[h] + s[i] + s[j] == s[k] + s[l] + s[p])
								{
									a1.push_back(s[h]);
									a1.push_back(s[i]);
									a1.push_back(s[j]);
									a2.push_back(s[k]);
									a2.push_back(s[l]);
									a2.push_back(s[p]);
									return;
								}
							}
				}




	}
};


int main()
{
	ifstream ifs("C-small-attempt1.in");
	ofstream ofs("C-small-attempt1.out");

	string line;
	getline(ifs, line);

	int number = 1;
	CaseInfo case_info;
	while (ifs >> case_info)
	{
		case_info.ProcessCase();

		ofs << "Case #" << number++ << ":\n" << case_info << "\n";
	}

	return 0;
}
