/*
user  : triveni
date  : 03/05/2014
time  : 22:20:48
*/
#include <bits/stdc++.h>

using namespace std;

#define      pii               std::pair<int,int>
#define      mp(a,b)           std::make_pair(a,b)
#define      X                 first
#define      Y                 second

typedef long long ll;
ll MOD = 1000000007;

void solve()
{
	int A, B, C;
	cin>>A>>B>>C;
	int ct = 0;
	for(int i=0;i<A;++i)
		for(int j=0;j<B;++j)
		{
			if((i&j)<C) ct++;
		}
	cout << ct << endl;
}
int main()
{
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;++i)
	{
		printf("Case #%d: ",i);
		solve();
	}
	return 0;
}