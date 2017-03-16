
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
	ifstream cin("a.in");
	FILE* pf = fopen( "out.txt", "w");
	//ofstream cout("out.txt");
	int t;
	cin >> t;

	for ( int i = 0; i < t; i++ )
	{
		int n;
		cin >> n;
		vector< int > v;
		v.resize(n);

		int sum = 0;
		for ( int j = 0; j < n; j++ )
		{
			cin >> v[j];
			sum += v[j];
		}

		double max = sum*2/(double)n;

		int cnt = n;
		int bs = sum;
		for ( int j = 0; j < n; j++ )
		{
			if ( max <= v[j] )
				cnt--;
			else
				bs += v[j];
		}

		double avg = bs/(double)cnt;

		fprintf(pf, "Case #%d:", i+1);
		for ( int j = 0; j < n; j++ )
		{
			double r = 0.0;
			if ( max > v[j] )
				r = (avg-v[j])/(double)sum*100.0;
			fprintf( pf, " %.6f", r );
		}

		fprintf(pf, "\n");
	}

	return 0;
}