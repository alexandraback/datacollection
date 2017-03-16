#include <iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;

	for(int i = 0; i < t; i++)
	{
		int n;
		cin >> n;
//		cout << n << " ";

		int *points = new int[n];
		int sum = 0;
		for(int j = 0; j < n; j++)
		{
			cin >> points[j];
//			cout << points[j] << " ";
			sum += points[j];
		}
//		cout << endl;

		cout << "Case #" << i+1 << ":";
		cout.precision(6);
		cout.setf(ios::fixed,ios::floatfield);

//		double persum = 0;
		int count = 0;	
		int newsum = 0;
		for(int j = 0; j < n; j++)
		{	
			if(double(points[j]) < 2 * double(sum) / double(n))
			{
				count++;
				newsum += points[j];
			}
		}

		double minreq = double(sum + newsum) / double(count);
		for(int j = 0; j < n; j++)
		{
		
			double remaining = 0;
			if(double(points[j]) < 2 * double(sum) / double(n))
			{
				if( newsum == 0 )
				{
					remaining = double(100) / double(count);
				}
				else
				{
					remaining = 100 * (minreq - points[j]) / sum;
				}
			}
			cout << " " << remaining;
//			persum += remaining;
		}
		cout << endl;
//		cout << persum << endl;
	}

	return 0;
}
