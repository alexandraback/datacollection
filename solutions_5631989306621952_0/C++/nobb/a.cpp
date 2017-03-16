#include <fstream>
#include <string>

#define SIZE 1000

using namespace std;
int main()
{
	ifstream infile("A-small-attempt0.in");
	ofstream outfile("A-output");

	int t;
	infile >> t;
	string c;
	getline(infile, c);
	for (int ca = 1; ca <= t; ++ca)
	{
		string s = "";
		string ans = "";
		getline(infile, s);
		for (int i = 0; i < s.length(); ++i)
		{
			if (ans.length() == 0) ans = ans + s[i];
			else 
			{
				if (s[i] >= ans[0])
					ans = s[i] + ans;
				else ans = ans + s[i];
			}
		}
		outfile << "Case #" << ca << ": " << ans << endl;
	}

	return 0;
}