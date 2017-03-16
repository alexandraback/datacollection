#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <deque>
#include <queue>
#include <utility>

using namespace std;

typedef long long ll;

int findmin( vector< double> &m, int j)
{
	int pos = 0;
	for( int i = 0; i < m.size(); i++ )
	{
		if( m[i] < m[pos] && i != j ) 
			pos = i;
	}
	return pos;
}

int main()
{
	freopen("b.in","r",stdin); freopen("output.txt","w",stdout);
	int nofcases;
	cin>>nofcases; 

	for( int nc = 1; nc <= nofcases; nc++ )
	{
		
		int n; 
		double sum = 0;
		double minimal;
		cin>>n;
		vector<double> m(n);
		for( int i = 0; i < n; i++ )
		{
			cin>>m[i];
			sum+=m[i];
		}
		cout<< "Case #" << nc <<": ";

		double q = sum * 2;
		double qq = q / n; 
		double mins = 0;

		int howmore = 0;
		for( int i = 0; i < n; i++ )
		{
			if( m[i] >= qq ) 
			{
				mins+= m[i];
				howmore++;
			}
		}

		qq = (q-mins) / ( n - howmore ) ;

		
		
		for( int i = 0; i < n; i++ )
		{
			if( qq <= m[i] ) printf("%.6lf ", 0.0 );
			else
			printf( "%.6lf ", (qq - m[i]) / sum *100);
		


		}

		cout<<endl;
	}
	
	
}