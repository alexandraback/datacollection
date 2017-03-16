#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<queue>
#include<utility>

using namespace std;

#define ii pair<int, int>
#define ll long long

int A, B, K;

ll solve()
{
	ll count = 0;
	for(int i = 0; i < A; i++)
	for(int j = 0; j < B; j++)
	{
		int C = (i&j);
		if(C < K)
		count++;
	}
	return count;
}

int main(void)
{
	freopen("B0.in", "r", stdin);
	freopen("B0.out", "w", stdout);
	
	int T, t = 1;
	
	cin>>T;
	while(T--)
	{
		cin>>A>>B>>K;
		cout<<"Case #"<<t++<<": ";
		cout<<solve()<<endl;
	}
	return 0;
}

