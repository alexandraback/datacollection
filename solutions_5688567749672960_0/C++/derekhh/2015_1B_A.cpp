//A. Counter Culture

#include<iostream>
using namespace std;

int f[1000001];

int rev(int num)
{
	int ret = 0;
	while (num)
	{
		ret = ret * 10 + num % 10;
		num /= 10;
	}
	return ret;
}

void foo()
{
	memset(f, -1, sizeof(f));
	f[1] = 1;
	for (int i = 1; i < 1000000; i++)
	{
		if (f[i + 1] == -1 || f[i + 1] > f[i] + 1)
			f[i + 1] = f[i] + 1;
		
		int next = rev(i);
		if (f[next] == -1 || f[next] > f[i] + 1)
			f[next] = f[i] + 1;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	foo();
	int t, kase = 0;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		cout << "Case #" << ++kase << ": " << f[n] << endl;
	}
	return 0;
}