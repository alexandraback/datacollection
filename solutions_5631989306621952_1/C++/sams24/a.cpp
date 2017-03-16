#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int t;

	cin >> t;

	fstream fout;
	fout.open("a_output.out", ios::out);

	string s, ans, copy;

	for(int i=1; i<=t; i++)
	{
		cin >> s;
		copy = s;

		sort(copy.begin(), copy.end());	
		reverse(copy.begin(), copy.end());

		char last = copy[0];

		ans = s.substr(0, 1); 
		s.erase(0, 1);

		char temp;
		string first;
		for(unsigned j=0; j<s.size(); j++)
		{
			temp = s[j];
			if(temp == last)
			{
				first = string(1, temp);
				ans.insert(0, first);
			}	   
			else if(temp >= ans[0])
			{
				first = string(1, temp);
				ans.insert(0, first);
			}
			else
			{
				ans.push_back(temp);
			}
		}

		fout << "Case #" << i << ": " << ans << endl;
	}
	return 0;
}
