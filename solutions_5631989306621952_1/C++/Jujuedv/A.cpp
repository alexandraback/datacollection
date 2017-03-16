#include <string>
#include <iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t)
	{
		string S;
		cin >> S;
		string out = "";
		for(char c : S)
		{
			if(string(out.size(), c) < out)
				out += c;
			else 
				out = c + out;
		}

		cout << "Case #" << t << ": " << out << endl;
	}
}
