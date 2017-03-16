#include <iostream>
using namespace std;

int main()
{
	int t,n,surprising,limit;
	cin >> t;
	for(int x = 0; x < t; ++x)
	{
		cin >> n >> surprising >> limit;
		int total,count,average,mod;
		count = 0;
		for (int i = 0; i < n; ++i)
		{
			cin >> total;
			average = total/3;
			mod = total%3;
			if ((average >= limit) || ((average == (limit - 1)) && (mod != 0)) )
			{
				count ++;
				continue;
			}
			if(surprising == 0 || limit > total)
				continue;
			if(average == (limit - 1))
			{
				surprising --;
				count ++;
			}
			else
			{
				total -= limit;
				if (total < 0)
					continue;
				average = total / 2;
				mod = total % 2;
				if ((limit - average) > 2)
					continue;
				count ++;
				surprising --;

			}


		}
		cout << "Case #" << x + 1 << ": " << count << endl;

	}
	return 0;
}
