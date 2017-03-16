#include <iostream>
#include <iomanip>
using namespace std;

int main ()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tc;		cin >> tc;	//scanf("%d", &tc);
	for (int T = 1; T <= tc; T++)
	{
		int a[1000], n, sum = 0;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		sum += a[i];}
		double avr = 2.0 * sum / n;
		int s = 0, num = 0;
		for (int i = 0; i <n; i++)
			if (a[i] <= avr)
			
			{
				num ++;
				s += a[i];
			}
		//printf("Case #%d:", T);
		cout <<"Case #" << T << ":";
		for (int i = 0; i < n; i++)
		
		{
			if (a[i] > avr)	cout << " " << 0;
			else
			{
				double ans = (double(s) + sum - num * a[i]) / (num * sum) * 100;
				if (ans < 0)	ans = 0;
				//printf(" %.8lf", ans);
				cout << " " << fixed << setprecision(6) << ans;
			}
		}
		cout << endl;

	}
}