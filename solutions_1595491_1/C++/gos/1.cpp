#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;
int T, Tidx = 1, N, P, S, arr[105];
int main()
{
	//freopen("e:\\B-large.in","r",stdin);
	//freopen("e:\\B-large.out","w",stdout);
	cin >> T;
	while(T--)
	{
		cin >> N >> S >> P;
		for(int i = 0; i < N; i++)
			cin >> arr[i];
		sort(arr, arr + N);
		int a, b, ans = 0;
		for(int i = N - 1; i >= 0; i--)
		{
			a = arr[i] / 3;
			b = arr[i] % 3;
			if(b > 0)
				a++;
			if(a >= P)
				ans++;
			else if(b != 1 && S > 0 && arr[i] > 1)
			{
				a++;
				S--;
				if(a >= P)
					ans++;
				else
					break;
			}
			else
				break;
		}
		cout << "Case #" << Tidx++ << ": " << ans << endl;
	}
	return 0;
}