#include "bits/stdc++.h"
using namespace std;

#define pb push_back
typedef long long ll;
void solve(int test)
{
	int n;
	ll t;
	cin >> n >> t;
	cout << "Case #" << test << ": ";
	if (t > (1ll << (n-2))) 
	{
	    cout << "IMPOSSIBLE" << "\n";
	}
	else
	{
		cout << "POSSIBLE\n";
		if (t == (1ll<<(n-2)))
		{
			cout << 0;
			for (int i = 1; i < n; i++) cout << 1;
			cout << endl;
		}
		else
		{
			cout << 0;
			for (int i = 0; i < n-2; i++)
			   cout << ((t>>(n-3-i))&1ll);
			cout << 0;
			cout << endl;
		}
		for (int i = 0; i < n-2; i++) 
		{
		   for (int j = 0; j < n; j++)
		      cout << ((i+1) < j);
		   cout << endl;
		}
		for (int i = 0; i < n; i++) cout << 0;
		cout << endl;
	}
	
}

int main() {
	// your code goes here
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) solve(i+1);
	return 0;
}