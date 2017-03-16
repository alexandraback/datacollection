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

int N, M, K;
int grid[1001][1001];

void init()
{
	grid[1][1] = 5;
	
	for(int p = 0; p <= 1000; p++)
	{
		grid[0][p] = p;
		grid[p][0] = p;
	}
	
	for(int p = 1; p <= 1000; p++)
	for(int q = 1; q <= 1000; q++)
	{
		if(q == 1)
		grid[p][q] = 3*p+2;
		else
		grid[p][q] = grid[p][q-1] + p + 2;
	}
}

int solve()
{
	int stones = min(2*N+2*M, K);
	
	for(int p = 1; p < M-1; p++)
	for(int q = 1; q < N-1; q++)
	{
		int size = p*q + 2*(p+q);
		if(size > K) stones = min(stones, 2*(p+q));
		else stones = min(stones, 2*(p+q) + K - size);
		
		int pt = p, qt = q, count = 2*(p+q);
		while((size >= K + 2) && pt > 1 && qt > 1)
		{
			count--;
			size -= 2;
			pt--;
			qt--;
			stones = min(stones, count);
		}
			
		//if(grid[i][j] > K)	stones = min(stones, 2*(i+j));
		//else stones = min(stones, 2*(i+j) + K - grid[i][j]);
	}
	return stones;
}

int main(void)
{
	freopen("C5.in", "r", stdin);
	freopen("C5.out", "w", stdout);
	
	int T, t = 1;
	init();
	char c;
	
	//for(int i = 0; i < 10; i++)
	{
	//	for(int j = 0; j < 10; j++)
	//	cout<<grid[i][j]<<" ";
	//	cout<<endl;
	}
	
	cin>>T;
	while(T--)
	{
		cin>>N>>M>>K;
		//cout<<N<<" "<<M<<" "<<K<<endl;
		cout<<"Case #"<<t++<<": ";
		//if(solve() < K)
		cout<<solve();
		cout<<endl;
		//cin>>c;
	}
	return 0;
}
