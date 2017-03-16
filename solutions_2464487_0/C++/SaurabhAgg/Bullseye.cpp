#include<iostream>
#include<cmath>
using namespace std;


long long r, t;

double value(long long k)
{
	return (2*k*k + k*(2*r - 1));
}

long long binary_search(long long low, long long high)
{
	long long ans = low;
	long long mid;
	while(low < high)
	{
		mid = low + (high - low) / 2;
		//cout << low << " " << mid << " " << high << endl;
		long long val = value(mid);
		//cout << val << " vs " << t << endl;
		if(val <= t)
		{
			ans = mid;
			low = mid + 1;
		}
		else
		{
			high = mid;
		}
		//cout << "low = " << low << endl;
		//cout << "high = " << high << endl;
	}
	
	return ans;
}

int main()
{
	int cases;
	cin >> cases;
	for(int t1 = 1; t1 <= cases; t1++)
	{
		cin >> r >> t;
		long long high = (long long)sqrt(t/2);
		high++;
		long long ans = binary_search(0, high);
		cout << "Case #" << t1 << ": " << ans << endl;
	}
	
	return 0;
}
