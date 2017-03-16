#include<iostream>
using namespace std;

int max(int a, int b)
{
	return a>b?a:b;
}
int min(int a, int b)
{
	return a<b?a:b;
}
bool solve(int n, int m)
{
	int board[n][m];
	int n_max[n];
	int m_max[m];

	for(int j=0;j<n;j++)
	{
		for(int k=0;k<m;k++)
		{
			board[j][k] = 0;
			n_max[j] = 0;
			m_max[k] = 0;
		}
	}
	for(int j=0;j<n;j++)
	{
		for(int k=0;k<m;k++)
		{
			cin >> board[j][k];
		}
	}
	for(int j=0;j<n;j++)
	{
		for(int k=0;k<m;k++)
		{
			n_max[j] = max(n_max[j], board[j][k]);
			m_max[k] = max(m_max[k], board[j][k]);
		}
	}
//	cout << endl;
//	for(int j=0;j<n;j++)
//		cout << n_max[j] << endl;
//	cout << endl;
//	for(int j=0;j<m;j++)
//		cout << m_max[j] << endl;



	for(int j=0;j<n;j++)
	{
		for(int k=0;k<m;k++)
		{
			if(board[j][k]<min(n_max[j],m_max[k]))
				return false;
		}
	}
	return true;
}
int main ()
{
	int T;
	cin >> T;
	for(int i=0;i<T;i++)
	{
		int n,m;
		cin >> n >> m;
		if(solve(n,m))
			cout << "Case #" << i+1 << ": YES" << endl; 
		else
			cout << "Case #" << i+1 << ": NO" << endl; 
	}
	return 0;
}

