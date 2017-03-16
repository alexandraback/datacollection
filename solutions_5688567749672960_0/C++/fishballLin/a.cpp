#include <bits/stdc++.h>
using namespace std;
#define MAX 1048576
int a[MAX];
int rev(int n)
{
	int sum = 0;
	while(n)
	{
		sum = sum * 10 + n % 10;
		n /= 10;
	}
	return sum;
}
int main()
{
	fill(a, a + MAX, 1029384756);
	for(int i = 1; i < 10; i++)
		a[i] = i;
	for(int i = 10; i < MAX; i++)
	{
		a[i] = a[i - 1] + 1;
		int re = rev(i);
		if(i % 10 && re < i)
			a[i] = min(a[i], a[re] + 1);
		//cout << i << ' ' << a[i] << endl;
	}
	int t, cnt = 1;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		cout << "Case #" << cnt++ << ": " << a[n] << endl;
	}
	return 0;
}