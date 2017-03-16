#include <iostream>
#include <iomanip>

using namespace std;

int pewniaki[100000];

double Newton( unsigned int n, unsigned int k)
{
	double Wynik = 1;       
 
	for (unsigned int i = 1; i <= k; i++) 
	{
		Wynik = Wynik * ( n - i + 1 ) / i;      
	}
 
	return Wynik;  
}

int main()
{
	ios_base::sync_with_stdio(0);
	int t;
	cin >> t;

	int n, x, y;
	int pop1, pop2, start, end, mid, k;
	pop1 = 2, pop2 = 3;
	pewniaki[0] = 1;
	for (int i = 1; ; i++)
	{
		pewniaki[i] = pewniaki[i-1] + pop1 + pop2;
		pop1+= 2;
		pop2 += 2;
		if (pewniaki[i] > 1000000)
		{
			k = i;
			break;
		}
	}
	for (int i = 1; i <= t; i++)
	{
		cin >> n >> x >> y;
		start = 0;
		end = k;
		cout << "Case #" << i << ": ";  
		while (true)
		{
			mid = (start + end) / 2;
			if (pewniaki[mid] > n)
			{
				end = mid;
			}
			else
			{
				if (start == mid) break;
				start = mid;
			}
		}
		if ((x + y) % 2 == 1)
		{
			cout << 0 << endl;
			continue;
		}
		if (x > -(2 * mid + 1) && x < 2 * mid + 1 && y >= 0 && y < 2 * mid + 1 - abs(x))
		{
			cout << 1 << endl;
			continue;
		}
		mid++;
		if (!(x > -(2 * mid + 1) && x < 2 * mid + 1 && y >= 0 && y < 2 * mid + 1 - abs(x)))
		{
			cout << 0 << endl;
			continue;
		}
		if (x == 0)
		{
			cout << 0 << endl;
			continue;
		}
		int newt;
		if (x > 0)
		{
			newt = 2 * mid - x + 1;
		}
		else
		{
			newt = 2 * mid + x + 1;
		}
		double wynik = 0;
		int rest = n - pewniaki[mid-1];
		if ((((pewniaki[mid] - pewniaki[mid-1]) / 2) + newt) <= rest)
		{
			cout << 1 << endl;
			continue;
		}
		for (int j = newt; j <= rest; j++)
		{
			wynik += Newton(rest,j);
		}
		for (int j = 0; j < rest; j++)
			wynik /= 2.0;
		if (wynik == 0.0) cout << 0 << endl;
		else cout << wynik << endl;
	}

	return 0;
}