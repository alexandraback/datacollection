#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

long long gcd(long long P, long long Q)
{
	long long min1 = min(P,Q);
	long long max1 = max(P,Q);
	while(min1!=0)
	{
		long long r = max1%min1;
		max1 = min1;
		min1 = r;
	}
	return max1;
}
int main()
{
	int t;
	cin >> t;
	char ch;
	long long P,Q;
	for(int i=0;i<t;i++)
	{
		cout << "Case #" << i+1 << ": ";
		cin >> P >> ch >> Q;
		long long r = gcd(P,Q);
		P = P/r;
		Q = Q/r;
		long long T = Q;
		int cnt = 0;
		while(T!=1 && T%2 == 0)
		{
			T=T/2;
			cnt++;
		}
		if(T!=1)
		{
			cout << "impossible" << endl;
			continue;
		}
		while(cnt<=40)
		{
			P = P*2;
			cnt++;
		}
		int ans = 0;
		while(P!=1)
		{
			P = P/2;
			ans++;
		}
		cout << 41-ans << endl;
	}
	return 0;
}
