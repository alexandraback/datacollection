#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <map>

using namespace std;

stringstream out;

void function()
{
	int j, p, s, k;
	cin >> j >> p >> s >> k;
	map<string, int> m;
	string f = "";
	stringstream o;
	int c = 0;
	for (int i = 0; i < j; i++)
	{
		for (int ii = 0; ii < p; ii++)
		{
			for (int iii = 0; iii < s; iii++)
			{
				string comb1 = to_string(i) + to_string(ii) + "A";
				string comb2 = to_string(i) + "A" + to_string(iii);
				string comb3 = "A" + to_string(ii) + to_string(iii);
				if (m[comb1] < k && m[comb2] < k && m[comb3] < k) {
					m[comb1]++;
					m[comb2]++;
					m[comb3]++;
					c++;
					o << i + 1 << " " << ii + 1 << " " << iii + 1 << endl;
				}
			}
		}
	}
	out << c << endl << o.str();

}

int main()
{
	ios_base::sync_with_stdio(0);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		out << "Case #" << i << ": ";
		function();
	}
	
	cout << out.str() << endl;
	return 0;
}