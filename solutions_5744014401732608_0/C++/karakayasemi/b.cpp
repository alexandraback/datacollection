#include <iostream>
#include <cstdio>
#include <algorithm>
#include <bitset>
#include <vector>
using namespace std;

long long int maxim[51];
int adj[51][51];
vector<int> zeros;
void determineZeros(int N,int M)
{
	for(int i=N-1;i>0;i--)
	{
		if(maxim[i]>M)
		{
			zeros.push_back(i);
		}
		else
		{
			M=M-maxim[i];
		}
	}
}
int main()
{
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	int T;
	maxim[1]=1;
	for(int i=2;i<51;i++)
	{
		for(int j=1;j<i;j++)
		{
			maxim[i]+=maxim[j];
		}
	}
	cin>>T;
	for(int i=0;i<T;i++)
	{
		for(int j=0;j<51;j++)
			for(int k=0;k<51;k++)
				adj[j][k]=0;
		int N,M;
		cin>>N>>M;
		if(M<=maxim[N])
		{
			cout<<"Case #"<<i+1<<": POSSIBLE"<<endl;
		}
		else
		{
			cout<<"Case #"<<i+1<<": IMPOSSIBLE"<<endl;
			continue;
		}
		for(int j=1;j<=N;j++)
			for(int k=j+1;k<=N;k++)
				adj[j][k]=1;
		determineZeros(N,M);
		for(int j=0;j<zeros.size();j++)
		{
			adj[zeros[j]][N]=0;
		}
		zeros.clear();
		for(int j=1;j<=N;j++)
		{
			for(int k=1;k<=N;k++)
				cout<<adj[j][k];
			cout<<endl;
		}
	}
}