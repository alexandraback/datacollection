#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int ncase;
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
	cin >> ncase;

	for(int icase = 0;icase < ncase;icase++)
	{
		int r, c, w;
		cin >> r >> c >> w;
		int res = (c / w) * r + w - 1;
		
		if (c % w != 0)
			cout << "Case #" << icase + 1 << ": " << res + 1 << endl;
		else
			cout << "Case #" << icase + 1 << ": " << res << endl;
	}

	return 0;
}
