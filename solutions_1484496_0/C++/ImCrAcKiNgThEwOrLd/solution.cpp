#include <iostream>
#include <vector>
#include <string>
using namespace std;
int a[20];
vector<int> vect(2000100);
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t = 0;
	cin >> t; getchar();
	for (int counter = 1; counter <= t; ++counter)
	{
		cout << "Case #" << counter << ":" << endl;
		int n, sum = 0;
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
		}
		bool yes = false;
		for (int i = 1; i < (1 << n); ++i)
		{
			int cur = 0;
			for (int j = 0; j < n; ++j)
				if ((i & (1 << j)) != 0)
					cur +=a[j];
			if (vect[cur] > 0)
			{
				int q = vect[cur];
				for (int j = 0; j < n; ++j)
					if ((q & (1 << j)) != 0)
						cout << a[j] << ' ';
				cout << endl;
				for (int j = 0; j < n; ++j)
					if ((i & (1 << j)) != 0)
						cout << a[j] <<' ' ;
				yes = true;
				break;
			}
			vect[cur] = i;
		}
		if (!yes)
			cout <<"Impossible";
		for (int i = 0; i < vect.size(); ++i)
			vect[i] = 0;
		cout << endl;
	}
}