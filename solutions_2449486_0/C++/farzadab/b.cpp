#include<iostream>
using namespace std;

const int MAX = 1000+1;

int a[MAX+10][MAX+10];
int mx[2][MAX+10];
int n,m;

int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	for(int tt=0; tt<t; tt++)
	{
		cin >> n >> m;
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
			{
				cin >> a[i][j];
				mx[0][i] = ( j==0 ? a[i][j] : max( mx[0][i] , a[i][j] ) );
				mx[1][j] = ( i==0 ? a[i][j] : max( mx[1][j] , a[i][j] ) );
			}
		bool f = true;
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				if( a[i][j] < mx[0][i] && a[i][j] < mx[1][j] )
					f = false;
		cout << "Case #" << tt+1 << ": ";
		if( f )
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
