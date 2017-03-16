#include<iostream>

using namespace std;

int D[10];
int cnt = 0;

void to_digits(int n)
{
	while(n)
	{
		int x = n % 10;
		if (!D[x])
		{
			D[x] = true;
			cnt++;
		}
		n /= 10;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	int tt;
	cin >> tt;
	for (int t = 1; t <= tt; t++)
	{
		int n;
		cin >> n;
		for (int j = 0; j < 10; j++) D[j] = false;
		cnt = 0;
		int ans = -1;
		for (int j = 1; j < 1000; j++)
		{
			to_digits(n * j);
			if (cnt == 10)
			{
				ans = n * j;
				break;
			}
		}
		cout << "Case #" << t << ": ";
		if (ans != -1) cout << ans << "\n";
		else cout << "INSOMNIA\n";
	}
	
	
	return 0;
}
