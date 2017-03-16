#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#include <algorithm>

using namespace std;

// main
string doIt( int N, vector< int> &v)
{
	int result = 0;

	int sum = 0, max = 0;
	for( vector< int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		sum += *it;
		if( *it > max) max = *it;
	}

	double avg = (( double)( sum)/N)*2;
	//if( avg < max) avg = max;

	stringstream ss;

	ss.precision(6);
	double o = 0;
	int c = 0;

	vector< double> res;

	for( vector< int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		double p = ( ( avg - ( double)( *it)) / sum) * 100;
		if( p < 0)
		{
			o += p;
			p = -1;
		}
		else
			c++;

		res.push_back(  ( ( avg - ( double)( *it)) / sum) * 100);
	}

	for( vector< double>::iterator it = res.begin(); it != res.end(); ++it)
	{
		if( *it > 0)
			*it += ( o/c);
		else
			*it = 0;

		ss << fixed << *it << " ";
	}

	return ss.str();
}

int main( const int argc, const char **argv)
{
	if( argc < 2)
		return 0;

	ifstream f( argv[ 1], ifstream::in);

	// get 'T'
	size_t TestCases, i = 1;
	f >> TestCases;

	f.ignore( 256, '\n');

	for( int N; i <= TestCases; i++)
	{
		f >> N;
		vector< int> values;
		values.resize( N);

		for( int j = 0; j < N; j++)
			f >> ( values[ j]);

		f.ignore( 256, '\n');

		cout << "Case #" << i << ": " << doIt( N, values) << endl;
	}

	f.close();
	return 0;
}
