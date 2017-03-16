#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("a.in");
ofstream fout("a.out");

int main()
{
	int T;
	fin >> T;
	for (int ca = 1; ca <= T; ca++)
	{
		fout << "Case #" << ca << ": ";
		string st;
		fin >> st;
		string ans = "";
		ans = ans + st[0];
		for (int i = 1; i < st.length(); i++)
		{
			if (st[i] >= ans[0]) ans = st[i] + ans; else ans = ans + st[i];
		}

		fout << ans << endl;
	}

}