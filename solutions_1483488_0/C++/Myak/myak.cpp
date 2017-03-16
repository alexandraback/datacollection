#include <iostream>

using namespace std;
int ten[]={1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};

int main()
{
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	int t;
	cin >> t;
	int a, b, col;
	long long k;
	int t1, t2;
	long long temp, temp2, m;
	int razr;
	for (int i=1; i<=t; i++)
	{
		cin >> a >> b;
		col=0;
		for (int n=a; n<b; n++)
		{
			razr=0;
			while (n/ten[razr]!=0)
				razr++;
			t1=0, t2=0;
			for (int j=1; j<=razr; j++)
			{
				temp=n%ten[j];
				temp2=n/ten[j];
				m=temp*ten[razr-j]+temp2;
				if (m<=b && m>n && m!=t1 && m!=t2)
				{
					col++;
					if (t1==0)
						t1=m;
					else
						t2=m;
				}
			}
		}
		cout << "Case #" << i << ": " << col << "\n";
	}
	return 0;
}