
#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t){
		string cakes;
		cin >> cakes;
		cakes += "+";

		int count = 0;
		char last = cakes[0];
		for (char c: cakes)
			if (last != c){
				++count;
				last = c;
			}

		cout << "Case #" << t + 1 << ": " << count << endl;
	}
	return 0;
}
