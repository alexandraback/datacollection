
#include <iostream>

#include <vector>
#include <string>

using namespace std;

int tests;

int N, M;

int atype[100], btype[100];
long long anum[100], bnum[100];


long long check( int ai, int bi, long long num )
{
	if ( ai >= N || bi >= M )
		return num;
	long long res = num;
	if ( atype[ai] == btype[bi] )
	{
		if ( anum[ai] == bnum[bi] )
		{
			long long t = check( ai+1, bi+1, num + anum[ai] );
			if ( res < t ) res = t;
		}
		else if ( anum[ai] < bnum[bi] )
		{
			long long tnum = bnum[bi];
			long long tc = anum[ai];
			bnum[bi] -= anum[ai];
			long long t = check( ai+1, bi, num + tc );
			if ( res < t ) res = t;
			bnum[bi] = tnum;
		} else {
			long long tnum = anum[ai];
			long long tc = bnum[bi];
			anum[ai] -= bnum[bi];
			long long t = check( ai, bi+1, num + tc );
			if ( res < t ) res = t;
			anum[ai] = tnum;
		}
	} else {
		long long t = check( ai, bi+1, num );
		if ( res < t ) res = t;
		long long tz = check( ai+1, bi, num );
		if ( res < tz ) res = tz;
	}
	return res;
}


int main()
{
	cin >> tests;

	for( int curTest=0; curTest<tests; ++curTest )
	{
		cin >> N >> M;
		for( int i=0; i<N; ++i )
			cin >> anum[i] >> atype[i];
		for( int i=0; i<M; ++i )
			cin >> bnum[i] >> btype[i];

		long long res = check( 0, 0, 0 );

		cout << "Case #" << (curTest+1) << ": ";
		cout << res;
		cout << endl;
	}

	return 0;
}

