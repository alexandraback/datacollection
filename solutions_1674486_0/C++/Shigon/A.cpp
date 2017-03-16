#include <iostream>
#include <vector>
#include <queue>
#define MAX 1100
#define PB push_back

using namespace std;
typedef vector<int> VI;
typedef vector<bool> VB;

bool BFS(int start, int N, VI* G)
{
	VB vis(N+1);
	vis[start]=true;

	queue<int> Q;
	Q.push(start);
	while (!Q.empty())
	{
		int a=Q.front(); Q.pop();
		for (VI::iterator I=G[a].begin(); I!=G[a].end(); ++I)
		{
			int b=*I;
			if (vis[b]) return true;
			vis[b]=true;
			Q.push(b);
		}
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(0);

	int Testow; cin>>Testow;
	for (int test=1; test<=Testow; ++test)
	{
		VI G[MAX];

		int N; cin>>N;
		for (int i=1; i<=N; ++i)
		{
			int m; cin>>m;
			for (int j=1; j<=m; ++j)
			{
				int x; cin>>x;
				G[i].PB(x);
			}
		}

		bool jest=false;
		for (int i=1; i<=N; ++i)
		{
			if (BFS(i,N,G))
			{
				jest=true;
				break;
			}
		}

		cout<<"Case #"<<test<<": ";
		if (jest) cout<<"Yes";
		else cout<<"No";
		cout<<endl;
	}
	
	return 0;
}