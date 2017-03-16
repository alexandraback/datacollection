#include <iostream>
#include <algorithm>
#define INF 1000009
#define N 105
#define uint long long int
using namespace std;
uint dp[N];
uint motes[N];
int main()
{
	ios_base::sync_with_stdio(0);
	int t;
	cin>>t;
	for (int y = 1; y <= t; y++)
	{
		cout<<"Case #"<<y<<": ";
		int a, n;
		cin>>a>>n;
		for (int i = 1; i <= n; i++)
		{
			cin>>motes[i];
		}
		sort(motes + 1, motes + 1 + n);
		int wyn = n;
		int aktwyn = n;
		int aktroz = a;
		if (a == 1)
		{
			cout<<n<<endl;
			continue;
		}
		for (int i = 1; i <= n; i++)
		{
			while (aktroz <= motes[i])
			{
				aktroz *= 2;
				aktroz--;
				aktwyn++;
			}
			aktroz += motes[i];
			aktwyn--;
			wyn = min(wyn, aktwyn);
		}
		cout<<wyn<<endl;
	}
	return 0;
}
		
	
	