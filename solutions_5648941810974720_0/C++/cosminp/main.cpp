#include <fstream>
#include <string>
#include <vector>
using namespace std;

string solve(string &s)
{
	vector<int> cnt(256, 0);
	vector<int> d(10, 0);
	string 		w[] 	= {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
	int 		order[] = {0,    2,   4,   6,   8,   3,   1,   5,   7,   9};
	char 		key[]   = {'Z', 'W', 'U', 'X', 'G', 'R', 'O', 'F', 'V', 'I'};
	string 		ans;

	for (char c : s) cnt[c]++;

	for (int i = 0; i <= 9; i++)
	{
		int x 		 = cnt[key[i]];
		d[order[i]] += x;
		for (char c : w[order[i]]) cnt[c] -= x;
	}

	for (int i = 0; i < d.size(); i++)
		if (d[i]) ans += string(d[i], i + '0');

	return ans;
}

int main()
{
	ifstream 	f("in.txt");
	ofstream 	g("out.txt");
	int 		T;
	string 		s;

	f >> T;
	for (int test = 1; test <= T; test++)
	{
		f >> s;
		g << "Case #" << test << ": " << solve(s) << endl;
	}

	return 0;
}
