#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
using namespace std;

vector <int> judges;
int n;

double bin_search( int p )
{
	double sum = 0.0;
	for( int i = 0; i < n ; i++)
		sum += (double) judges[i];
	double lb = 0.0;
	double ub = 100.0;
	double mid = lb + ub;

	while ( ub - lb > 0.00000001 )
	{
//		cout<< mid <<endl;
		mid = lb + ub;
		mid /= 2.0;
		double target = (judges[p]) + mid*sum/100.0;
		
		double tally = mid;
		for( int i = 0; i< n ;i++ )
		{
			if( i == p )
				continue;
			tally += max( 0.0, ( target - double( judges[i] ) )*100/sum );
		}
		if( tally > 100.0 )
			ub = mid;
		else
			lb = mid;
	}
	return mid;
}
			 	
			


int main()
{
	int t;
	cin>>t;
	int ptr = 1;
	while( t-- )
	{
		cin>>n;
		judges.resize(n);
		for (int i=0;i<n;i++)
			cin>>judges[i];
		cout << "Case #"<<ptr<<":";
		ptr++;
		for( int i =0;i < n;i++)
			printf(" %.10lf", bin_search(i) );
//			cout<<" "<<bin_search( i );
		cout<<endl;
	}
	return 0;
}






