#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int T = 100000;
	cin >> T;
	for(int t = 1; t <= T; ++t)
	{
		int N;
		cin >> N;
		if(N == 0)
			cout << "Case #" << t << ": INSOMNIA\n";
		else
		{
			bool seen [10] = {};
			for(int i = 1; ; ++i)
			{
				string str = to_string(N * i);
				for(char c : str)
					seen[c - '0'] = true;
				if(all_of(seen, seen + 10, [](bool b){ return b; }))
				{
					cout << "Case #" << t << ": " << N*i << endl;
					break;
				}
			}
		}
	}
}
