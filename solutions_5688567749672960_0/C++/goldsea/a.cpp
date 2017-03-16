#include <bits/stdc++.h>
using namespace std;

int test, t;
long long n;
long long powr[16];
long long l[16];
int a[16];

int main()
{
	//freopen("in.txt", "r", stdin);
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> test;
	powr[0] = 1;
	for(int i = 1; i < 16; i++) powr[i] = 10*powr[i-1];
	l[0] = 0;
	for(int i = 1; i < 16; i++) l[i] = powr[i/2] + powr[i - i/2] - 1;
	for(int i = 1; i < 16; i++) l[i] += l[i - 1];
	//l[1] = 9;
	for(int t = 1; t <= test; t++)
	{
		cin >> n;
		
		int hold = 0;
		if(n % 10 == 0) 
		{
			hold = 1;
			n--;
		}
		long long s = n;
		int m = 0;
		//cout << s;
		while(n >= powr[m])
		{
			a[m] = s % 10;
			s /= 10;
			m++;
		}
		//cout << m;
		long long rs = 0;
		rs = l[m - 1];
		long long ab = 0;
		long long cd = 0;
		for(int i = (m + 1)/2; i < m; i++)
			ab = ab*10 + a[i];
		for(int i = (m + 1)/2 - 1; i >= 0; i--)
			cd = cd*10 + a[i];
		if(ab == 1) rs--;
		//cout << ab <<  " " << cd << " " << rs;
		rs = rs + ab + cd + hold;
		cout << "Case #" << t << ": " << rs << "\n";
	}
	return 0;
}