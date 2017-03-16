#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int t; cin >> t;
	for (int i=1; i<=t; ++i)
	{	
		int n, x;
		cin >> n;
		vector < int > v(2501, 0);
		vector < int > num;

		for (int j=1; j<=((n*2)-1)*n; ++j)
		{

			cin >> x;
			v[x]++;
		}
		for (int j=1; j<=2501; ++j)
		{
			if (v[j] % 2)
				num.push_back(j);
		}

		sort(num.begin(), num.end());

		cout << "Case #" << i << ": ";
		
		for (int j=0; j<num.size(); ++j)
			cout << num[j] << " ";

		cout << endl;
	}
	return 0;
}