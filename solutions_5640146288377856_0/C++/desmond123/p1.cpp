#include<bits/stdc++.h>

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


inline void solve()
{
	int r,c,w;
	cin >> r >> c >> w;
	int ans = (r)*c/w + w-1;
	if(c%w != 0)
		ans++;
	cout << ans << endl;
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