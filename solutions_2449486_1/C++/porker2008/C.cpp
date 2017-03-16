#include <iostream>
using namespace std;

int data[100][100];
int maximum[100][2];

int main()
{
	int T;
	cin >> T;
	for(int c=1; c<=T; c++)
	{
		int N,M;
		cin >> N >> M;
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<M;j++)
			{
				cin >> data[i][j];
			}
		}
		for(int i=0;i<N;i++)
		{
			maximum[i][0] = 0;
			for(int j=0;j<M;j++)
				if(maximum[i][0] < data[i][j])
					maximum[i][0] = data[i][j];
		}
		for(int j=0;j<M;j++)
		{
			maximum[j][1] = 0;
			for(int i=0;i<N;i++)
				if(maximum[j][1] < data[i][j])
					maximum[j][1] = data[i][j];
		}
		bool yes = true;
		for(int i=0;yes && i<N;i++)
		{
			for(int j=0;yes && j<M;j++)
			{
				if(data[i][j] < maximum[i][0] && data[i][j] < maximum[j][1])
					yes = false;
			}
		}
		cout << "Case #" << c << ": ";
		if(yes) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}