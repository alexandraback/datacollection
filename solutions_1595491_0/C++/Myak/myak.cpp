#include <iostream>

using namespace std;

int main()
{
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	int t;
	cin >> t;
	int n, s, p, t1, t2;
	int col, temp, teks;
	for (int i=0; i<t; i++)
	{
		cin >> n >> s >> p;
		col=0, teks=0;
		for (int j=0; j<n; j++)
		{
			cin >> temp;
			t1=max(3*p-2, p);
			t2=max(3*p-4, p);
			if (temp>=t1)
				col++;
			else if (teks<s && temp>=t2)
			{
				col++;
				teks++;
			}
		}
		cout << "Case #" << i+1 << ": " << col << "\n";
	}
	return 0;
}