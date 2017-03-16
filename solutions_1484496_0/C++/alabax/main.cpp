#include <fstream>
#include <string>
#include <map>
#include <vector>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int N;
int s[20];

map<int, vector<int> > ans;

void solve()
{
	for (int i=1; i <= 1<<19;++i)
	{
		int q = 0;
		vector<int> vars;
		for (int j=0, v=i; j<20; ++j)
		{
			if ((v&1) == 1)
			{
				q+=s[j];
				vars.push_back(s[j]);
			}
			v = v>>1;
		}
		if (q!=0)
		{
			map<int, vector<int> >::iterator it = ans.find(q);
			if (it != ans.end())
			{
				fout << endl;
				vector<int> ans2 = it->second;
				for (vector<int>::iterator it2 = ans2.begin(); it2!=ans2.end(); ++it2)
				{
					if (it2 != ans2.begin()) fout << ' ';
					fout << *it2 ;
				}
				fout << endl;
				for (vector<int>::iterator it2 = vars.begin(); it2!=vars.end(); ++it2)
				{
					if (it2 != vars.begin()) fout << ' ';
					fout << *it2 ;
				}
				return;
			}
			ans[q] = vars;
		}
	}
	fout << endl;
	fout << "Impossible";
}

int main()
{
	int T;
	fin >> T;
	for (int i=0;i<T;++i)
	{
		fin >> N;
		ans.clear();
		for (int j=0;j<N;++j)
		{
			fin >> s[j];
		}
		fout << "Case #" << i+1 << ": ";
		solve();
		fout << endl;
	}
	return 0;
}