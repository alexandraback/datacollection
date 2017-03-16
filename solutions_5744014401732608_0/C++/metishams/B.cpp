#include <iostream>


using namespace std;

const int MXB = 50;

int m[MXB];
int em[MXB][MXB];
int count = 0;
int M=0;

void dfs(int x, int b)
{
	m[x]=1;
	if(x==b-1)
	{
		count++;
		if(count==M)
		{
			cout << "POSSIBLE" << endl;
			for(int i=0;i<b;i++)
			{
				for(int j=0;j<b;j++)
					cout << em[i][j];
				cout << endl;
			}
		}
		m[x]=0;
		return;
	}
	for(int i=b-1;i>=0;i--)
		if(!m[i]){
			if(count<M)
				em[x][i]=1;
			dfs(i,b);
		}
	m[x]=0;
}


int main()
{
	int t;
	cin >> t;
	for(int i=0;i<t;i++){
		
		int b;
		cin >> b >> M;

		for(int j=0;j<b;j++){
			m[j]=0;
			for(int k=0;k<b;k++)
				em[j][k]=0;
		}
		count=0;
		cout << "Case #" << i+1 << ": ";
		dfs(0, b);
		if(count<M)
			cout << "IMPOSSIBLE" << endl;
	}

	return 0;
}