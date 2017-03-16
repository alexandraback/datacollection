#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("b.in", "r", stdin); 
	freopen("b.out", "w", stdout);
	int test;
	cin >> test;
	for (int noTest = 1; noTest <= test; noTest++)
	{
		double C, F, X;
		cin >> C >> F >> X;
		
		double ans = 1e18, currentTime = 0, rate = 2;
		for (int farm = 0; farm <= 100010; farm++)
		{
			double neededTime = currentTime + X / rate;
			ans = min(ans, neededTime);
			currentTime += C / rate;
			rate += F;
		}
		
		printf("Case #%d: %.9lf\n", noTest, ans);
	}
}
