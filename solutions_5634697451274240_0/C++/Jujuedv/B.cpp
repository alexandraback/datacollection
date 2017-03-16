#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int T; 
	cin >> T;
	string str;
	getline(cin, str);
	for(int t = 1; t <= T; ++t)
	{
		getline(cin, str);
		int cuts = 0;
		for(int i = 0; i < str.size()-1; ++i)
			if(str[i] != str[i+1])
				cuts ++;
		if(str.back() == '-')
			cuts ++;

		cout << "Case #" << t << ": " << cuts << endl;
	}
}
