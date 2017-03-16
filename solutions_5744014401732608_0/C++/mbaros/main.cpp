#include <iostream>
#include <vector>
using namespace std;

#define LL long long

int a[55][55];

int main()
{

	freopen("input.txt","r",stdin);
	freopen ( "output.txt","w",stdout );

	int w;
	cin>>w;

	for ( int v=1; v<=w; v++ ) {
		LL n,m;
		cin>>n>>m;

		for ( int i=1; i<=n; i++ )
			for ( int j=1; j<=n; j++ )
				a[i][j]=0;

		long long pw =1;
		for ( long long i=1; i<=n-2; i++ )
			pw*=2;

		cout<<"Case #"<<v<<": ";
		if ( m>pw ) {
			cout<<"IMPOSSIBLE\n";
			continue;
		}

		for ( int i=1; i<=n; i++ )
				for ( int j=i+1; j<n; j++ )
					a[i][j] = 1;
					
		if ( m==pw ) {
			cout<<"POSSIBLE\n";
			for ( int i=1; i<=n; i++ ) {
				for ( int j=1; j<=n; j++ )
					if( i!=n && j==n)
					cout<<1;
					else
						cout<<a[i][j];
				cout<<endl;
			}
			continue;
		}
		
		vector<int> vc;

		LL tmp = m;
		while ( tmp>0 ) {
			if ( tmp%2 )
				vc.push_back ( 1 );
			else
				vc.push_back ( 0 );
			tmp/=2;
		}
		for ( int i=0; i<vc.size(); i++ ) {
			if ( vc[i]==1 ) {
				a[i+2][n] = 1;
			}
		}
			cout<<"POSSIBLE\n";
			for ( int i=1; i<=n; i++ ) {
				for ( int j=1; j<=n; j++ )
					cout<<a[i][j];
				cout<<endl;
			}
	}
	return 0;
}
