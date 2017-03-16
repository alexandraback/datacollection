#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <string>
#include <math.h>
using namespace std;

		
int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int t;
	cin>>t;
	for (int l = 0; l < t; ++l)
	{
		string s;
		cin>>s;
		vector<int> mas(27);
		for (int i = 0; i < s.length(); ++i)
		{
			++mas[s[i] - 'A'];
		}
		vector<int> digs(10);
		digs[0] = mas['Z' - 'A'];
		mas['E' - 'A'] -= mas['Z' - 'A'];
		mas['R' - 'A'] -= mas['Z' - 'A'];
		mas['O' - 'A'] -= mas['Z' - 'A'];
		mas['Z' - 'A'] = 0;
		digs[2] = mas['W' - 'A'];
		mas['T' - 'A'] -= mas['W' - 'A'];
		mas['O' - 'A'] -= mas['W' - 'A'];
		mas['W' - 'A'] = 0;
		digs[4] = mas['U' - 'A'];
		mas['F' - 'A'] -= mas['U' - 'A'];
		mas['O' - 'A'] -= mas['U' - 'A'];
		mas['R' - 'A'] -= mas['U' - 'A'];
		mas['U' - 'A'] = 0;
		digs[5] = mas['F' - 'A'];
		mas['I' - 'A'] -= mas['F' - 'A'];
		mas['V' - 'A'] -= mas['F' - 'A'];
		mas['E' - 'A'] -= mas['F' - 'A'];
		mas['F' - 'A'] = 0;
		digs[7] = mas['V' - 'A'];
		mas['E' - 'A'] -= mas['V' - 'A'] * 2;
		mas['S' - 'A'] -= mas['V' - 'A'];
		mas['N' - 'A'] -= mas['V' - 'A'];
		mas['V' - 'A'] = 0;
		digs[8] = mas['G' - 'A'];
		mas['E' - 'A'] -= mas['G' - 'A'];
		mas['I' - 'A'] -= mas['G' - 'A'];
		mas['H' - 'A'] -= mas['G' - 'A'];
		mas['T' - 'A'] -= mas['G' - 'A'];
		mas['G' - 'A'] = 0;
		digs[6] = mas['X' - 'A'];
		mas['S' - 'A'] -= mas['X' - 'A'];
		mas['I' - 'A'] -= mas['X' - 'A'];
		mas['X' - 'A'] = 0;
		digs[3] = mas['H' - 'A'];
		mas['T' - 'A'] -= mas['H' - 'A'];
		mas['R' - 'A'] -= mas['H' - 'A'];
		mas['E' - 'A'] -= 2 * mas['H' - 'A'];
		mas['H' - 'A'] = 0;
		digs[9] = mas['I' - 'A'];
		digs[1] = mas['O' - 'A'];
		cout<<"Case #"<<l+1<<": ";
		for (int i = 0; i < 10; ++i)
			for (int j = 0; j < digs[i]; ++j)
				cout<<i;
		cout<<endl;
	}
	return 0;
}