#include <bits/stdc++.h>
using namespace std;

int l[2600];
int main()
{
	//ifstream cin("in.txt");
	//ofstream cout("out.txt");
	int t,n;
	cin >> t;
	for (int a0 = 1; a0<=t; a0++)
	{
		cin >> n;
		for (int i=1; i<=2600;i++)
			l[i] = 0;	

		int x;
		for (int i = 0;i < 2*n - 1; i++)
			for (int j = 0; j < n; j++)
			{	
				cin >> x;
				l[x]++;
			}

		cout << "Case #" << a0 << ": ";		
		for (int i = 1; i<=2600; i++)
			if (l[i]&1)
				cout << i << " ";
		cout << endl;
	}

	return 0;
}
