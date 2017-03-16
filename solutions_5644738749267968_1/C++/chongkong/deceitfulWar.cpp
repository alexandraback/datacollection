#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int CaseNum;
	cin >> CaseNum;
	for (int Case = 1; Case <= CaseNum; Case++)
	{
		cout << "Case #" << Case << ": ";

		int n;
		cin >> n;

		vector <double> Naomi(n, 0);
		vector <double> Ken(n, 0);

		for (int i = 0; i < n; i++)
			cin >> Naomi[i];
		for (int i = 0; i < n; i++)
			cin >> Ken[i];

		sort(Naomi.begin(), Naomi.end());
		sort(Ken.begin(), Ken.end());

		int a = 0, b = n - 1, c = 0, d = n - 1;
		int war = 0, dwar = 0;

		for (int i = 0; i < n; i++) {
			if (Naomi[b] > Ken[d])
				b--, war++;
			else 
				b--, d--;
		}

		b = d = n - 1;
		for (int i = 0; i < n; i++) {
			if (Naomi[a] > Ken[c])
				a++, c++, dwar++;
			else
				a++;

		}

		cout << dwar << " " << war << endl;
	}
}