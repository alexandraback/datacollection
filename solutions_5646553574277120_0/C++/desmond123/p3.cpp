#include <bits/stdc++.h>

using namespace std;

#define LL long long int
#define ULL unsigned long long
#define sd(x) scanf("%d", &x)
#define MP make_pair
#define PB push_back
#define vi vector<int> 
#define pii pair<int,int> 
#define F first
#define S second
#define D double
#define LD long double

bool valid(vector<int> &coins, int v)
{
	vector<bool> feasible(v+1, false);
	for(int i = 0; i < (1<<coins.size()); i++)
	{
		int s = 0;
		for(int j = 0; j < coins.size(); j++)
		{
			if(i & (1<<j))
				s += coins[j];
		}
		if(s <= v)
			feasible[s] = true;
	}
	bool flag = true;
	for(int i = 1; i <= v; i++)
		if(feasible[i] == false)
			return false;
	return true;
}

inline void solve()
{
	int c,d,v;
	cin >> c >> d >> v;
	vector<int> coins;
	vector<bool> denoms(13, true);
	for(int i = 0;i < d; i++)
	{
		int a;
		cin >> a ;
		coins.push_back(a);
		denoms[a] = false;
	}
	vector<int> possibleDenoms;
	for(int i = 1; i < denoms.size(); i++)
		if(denoms[i] && i <= v)
			possibleDenoms.push_back(i);
	possibleDenoms.push_back(16);

	int m = v;
	for(int i = 0; i < (1<<possibleDenoms.size()); i++)
	{
		vector<int> temp = coins;
		int c = 0;
		for(int j=0;j<possibleDenoms.size();j++)
		{
			if(i & (1<<j))
			{
				c++;
				temp.push_back(possibleDenoms[j]);
			}
		}
		// for(int i=0;i<temp.size(); i++)
		// 	cout<<temp[i]<<" ";
		if(valid(temp,v))
		{
			m = min(m,c);
		}
		// cout<<endl<<valid(temp,v)<<" "<< m<<endl;
		// return;
	}
	cout << m<< endl;
}

int main()
{
	int t, i;
	sd(t);
	for(i = 1; i <= t; i++)
	{
		printf("Case #%d: ", i);
		solve();
	}
    return 0;
}