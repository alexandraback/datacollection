#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
int sum, N, T, Tidx = 1, arr[205], tmp, tn;
int main()
{
	freopen("e:\\A-large.in", "r", stdin);
	freopen("e:\\A-large.out", "w", stdout);
	cin >> T;
	while(T--)
	{
		cin >> N;
		sum = 0;
		for(int i = 0; i < N; i++)
		{
			cin >> arr[i];
			sum += arr[i];
		}
		tmp = sum;
		tn = N;
		for(int i = 0; i < N; i++)
		{
			if(sum * 2 / N < arr[i])
			{
				tmp -= arr[i];
				arr[i] = -1;
				tn--;
			}
		}
		cout << "Case #" << Tidx++ << ":";
		for(int i = 0; i < N; i++)
		{
			cout << " " << fixed << setprecision(6);
			if(arr[i] < 0)
				cout << 0.0;
			else
			{
				cout << 100.0 * (1.0 * (sum + tmp) / tn - arr[i]) / (1.0 * sum);
			}
		}
		cout << endl;
	}
	return 0;
}