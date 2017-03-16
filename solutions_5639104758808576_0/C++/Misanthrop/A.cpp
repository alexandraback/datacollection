#include <iostream>
#include <string>
using namespace std;

int main()
{
	int t; cin >> t;
	string s;
	for(int i = 1; i <= t; ++i)
	{
		int n, stand = 0, need = 0;
		cin >> n >> s;
		for(int j = 0; j <= n; ++j)
		{
			int miss = max(0, j - stand);
			need += miss;
			stand += miss + s[j] - '0';
		}
		cout << "Case #" << i << ": " << need << endl;
	}
}
